/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2015 OpenFOAM Foundation
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
#include "thermoPhysicsTypes.H"
#include "solidThermoPhysicsTypes.H"

#include "chemistryReader.H"
#include "foamChemistryReader.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

// Solid chemistry readers based on sensibleEnthalpy

makeChemistryReader(constGasHThermoPhysics);
makeChemistryReader(gasHThermoPhysics);
makeChemistryReader(constIncompressibleGasHThermoPhysics);
makeChemistryReader(incompressibleGasHThermoPhysics);
makeChemistryReader(icoPoly8HThermoPhysics);
makeChemistryReader(constFluidHThermoPhysics);
makeChemistryReader(constAdiabaticFluidHThermoPhysics);
makeChemistryReader(constHThermoPhysics);


makeChemistryReaderType(foamChemistryReader, constGasHThermoPhysics);
makeChemistryReaderType(foamChemistryReader, gasHThermoPhysics);
makeChemistryReaderType
(
    foamChemistryReader,
    constIncompressibleGasHThermoPhysics
);
makeChemistryReaderType(foamChemistryReader, incompressibleGasHThermoPhysics);
makeChemistryReaderType(foamChemistryReader, icoPoly8HThermoPhysics);
makeChemistryReaderType(foamChemistryReader, constFluidHThermoPhysics);
makeChemistryReaderType(foamChemistryReader, constAdiabaticFluidHThermoPhysics);
makeChemistryReaderType(foamChemistryReader, constHThermoPhysics);

//----------------------------------------------------------------------------------- janaf9

makeChemistryReader(gas9HThermoPhysics);
makeChemistryReader(incompressibleGas9HThermoPhysics);


makeChemistryReaderType(foamChemistryReader, gas9HThermoPhysics);
makeChemistryReaderType(foamChemistryReader, incompressibleGas9HThermoPhysics);

//----------------------------------------------------------------------------------- end janaf9

// Solid chemistry readers based on sensibleInternalEnergy

makeChemistryReader(constGasEThermoPhysics);
makeChemistryReader(gasEThermoPhysics);
makeChemistryReader(constIncompressibleGasEThermoPhysics);
makeChemistryReader(incompressibleGasEThermoPhysics);
makeChemistryReader(icoPoly8EThermoPhysics);
makeChemistryReader(constFluidEThermoPhysics);
makeChemistryReader(constAdiabaticFluidEThermoPhysics);
makeChemistryReader(constEThermoPhysics);


makeChemistryReaderType(foamChemistryReader, constGasEThermoPhysics);
makeChemistryReaderType(foamChemistryReader, gasEThermoPhysics);
makeChemistryReaderType
(
    foamChemistryReader,
    constIncompressibleGasEThermoPhysics
);
makeChemistryReaderType(foamChemistryReader, incompressibleGasEThermoPhysics);
makeChemistryReaderType(foamChemistryReader, icoPoly8EThermoPhysics);
makeChemistryReaderType(foamChemistryReader, constFluidEThermoPhysics);
makeChemistryReaderType(foamChemistryReader, constAdiabaticFluidEThermoPhysics);
makeChemistryReaderType(foamChemistryReader, constEThermoPhysics);

//----------------------------------------------------------------------------------- janaf9

makeChemistryReader(gas9EThermoPhysics);
makeChemistryReader(incompressibleGas9EThermoPhysics);


makeChemistryReaderType(foamChemistryReader, gas9EThermoPhysics);
makeChemistryReaderType(foamChemistryReader, incompressibleGas9EThermoPhysics);

//----------------------------------------------------------------------------------- end janaf9

// ************************************************************************* POWER *************************************************************************  

makeChemistryReader(powerGasEThermoPhysics);
makeChemistryReader(powerGas9EThermoPhysics);

makeChemistryReaderType(foamChemistryReader, powerGasEThermoPhysics);
makeChemistryReaderType(foamChemistryReader, powerGas9EThermoPhysics);

// ************************************************************************* END POWER *************************************************************************  

// Solid chemistry readers for solids based on sensibleInternalEnergy

makeChemistryReader(hConstSolidThermoPhysics);
makeChemistryReader(hPowerSolidThermoPhysics);
makeChemistryReader(hExpKappaConstSolidThermoPhysics);

makeChemistryReaderType(foamChemistryReader, hConstSolidThermoPhysics);
makeChemistryReaderType(foamChemistryReader, hPowerSolidThermoPhysics);
makeChemistryReaderType(foamChemistryReader, hExpKappaConstSolidThermoPhysics);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
