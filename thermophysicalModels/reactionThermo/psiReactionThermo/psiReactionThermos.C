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

#include "makeReactionThermo.H"

#include "psiReactionThermo.H"
#include "hePsiThermo.H"


#include "specie.H"
#include "perfectGas.H"
#include "hConstThermo.H"
#include "janafThermo.H"
#include "janaf9Thermo.H"
#include "sensibleEnthalpy.H"
#include "thermo.H"
#include "constTransport.H"
#include "sutherlandTransport.H"
#include "powerTransport.H"

#include "homogeneousMixture.H"
#include "inhomogeneousMixture.H"
#include "veryInhomogeneousMixture.H"
#include "multiComponentMixture.H"
#include "reactingMixture.H"
#include "singleStepReactingMixture.H"
#include "singleComponentMixture.H"

#include "thermoPhysicsTypes.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

// constTransport, hConstThermo

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    homogeneousMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    inhomogeneousMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    veryInhomogeneousMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);


// sutherlandTransport, hConstThermo

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    homogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    inhomogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    veryInhomogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);


// sutherlandTransport, janafThermo

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    homogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    inhomogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    veryInhomogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    homogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janaf9Thermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    inhomogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janaf9Thermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    veryInhomogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janaf9Thermo,
    perfectGas,
    specie
);

// ************************************************************************* POWER *************************************************************************

// powerTransport, hConstThermo

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    homogeneousMixture,
    powerTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    inhomogeneousMixture,
    powerTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    veryInhomogeneousMixture,
    powerTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);


// powerTransport, janafThermo

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    homogeneousMixture,
    powerTransport,
    sensibleEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    inhomogeneousMixture,
    powerTransport,
    sensibleEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    veryInhomogeneousMixture,
    powerTransport,
    sensibleEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    homogeneousMixture,
    powerTransport,
    sensibleEnthalpy,
    janaf9Thermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    inhomogeneousMixture,
    powerTransport,
    sensibleEnthalpy,
    janaf9Thermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    veryInhomogeneousMixture,
    powerTransport,
    sensibleEnthalpy,
    janaf9Thermo,
    perfectGas,
    specie
);

// ************************************************************************* END POWER *************************************************************************


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

// Multi-component thermo for sensible enthalpy

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    multiComponentMixture,
    constGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    multiComponentMixture,
    gasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    multiComponentMixture,
    gas9HThermoPhysics
);


// Multi-component thermo for internal energy

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    multiComponentMixture,
    constGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    multiComponentMixture,
    gasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    multiComponentMixture,
    gas9EThermoPhysics
);


// Reaction thermo for sensible enthalpy

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    reactingMixture,
    constGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    reactingMixture,
    gasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    reactingMixture,
    gas9HThermoPhysics
);


// Single-step reaction thermo for sensible enthalpy

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    singleStepReactingMixture,
    gasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    singleStepReactingMixture,
    gas9HThermoPhysics
);


// Reaction thermo for internal energy

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    reactingMixture,
    constGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    reactingMixture,
    gasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    reactingMixture,
    gas9EThermoPhysics
);

// ************************************************************************* POWER *************************************************************************    
   
makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    reactingMixture,
    powerGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    reactingMixture,
    powerGas9EThermoPhysics
);    

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    multiComponentMixture,
    powerGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    multiComponentMixture,
    powerGas9EThermoPhysics
);
    
// ************************************************************************* END POWER *************************************************************************

// Single-step reaction thermo for internal energy

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    singleStepReactingMixture,
    gasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    singleStepReactingMixture,
    gas9EThermoPhysics
);


// Single-component thermo for sensible enthalpy

makeThermoPhysicsReactionThermo
(
    psiReactionThermo,
    hePsiThermo,
    singleComponentMixture,
    constGasHThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    psiReactionThermo,
    hePsiThermo,
    singleComponentMixture,
    gasHThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    psiReactionThermo,
    hePsiThermo,
    singleComponentMixture,
    gas9HThermoPhysics
);


// Single-component thermo for internal energy

makeThermoPhysicsReactionThermo
(
    psiReactionThermo,
    hePsiThermo,
    singleComponentMixture,
    constGasEThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    psiReactionThermo,
    hePsiThermo,
    singleComponentMixture,
    gasEThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    psiReactionThermo,
    hePsiThermo,
    singleComponentMixture,
    gas9EThermoPhysics
);

// ************************************************************************* POWER *************************************************************************   

// Single-step reaction thermo for internal energy

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    singleStepReactingMixture,
    powerGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    singleStepReactingMixture,
    powerGas9EThermoPhysics
);

// Single-component thermo for internal energy

makeThermoPhysicsReactionThermo
(
    psiReactionThermo,
    hePsiThermo,
    singleComponentMixture,
    powerGasEThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    psiReactionThermo,
    hePsiThermo,
    singleComponentMixture,
    powerGas9EThermoPhysics
);

// ************************************************************************* END POWER *************************************************************************   

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
