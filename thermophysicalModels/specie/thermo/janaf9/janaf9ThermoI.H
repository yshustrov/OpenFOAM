/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2017 OpenFOAM Foundation
    Copyright (C) 2020 OpenCFD Ltd.
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "janaf9Thermo.H"
#include "specie.H"

// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

template<class EquationOfState>
inline Foam::janaf9Thermo<EquationOfState>::janaf9Thermo
(
    const EquationOfState& st,
    const scalar Tlow,
    const scalar Thigh,
    const scalar Tcommon,
    const scalar Tcommon2,
    const typename janaf9Thermo<EquationOfState>::coeffArray& highCpCoeffs,
    const typename janaf9Thermo<EquationOfState>::coeffArray& middleCpCoeffs,
    const typename janaf9Thermo<EquationOfState>::coeffArray& lowCpCoeffs,
    const bool convertCoeffs
)
:
    EquationOfState(st),
    Tlow_(Tlow),
    Thigh_(Thigh),
    Tcommon_(Tcommon),
    Tcommon2_(Tcommon2)
{
    if (convertCoeffs)
    {
        for (label coefLabel=0; coefLabel<nCoeffs_; coefLabel++)
        {
            highCpCoeffs_[coefLabel] = highCpCoeffs[coefLabel]*this->R();
            middleCpCoeffs_[coefLabel] = middleCpCoeffs[coefLabel]*this->R();
            lowCpCoeffs_[coefLabel] = lowCpCoeffs[coefLabel]*this->R();
        }
    }
    else
    {
        for (label coefLabel=0; coefLabel<nCoeffs_; coefLabel++)
        {
            highCpCoeffs_[coefLabel] = highCpCoeffs[coefLabel];
            middleCpCoeffs_[coefLabel] = middleCpCoeffs[coefLabel];
            lowCpCoeffs_[coefLabel] = lowCpCoeffs[coefLabel];
        }
    }
}


