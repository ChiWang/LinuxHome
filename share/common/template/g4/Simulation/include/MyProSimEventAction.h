/*
 *  $Id: MyProSimEventAction.h, 2014-02-16 23:12:28 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/06/2013
 *  Note:
 *    only need to override BeginOfEventAction(const G4Event*) and EndOfEventAction(const G4Event*).
*/

#ifndef MyProSimEventAction_H
#define MyProSimEventAction_H

#include "G4UserEventAction.hh"
#include "globals.hh"

//-------------------------------------------------------------------
class MyProSimEventAction : public G4UserEventAction{
// common
  public:
    MyProSimEventAction();
    virtual ~MyProSimEventAction();

    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);

    void SetDrawFlag(G4String val) {fDrawFlag = val;}

  private:
    G4String fDrawFlag;

// special. user define their special methods below

};

#endif


