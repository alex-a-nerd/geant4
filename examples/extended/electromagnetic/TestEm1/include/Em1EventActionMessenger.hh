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
// $Id: Em1EventActionMessenger.hh,v 1.2.4.1 2001/06/28 19:06:48 gunter Exp $
// GEANT4 tag $Name:  $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef Em1EventActionMessenger_h
#define Em1EventActionMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class Em1EventAction;
class G4UIcmdWithAString;
class G4UIcmdWithAnInteger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class Em1EventActionMessenger: public G4UImessenger
{
  public:
    Em1EventActionMessenger(Em1EventAction*);
   ~Em1EventActionMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
  private:
    Em1EventAction* eventAction;   
    G4UIcmdWithAString* DrawCmd;
    G4UIcmdWithAnInteger* PrintCmd;    
};

#endif