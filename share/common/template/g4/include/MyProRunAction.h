/*=====================================================================
 *   File:   MyProRunAction.h
 *   Author: Chi WANG  (chiwang@mail.ustc.edu.cn)    18/016/2014
 *---------------------------------------------------------------------
 *   Description:
 *      user only need to override BeginOfRunAction(const G4Run*) and EndOfRunAction(const G4Run*).
 *
 *---------------------------------------------------------------------
 *   History:
 *                           Last update:  30/01/2014   14:56:02
=====================================================================*/

#ifndef MyProRunAction_H
#define MyProRunAction_H

#include "G4UserRunAction.hh"       // already has class G4Run;
#include "globals.hh"

//-------------------------------------------------------------------
class MyProRunAction : public G4UserRunAction{
// common, all need
  public:
    MyProRunAction();
    virtual ~MyProRunAction();

    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);

// user define their special methods below
  private:

};

#endif


