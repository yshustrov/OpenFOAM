/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2017 OpenFOAM Foundation
    Copyright (C) 2017 OpenCFD Ltd.
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

#include "mutThermo.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(mutThermo, 0);
    defineRunTimeSelectionTable(mutThermo, fvMesh);
    defineRunTimeSelectionTable(mutThermo, fvMeshDictPhase);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::mutThermo::mutThermo(const fvMesh& mesh, const word& phaseName)
:
    fluidThermo(mesh, phaseName),

    psi_
    (
        IOobject
        (
            phasePropertyName("thermo:psi"),
            mesh.time().timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        mesh,
        dimensionSet(0, -2, 2, 0, 0)
    ),

    mu_
    (
        IOobject
        (
            phasePropertyName("thermo:mu"),
            mesh.time().timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        mesh,
        dimensionSet(1, -1, -1, 0, 0)
    )
{}


Foam::mutThermo::mutThermo
(
    const fvMesh& mesh,
    const word& phaseName,
    const word& dictionaryName
)
:
    fluidThermo(mesh, phaseName, dictionaryName),

    psi_
    (
        IOobject
        (
            phasePropertyName("thermo:psi"),
            mesh.time().timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        mesh,
        dimensionSet(0, -2, 2, 0, 0)
    ),

    mu_
    (
        IOobject
        (
            phasePropertyName("thermo:mu"),
            mesh.time().timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        mesh,
        dimensionSet(1, -1, -1, 0, 0)
    )
{}

// * * * * * * * * * * * * * * * * Selectors * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::mutThermo> Foam::mutThermo::New
(
    const fvMesh& mesh,
    const word& phaseName
)
{
    return basicThermo::New<mutThermo>(mesh, phaseName);
}


Foam::autoPtr<Foam::mutThermo> Foam::mutThermo::New
(
    const fvMesh& mesh,
    const word& phaseName,
    const word& dictionaryName
)
{
     return basicThermo::New<mutThermo>(mesh, phaseName, dictionaryName);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::mutThermo::~mutThermo()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField> Foam::mutThermo::rho() const
{
    return p_*psi_;
}


Foam::tmp<Foam::scalarField> Foam::mutThermo::rho(const label patchi) const
{
    return p_.boundaryField()[patchi]*psi_.boundaryField()[patchi];
}


void Foam::mutThermo::correctRho
(
    const Foam::volScalarField& deltaRho,
    const dimensionedScalar& rhoMin,
    const dimensionedScalar& rhoMax
)
{}

void Foam::mutThermo::correctRho
(
    const Foam::volScalarField& deltaRho
)
{}

const Foam::volScalarField& Foam::mutThermo::psi() const
{
    return psi_;
}


Foam::tmp<Foam::volScalarField> Foam::mutThermo::mu() const
{
    return mu_;
}


Foam::tmp<Foam::scalarField> Foam::mutThermo::mu(const label patchi) const
{
    return mu_.boundaryField()[patchi];
}


// ************************************************************************* //