template<class EquationOfState>
inline const typename Foam::janaf9Thermo<EquationOfState>::coeffArray&
Foam::janaf9Thermo<EquationOfState>::coeffs
(
    const scalar T
) const
{
    if (T < Tcommon_)
    {
        return lowCpCoeffs_;
    }
    else if (T > Tcommon_ && T < Tcommon2_)
    {
        return middleCpCoeffs_;
    }
    else
    {
        return highCpCoeffs_;
    }
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class EquationOfState>
inline Foam::janaf9Thermo<EquationOfState>::janaf9Thermo
(
    const word& name,
    const janaf9Thermo& jt
)
:
    EquationOfState(name, jt),
    Tlow_(jt.Tlow_),
    Thigh_(jt.Thigh_),
    Tcommon_(jt.Tcommon_),
    Tcommon2_(jt.Tcommon2_)
    
{
    for (label coefLabel=0; coefLabel<nCoeffs_; coefLabel++)
    {
        highCpCoeffs_[coefLabel] = jt.highCpCoeffs_[coefLabel];
        middleCpCoeffs_[coefLabel] = jt.middleCpCoeffs_[coefLabel];
        lowCpCoeffs_[coefLabel] = jt.lowCpCoeffs_[coefLabel];
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class EquationOfState>
inline Foam::scalar Foam::janaf9Thermo<EquationOfState>::limit
(
    const scalar T
) const
{
    if (T < Tlow_ || T > Thigh_)
    {
        WarningInFunction
            << "attempt to use janaf9Thermo<EquationOfState>"
               " out of temperature range "
            << Tlow_ << " -> " << Thigh_ << ";  T = " << T
            << endl;

        return min(max(T, Tlow_), Thigh_);
    }
    else
    {
        return T;
    }
}


template<class EquationOfState>
inline Foam::scalar Foam::janaf9Thermo<EquationOfState>::Tlow() const
{
    return Tlow_;
}


template<class EquationOfState>
inline Foam::scalar Foam::janaf9Thermo<EquationOfState>::Thigh() const
{
    return Thigh_;
}


template<class EquationOfState>
inline Foam::scalar Foam::janaf9Thermo<EquationOfState>::Tcommon() const
{
    return Tcommon_;
}

template<class EquationOfState>
inline Foam::scalar Foam::janaf9Thermo<EquationOfState>::Tcommon2() const
{
    return Tcommon2_;
}



template<class EquationOfState>
inline const typename Foam::janaf9Thermo<EquationOfState>::coeffArray&
Foam::janaf9Thermo<EquationOfState>::highCpCoeffs() const
{
    return highCpCoeffs_;
}

template<class EquationOfState>
inline const typename Foam::janaf9Thermo<EquationOfState>::coeffArray&
Foam::janaf9Thermo<EquationOfState>::middleCpCoeffs() const
{
    return middleCpCoeffs_;
}


template<class EquationOfState>
inline const typename Foam::janaf9Thermo<EquationOfState>::coeffArray&
Foam::janaf9Thermo<EquationOfState>::lowCpCoeffs() const
{
    return lowCpCoeffs_;
}


template<class EquationOfState>
inline Foam::scalar Foam::janaf9Thermo<EquationOfState>::Cp
(
    const scalar p,
    const scalar T
) const
{
    const coeffArray& a = coeffs(T);
    return
        ((((a[6]*T + a[5])*T + a[4])*T + a[3])*T + a[2] + a[1]/T + a[0]/T/T)
      + EquationOfState::Cp(p, T);
}


template<class EquationOfState>
inline Foam::scalar Foam::janaf9Thermo<EquationOfState>::Ha
(
    const scalar p,
    const scalar T
) const
{
    const coeffArray& a = coeffs(T);
    return
    (
        ((((a[6]/5.0*T + a[5]/4.0)*T + a[4]/3.0)*T + a[3]/2.0)*T + a[2])*T
      + a[1]*log(T) - a[0]/T + a[7]
    ) + EquationOfState::H(p, T);
}


template<class EquationOfState>
inline Foam::scalar Foam::janaf9Thermo<EquationOfState>::Hs
(
    const scalar p,
    const scalar T
) const
{
    return Ha(p, T) - Hc();
}


template<class EquationOfState>
inline Foam::scalar Foam::janaf9Thermo<EquationOfState>::Hc() const
{
    const coeffArray& a = lowCpCoeffs_;
    return
    (
          ((((a[6]/5.0*Tstd + a[5]/4.0)*Tstd + a[4]/3.0)*Tstd + a[3]/2.0)*Tstd + a[2])*Tstd
      + a[1]*log(Tstd) -a[0]/Tstd + a[7]
    );
}


template<class EquationOfState>
inline Foam::scalar Foam::janaf9Thermo<EquationOfState>::S
(
    const scalar p,
    const scalar T
) const
{
    const coeffArray& a = coeffs(T);
    return
    (
        (((a[6]/4.0*T + a[5]/3.0)*T + a[4]/2.0)*T + a[3])*T + a[2]*log(T)
      - a[1]/T - a[0]/2/T/T + a[8] 
    ) + EquationOfState::S(p, T);
}


template<class EquationOfState>
inline Foam::scalar Foam::janaf9Thermo<EquationOfState>::Gstd
(
    const scalar T
) const
{
    const coeffArray& a = coeffs(T);
    return
    (
        (
            a[2]*(1 - log(T))
          - (((a[6]/20.0*T + a[5]/12.0)*T + a[4]/6.0)*T + a[3]/2.0)*T
          - a[8]
        )*T
      + a[7] - a[0]/2/T + a[1]*(log(T) + 1)
    );
}


template<class EquationOfState>
inline Foam::scalar Foam::janaf9Thermo<EquationOfState>::dCpdT
(
    const scalar p,
    const scalar T
) const
{
    const coeffArray& a = coeffs(T);
    return
        (((4*a[6]*T + 3*a[5])*T + 2*a[4])*T + a[3] -a[1]/T/T - 2*a[0]/T/T/T);
}

// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class EquationOfState>
inline void Foam::janaf9Thermo<EquationOfState>::operator+=
(
    const janaf9Thermo<EquationOfState>& jt
)
{
    scalar Y1 = this->Y();

    EquationOfState::operator+=(jt);

    if (mag(this->Y()) > SMALL)
    {
        Y1 /= this->Y();
        const scalar Y2 = jt.Y()/this->Y();

        Tlow_ = max(Tlow_, jt.Tlow_);
        Thigh_ = min(Thigh_, jt.Thigh_);

        if
        (
            janaf9Thermo<EquationOfState>::debug
         && notEqual(Tcommon_, jt.Tcommon_)
        )
        {
            FatalErrorInFunction
                << "Tcommon " << Tcommon_ << " for "
                << (this->name().size() ? this->name() : "others")
                << " != " << jt.Tcommon_ << " for "
                << (jt.name().size() ? jt.name() : "others")
                << exit(FatalError);
        }

        for
        (
            label coefLabel=0;
            coefLabel<janaf9Thermo<EquationOfState>::nCoeffs_;
            coefLabel++
        )
        {
            highCpCoeffs_[coefLabel] =
                Y1*highCpCoeffs_[coefLabel]
              + Y2*jt.highCpCoeffs_[coefLabel];
              
            middleCpCoeffs_[coefLabel] =
                Y1*middleCpCoeffs_[coefLabel]
              + Y2*jt.middleCpCoeffs_[coefLabel];

            lowCpCoeffs_[coefLabel] =
                Y1*lowCpCoeffs_[coefLabel]
              + Y2*jt.lowCpCoeffs_[coefLabel];
        }
    }
}


// * * * * * * * * * * * * * * * Friend Operators  * * * * * * * * * * * * * //

template<class EquationOfState>
inline Foam::janaf9Thermo<EquationOfState> Foam::operator+
(
    const janaf9Thermo<EquationOfState>& jt1,
    const janaf9Thermo<EquationOfState>& jt2
)
{
    EquationOfState eofs = jt1;
    eofs += jt2;

    if (mag(eofs.Y()) < SMALL)
    {
        return janaf9Thermo<EquationOfState>
        (
            eofs,
            jt1.Tlow_,
            jt1.Thigh_,
            jt1.Tcommon_,
            jt1.Tcommon2_,
            jt1.highCpCoeffs_,
            jt1.middleCpCoeffs_,
            jt1.lowCpCoeffs_
        );
    }
    else
    {
        const scalar Y1 = jt1.Y()/eofs.Y();
        const scalar Y2 = jt2.Y()/eofs.Y();

        typename janaf9Thermo<EquationOfState>::coeffArray highCpCoeffs;
        typename janaf9Thermo<EquationOfState>::coeffArray middleCpCoeffs;
        typename janaf9Thermo<EquationOfState>::coeffArray lowCpCoeffs;

        for
        (
            label coefLabel=0;
            coefLabel<janaf9Thermo<EquationOfState>::nCoeffs_;
            coefLabel++
        )
        {
            highCpCoeffs[coefLabel] =
                Y1*jt1.highCpCoeffs_[coefLabel]
              + Y2*jt2.highCpCoeffs_[coefLabel];

            middleCpCoeffs[coefLabel] =
                Y1*jt1.middleCpCoeffs_[coefLabel]
              + Y2*jt2.middleCpCoeffs_[coefLabel];

            lowCpCoeffs[coefLabel] =
                Y1*jt1.lowCpCoeffs_[coefLabel]
              + Y2*jt2.lowCpCoeffs_[coefLabel];
        }

        if
        (
            janaf9Thermo<EquationOfState>::debug
         && notEqual(jt1.Tcommon_, jt2.Tcommon_)
        )
        {
            FatalErrorInFunction
                << "Tcommon " << jt1.Tcommon_ << " for "
                << (jt1.name().size() ? jt1.name() : "others")
                << " != " << jt2.Tcommon_ << " for "
                << (jt2.name().size() ? jt2.name() : "others")
                << exit(FatalError);
        }

        return janaf9Thermo<EquationOfState>
        (
            eofs,
            max(jt1.Tlow_, jt2.Tlow_),
            min(jt1.Thigh_, jt2.Thigh_),
            jt1.Tcommon_,
            jt1.Tcommon2_,
            highCpCoeffs,
            middleCpCoeffs,
            lowCpCoeffs
        );
    }
}


template<class EquationOfState>
inline Foam::janaf9Thermo<EquationOfState> Foam::operator*
(
    const scalar s,
    const janaf9Thermo<EquationOfState>& jt
)
{
    return janaf9Thermo<EquationOfState>
    (
        s*static_cast<const EquationOfState&>(jt),
        jt.Tlow_,
        jt.Thigh_,
        jt.Tcommon_,
        jt.Tcommon2_,
        jt.highCpCoeffs_,
        jt.middleCpCoeffs_,
        jt.lowCpCoeffs_
    );
}


template<class EquationOfState>
inline Foam::janaf9Thermo<EquationOfState> Foam::operator==
(
    const janaf9Thermo<EquationOfState>& jt1,
    const janaf9Thermo<EquationOfState>& jt2
)
{
    EquationOfState eofs
    (
        static_cast<const EquationOfState&>(jt1)
     == static_cast<const EquationOfState&>(jt2)
    );

    const scalar Y1 = jt2.Y()/eofs.Y();
    const scalar Y2 = jt1.Y()/eofs.Y();

    typename janaf9Thermo<EquationOfState>::coeffArray highCpCoeffs;
    typename janaf9Thermo<EquationOfState>::coeffArray middleCpCoeffs;
    typename janaf9Thermo<EquationOfState>::coeffArray lowCpCoeffs;

    for
    (
        label coefLabel=0;
        coefLabel<janaf9Thermo<EquationOfState>::nCoeffs_;
        coefLabel++
    )
    {
        highCpCoeffs[coefLabel] =
            Y1*jt2.highCpCoeffs_[coefLabel]
          - Y2*jt1.highCpCoeffs_[coefLabel];

        middleCpCoeffs[coefLabel] =
            Y1*jt2.middleCpCoeffs_[coefLabel]
          - Y2*jt1.middleCpCoeffs_[coefLabel];

        lowCpCoeffs[coefLabel] =
            Y1*jt2.lowCpCoeffs_[coefLabel]
          - Y2*jt1.lowCpCoeffs_[coefLabel];
    }

    if
    (
        janaf9Thermo<EquationOfState>::debug
     && notEqual(jt2.Tcommon_, jt1.Tcommon_)
    )
    {
        FatalErrorInFunction
            << "Tcommon " << jt2.Tcommon_ << " for "
            << (jt2.name().size() ? jt2.name() : "others")
            << " != " << jt1.Tcommon_ << " for "
            << (jt1.name().size() ? jt1.name() : "others")
            << exit(FatalError);
    }

    return janaf9Thermo<EquationOfState>
    (
        eofs,
        max(jt2.Tlow_, jt1.Tlow_),
        min(jt2.Thigh_, jt1.Thigh_),
        jt2.Tcommon_,
        jt2.Tcommon2_,
        highCpCoeffs,
        middleCpCoeffs,
        lowCpCoeffs
    );
}

//************
// ************************************************************************* //
