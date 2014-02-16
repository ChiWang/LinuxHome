/*
 *  $Id: MyProSimRunAction.h, 2014-02-16 23:22:29 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/06/2013
 *  Note:
 *    only need to override BeginOfRunAction(const G4Run*) and EndOfRunAction(const G4Run*).
*/

#ifndef MyProSimRunAction_H
#define MyProSimRunAction_H

#include "G4UserRunAction.hh"       // already has class G4Run;
#include "globals.hh"

//-------------------------------------------------------------------
class MyProSimRunAction : public G4UserRunAction{
// common, all need
  public:
    MyProSimRunAction();
    virtual ~MyProSimRunAction();

    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);

// user define their special methods below
  private:

};

#endif


