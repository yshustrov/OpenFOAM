/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2017 OpenFOAM Foundation
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

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

inline Foam::CondensReactionRate::CondensReactionRate
(
    const scalar A,
    const scalar beta,
    const scalar Ta,
    const scalar B
)
:
    A_(A),
    beta_(beta),
    Ta_(Ta),
    B_(B)
{}


inline Foam::CondensReactionRate::CondensReactionRate
(
    const speciesTable&,
    const dictionary& dict
)
:
    A_(dict.get<scalar>("A")),
    beta_(dict.get<scalar>("beta")),
    Ta_(dict.get<scalar>("Ta")),
    B_(dict.get<scalar>("B"))
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

inline Foam::scalar Foam::CondensReactionRate::operator()
(
    const scalar p,
    const scalar T,
    const scalarField&
) const
{
    scalar ak = A_;
    
    if (mag(beta_) > VSMALL)
    {
        ak *= pow(T, beta_);
    }

    if (mag(Ta_) > VSMALL)
    {
        ak *= exp(-Ta_/T);
    }
    
    ak *= exp(B_*T);

    return ak;
}


inline void Foam::CondensReactionRate::write(Ostream& os) const
{
    os.writeEntry("A", A_);
    os.writeEntry("beta", beta_);
    os.writeEntry("Ta", Ta_);
    os.writeEntry("B", B_);
}


inline Foam::Ostream& Foam::operator<<
(
    Ostream& os,
    const CondensReactionRate& arr
)
{
    arr.write(os);
    return os;
}


// ************************************************************************* //
