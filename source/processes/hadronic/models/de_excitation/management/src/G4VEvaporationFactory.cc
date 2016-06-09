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
// $Id: G4VEvaporationFactory.cc,v 1.4 2005/06/04 13:26:42 jwellisc Exp $
// GEANT4 tag $Name: geant4-07-01 $
//
// Hadronic Process: Nuclear De-excitations
// by V. Lara

#include "G4VEvaporationFactory.hh"
#include "G4HadronicException.hh"

const G4VEvaporationFactory & 
G4VEvaporationFactory::operator=(const G4VEvaporationFactory & )
{
  throw G4HadronicException(__FILE__, __LINE__, "G4VEvaporationFactory::operator= meant to not be accessable.");
  return *this;
}

G4bool 
G4VEvaporationFactory::operator==(const G4VEvaporationFactory & ) const
{
  throw G4HadronicException(__FILE__, __LINE__, "G4VEvaporationFactory::operator== meant to not be accessable.");
  return false;
}

G4bool 
G4VEvaporationFactory::operator!=(const G4VEvaporationFactory & ) const
{
  throw G4HadronicException(__FILE__, __LINE__, "G4VEvaporationFactory::operator!= meant to not be accessable.");
  return true;
}




G4VEvaporationFactory::~G4VEvaporationFactory()
{
  if (_channel != 0)
    std::for_each(_channel->begin(), _channel->end(), 
		    DeleteFragment());
  delete _channel;
}


std::vector<G4VEvaporationChannel*> * 
G4VEvaporationFactory::GetChannel()
{
  // Lazy initialization
  if (_channel == 0)
    _channel = CreateChannel();
  return _channel;
}


