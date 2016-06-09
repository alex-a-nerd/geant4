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
// $Id: RE01PrimaryGeneratorAction.hh,v 1.1 2004/11/26 07:37:40 asaim Exp $
// GEANT4 tag $Name: geant4-07-01 $
//


#ifndef RE01PrimaryGeneratorAction_h
#define RE01PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"

class G4VPrimaryGenerator;
class G4Event;
class RE01PrimaryGeneratorMessenger;

class RE01PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    RE01PrimaryGeneratorAction();
    ~RE01PrimaryGeneratorAction();

  public:
    void GeneratePrimaries(G4Event* anEvent);

  private:
    G4VPrimaryGenerator* HEPEvt;
    G4VPrimaryGenerator* particleGun;
    RE01PrimaryGeneratorMessenger* messenger;
    G4bool useHEPEvt;

  public:
    inline void SetHEPEvtGenerator(G4bool f)
    { useHEPEvt = f; }
    inline G4bool GetHEPEvtGenerator()
    { return useHEPEvt; }
};

#endif

