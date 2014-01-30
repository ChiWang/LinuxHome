/*=====================================================================
 *   File:   MyProEventAction.h
 *   Author: Chi WANG  (chiwang@mail.ustc.edu.cn)    18/06/2014
 *---------------------------------------------------------------------
 *   Description:
 *      user only need to override BeginOfEventAction(const G4Event*) and EndOfEventAction(const G4Event*).
 *
 *---------------------------------------------------------------------
 *   History:
 *                           Last update:  30/01/2014   14:58:07
=====================================================================*/

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


