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

Class
    Foam::janaf9Thermo

Group
    grpSpecieThermo

Description
    janaf9 tables based thermodynamics package templated
    into the equation of state.

SourceFiles
    janaf9ThermoI.H
    janaf9Thermo.C

\*---------------------------------------------------------------------------*/

#ifndef janaf9Thermo_H
#define janaf9Thermo_H

#include "scalar.H"
#include "FixedList.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward Declarations

template<class EquationOfState> class janaf9Thermo;

template<class EquationOfState>
inline janaf9Thermo<EquationOfState> operator+
(
    const janaf9Thermo<EquationOfState>&,
    const janaf9Thermo<EquationOfState>&
);

template<class EquationOfState>
inline janaf9Thermo<EquationOfState> operator*
(
    const scalar,
    const janaf9Thermo<EquationOfState>&
);

template<class EquationOfState>
inline janaf9Thermo<EquationOfState> operator==
(
    const janaf9Thermo<EquationOfState>&,
    const janaf9Thermo<EquationOfState>&
);

template<class EquationOfState>
Ostream& operator<<
(
    Ostream&,
    const janaf9Thermo<EquationOfState>&
);


/*---------------------------------------------------------------------------*\
                           Class janaf9Thermo Declaration
\*---------------------------------------------------------------------------*/

template<class EquationOfState>
class janaf9Thermo
:
    public EquationOfState
{
public:

    // Public Data

        static constexpr int nCoeffs_ = 9;
        typedef FixedList<scalar, nCoeffs_> coeffArray;


private:

    // Private Data

        // Temperature limits of applicability of functions
        scalar Tlow_, Thigh_, Tcommon_, Tcommon2_;

        coeffArray highCpCoeffs_;
        coeffArray middleCpCoeffs_;
        coeffArray lowCpCoeffs_;


    // Private Member Functions

        //- Check that input data is valid
        void checkInputData() const;

        //- Return the coefficients corresponding to the given temperature
        inline const coeffArray& coeffs(const scalar T) const;


public:

    // Constructors

        //- Construct from components
        inline janaf9Thermo
        (
            const EquationOfState& st,
            const scalar Tlow,
            const scalar Thigh,
            const scalar Tcommon,
            const scalar Tcommon2,
            const coeffArray& highCpCoeffs,
            const coeffArray& middleCpCoeffs,
            const coeffArray& lowCpCoeffs,
            const bool convertCoeffs = false
        );

        //- Construct from dictionary
        janaf9Thermo(const dictionary& dict);

        //- Construct as a named copy
        inline janaf9Thermo(const word&, const janaf9Thermo&);


    // Member Functions

        //- Return the instantiated type name
        static word typeName()
        {
            return "janaf9<" + EquationOfState::typeName() + '>';
        }

        //- Limit the temperature to be in the range Tlow_ to Thigh_
        inline scalar limit(const scalar T) const;


        // Access

            //- Return const access to the low temperature limit
            inline scalar Tlow() const;

            //- Return const access to the high temperature limit
            inline scalar Thigh() const;

            //- Return const access to the common temperature
            inline scalar Tcommon() const;

            //- Return const access to the common temperature 2
            inline scalar Tcommon2() const;

            //- Return const access to the high temperature poly coefficients
            inline const coeffArray& highCpCoeffs() const;


            //- Return const access to the middle temperature poly coefficients
            inline const coeffArray& middleCpCoeffs() const;

            //- Return const access to the low temperature poly coefficients
            inline const coeffArray& lowCpCoeffs() const;


        // Fundamental properties

            //- Heat capacity at constant pressure [J/(kg K)]
            inline scalar Cp(const scalar p, const scalar T) const;

            //- Absolute Enthalpy [J/kg]
            inline scalar Ha(const scalar p, const scalar T) const;

            //- Sensible enthalpy [J/kg]
            inline scalar Hs(const scalar p, const scalar T) const;

            //- Chemical enthalpy [J/kg]
            inline scalar Hc() const;

            //- Entropy [J/(kg K)]
            inline scalar S(const scalar p, const scalar T) const;

            //- Gibbs free energy of the mixture in the standard state [J/kg]
            inline scalar Gstd(const scalar T) const;

            #include "HtoEthermo.H"


        // Derivative term used for Jacobian


            //- Temperature derivative of heat capacity at constant pressure
            inline scalar dCpdT(const scalar p, const scalar T) const;


        // I-O

            //- Write to Ostream
            void write(Ostream& os) const;


    // Member operators

        inline void operator+=(const janaf9Thermo&);


    // Friend operators

        friend janaf9Thermo operator+ <EquationOfState>
        (
            const janaf9Thermo&,
            const janaf9Thermo&
        );

        friend janaf9Thermo operator* <EquationOfState>
        (
            const scalar,
            const janaf9Thermo&
        );

        friend janaf9Thermo operator== <EquationOfState>
        (
            const janaf9Thermo&,
            const janaf9Thermo&
        );


    // Ostream Operator

        friend Ostream& operator<< <EquationOfState>
        (
            Ostream&,
            const janaf9Thermo&
        );
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "janaf9ThermoI.H"

#ifdef NoRepository
    #include "janaf9Thermo.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif
//********************************
// ************************************************************************* //
