/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2013 OpenFOAM Foundation
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

Typedefs
    Foam::reactionTypes

Description
    Type definitions for reactions

\*---------------------------------------------------------------------------*/

#ifndef reactionTypes_H
#define reactionTypes_H

#include "thermoPhysicsTypes.H"
#include "Reaction.H"

#include "icoPolynomial.H"
#include "hPolynomialThermo.H"
#include "polynomialTransport.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    // sensible enthalpy based reactions
    typedef Reaction<constGasHThermoPhysics> constGasHReaction;

    typedef Reaction<gasHThermoPhysics> gasHReaction;

    typedef Reaction<constIncompressibleGasHThermoPhysics>
        constIncompressibleGasHReaction;

    typedef Reaction<incompressibleGasHThermoPhysics>
        incompressibleGasHReaction;

    typedef Reaction<icoPoly8HThermoPhysics> icoPoly8HReaction;

    typedef Reaction<constFluidHThermoPhysics> constFluidHReaction;

    typedef Reaction<constAdiabaticFluidHThermoPhysics>
        constAdiabaticFluidHReaction;

    typedef Reaction<constHThermoPhysics> constHReaction;
    
    // ---------------------------------------------------- janaf9
    
    typedef Reaction<gas9HThermoPhysics> gas9HReaction;

    typedef Reaction<incompressibleGas9HThermoPhysics>
        incompressibleGas9HReaction;

    // -------------------------------------------------- end janaf9


    // internal energy based reactions
    typedef Reaction<constGasEThermoPhysics> constGasEReaction;

    typedef Reaction<gasEThermoPhysics> gasEReaction;
    
    typedef Reaction<constIncompressibleGasEThermoPhysics>
        constIncompressibleGasEReaction;

    typedef Reaction<incompressibleGasEThermoPhysics>
        incompressibleGasEReaction;

    typedef Reaction<icoPoly8EThermoPhysics> icoPoly8EReaction;

    typedef Reaction<constFluidEThermoPhysics> constFluidEReaction;

    typedef Reaction<constAdiabaticFluidEThermoPhysics>
        constAdiabaticFluidEReaction;

    typedef Reaction<constEThermoPhysics> constEReaction;
    
    // ----------------------------------------------------------- janaf9
    
    typedef Reaction<gas9EThermoPhysics> gas9EReaction;
    
    typedef Reaction<incompressibleGas9EThermoPhysics>
        incompressibleGas9EReaction;
        
    // ---------------------------------------------------------- end janaf9
    
    // ************************************************************************* POWER *************************************************************************
    
    typedef Reaction<powerGasHThermoPhysics> powerGasHReaction;
    
    typedef Reaction<powerGas9HThermoPhysics> powerGas9HReaction;
    
    typedef Reaction<powerGasEThermoPhysics> powerGasEReaction;
    
    typedef Reaction<powerGas9EThermoPhysics> powerGas9EReaction;
    
    // ************************************************************************* END POWER *************************************************************************
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
