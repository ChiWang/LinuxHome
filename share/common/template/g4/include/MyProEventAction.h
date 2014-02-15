/*
 *  $Id: MyProEventAction.h, 2014-02-15 23:21:43 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/06/2013
 *  Note:
 *    only need to override BeginOfEventAction(const G4Event*) and EndOfEventAction(const G4Event*).
*/

#ifndef MyProEventAction_H
#define MyProEventAction_H

#include "G4UserEventAction.hh"
#include "globals.hh"

//-------------------------------------------------------------------
class MyProEventAction : public G4UserEventAction{
// common
  public:
    MyProEventAction();
    virtual ~MyProEventAction();

    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);

    void SetDrawFlag(G4String val) {fDrawFlag = val;}

  private:
    G4String fDrawFlag;

// special. user define their special methods below

};
#endif


