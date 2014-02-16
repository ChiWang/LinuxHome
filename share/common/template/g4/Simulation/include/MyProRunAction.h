/*
 *  $Id: MyProRunAction.h, 2014-02-15 23:26:52 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/06/2013
 *  Note:
 *    only need to override BeginOfRunAction(const G4Run*) and EndOfRunAction(const G4Run*).
*/

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


