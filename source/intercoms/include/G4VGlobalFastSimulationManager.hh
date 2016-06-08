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
// $Id: G4VGlobalFastSimulationManager.hh,v 1.2.4.1 2001/06/28 19:10:16 gunter Exp $
// GEANT4 tag $Name:  $
//
// 
// Abstract interface for GEANT4 Global Fast Simulation Manager.
// P. Mora de Freitas & M. Verderi 14/April/1999.
//
// G4GlobalFastSimulationManager is a "Singleton", i.e., only one instance 
// of it may exist. This is ensured by making the constructor private.
//
// G4VGlobalFastSimulationManager is an abstract interface for the
// G4GlobalFastSimulationManager one. It has the public access function
// GetConcreteInstance(), which is used to obtain a pointer to the concrete 
// G4GlobalFastSimulationManager, should it exist. After
//
// G4VGlobalFastSimulationManager* pVFSMan =  
//     G4VGlobalFastSimulationManager::GetConcreteInstance ();
//
// pVFSMan points to the real (concrete) G4GlobalFastSimulationManager if
// at least a parameterisation envelope exists, otherwise is zero.  
//
// Thus all code must be protected, for example by:
//   if (pVFSMan) 
//    G4FlavoredParallelWorld* =
//      pVFSMan -> GetFlavoredWorldForThis(p);
//

#ifndef G4VGLOBALFASTSIMULATIONMANAGER_HH
#define G4VGLOBALFASTSIMULATIONMANAGER_HH

class G4VFlavoredParallelWorld;
class G4ParticleDefinition;

class G4VGlobalFastSimulationManager {

public:
  // Returns pointer to actual Global Fast Simulation manager if
  // at least a parameterisation envelope exists. Always check value.
  static G4VGlobalFastSimulationManager* GetConcreteInstance ();

  virtual ~G4VGlobalFastSimulationManager () {}

  // VGlobalFastSimulationManager Interface for visualisation.

  virtual
  G4VFlavoredParallelWorld* GetFlavoredWorldForThis(G4ParticleDefinition*)=0;

protected:
  // Pointer to real G4GlobalFastSimulationManager.
  static G4VGlobalFastSimulationManager* fpConcreteInstance;  

};

inline 
G4VGlobalFastSimulationManager* 
G4VGlobalFastSimulationManager::GetConcreteInstance () {
  return fpConcreteInstance;
}
#endif