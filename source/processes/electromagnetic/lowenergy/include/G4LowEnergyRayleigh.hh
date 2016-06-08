//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: G4LowEnergyRayleigh.hh,v 1.10.2.2 2001/06/28 20:19:24 gunter Exp $
// GEANT4 tag $Name:  $
//
// 
// ------------------------------------------------------------
//      GEANT 4 class header file --- Copyright CERN 1995
//      CERN Geneva Switzerland
//
//      ------------ G4LowEnergyRayleigh physics process ------
//                   by A.Forti 1999/03/02
//
// Class description:
// Low Energy Electromagnetic process, Rayleigh effect
// Further documentation available from http://www.ge.infn.it/geant4/lowE

// ************************************************************

#ifndef G4LowEnergyRayleigh_h
#define G4LowEnergyRayleigh_h 

// Base Class Headers
#include "G4VDiscreteProcess.hh"

// Contained Variables Headers
#include "G4LowEnergyUtilities.hh"
#include "G4Gamma.hh"

class G4LowEnergyRayleigh : public G4VDiscreteProcess {

private: 

  // hide assignment operator as private 
  G4LowEnergyRayleigh& operator=(const G4LowEnergyRayleigh &right);
  G4LowEnergyRayleigh(const G4LowEnergyRayleigh& );
  
public:
  
  G4LowEnergyRayleigh(const G4String& processName ="LowEnRayleigh");
  
  ~G4LowEnergyRayleigh();

  G4bool IsApplicable(const G4ParticleDefinition&);
  
  void BuildPhysicsTable(const G4ParticleDefinition& GammaType);
  
  G4double GetMeanFreePath(const G4Track& aTrack, 
			   G4double previousStepSize, 
			   G4ForceCondition* condition);

  G4VParticleChange* PostStepDoIt(const G4Track&, const G4Step& aStep);

protected:

  void BuildFormFactorTable();
  void BuildCrossSectionTable();
  void BuildMeanFreePathTable();
  void BuildZVec();

private:
  
  G4Element* SelectRandomAtom(const G4DynamicParticle*, G4Material*);

  G4SecondLevel* theCrossSectionTable; 
  G4SecondLevel* theFormFactorTable;
  G4PhysicsTable* theMeanFreePathTable;  
  G4DataVector* ZNumVec;

  G4double lowestEnergyLimit; // low  energy limit of the crosssection formula
  G4double highestEnergyLimit; // high energy limit of the crosssection formula
  G4int NumbBinTable; // number of bins in the crossection table

  G4LowEnergyUtilities util;

  G4double MeanFreePath; // actual Mean Free Path (current medium)
};

#include "G4LowEnergyRayleigh.icc"

#endif
 














