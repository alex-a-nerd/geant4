// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: MyCalorimeterHitsCollection.hh,v 2.1 1998/07/12 02:37:13 urbi Exp $
// GEANT4 tag $Name: geant4-00 $
//

#ifndef MyCalorimeterHitsCollection_h
#define MyCalorimeterHitsCollection_h 1

#include <rw/tvordvec.h>

#include "G4VHitsCollection.hh"
#include "MyCalorimeterHit.hh"

class G4VSensitiveDetector;

class MyCalorimeterHitsCollection : public G4VHitsCollection
{
  public:
    MyCalorimeterHitsCollection();
    MyCalorimeterHitsCollection(G4String aName,G4VSensitiveDetector* theSD);
    ~MyCalorimeterHitsCollection();

    void DrawAllHits();
    void PrintAllHits();
  private:
    RWTValOrderedVector<MyCalorimeterHit> theCollection;
  public:
    inline RWTValOrderedVector<MyCalorimeterHit>& GetVector()
    { return theCollection; };
    inline int insert(MyCalorimeterHit* pHit)
    { 
      theCollection.insert(*pHit); 
      return theCollection.entries()-1;
    };
    inline void AddEdep(int i,G4double edep)
    { theCollection[i].AddEdep(edep); };
};

#endif
