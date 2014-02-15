/*
 *  $Id: MyProSteppingAction.h, 2014-02-15 23:27:32 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/06/2013
*/ 
 
#ifndef MyProSteppingAction_H
#define MyProSteppingAction_H

#include "G4UserSteppingAction.hh"
#include "globals.hh"

//-------------------------------------------------------------------
class MyProSteppingAction : public G4UserSteppingAction{
  public:
    MyProSteppingAction();
    virtual ~MyProSteppingAction();
	  
    virtual void UserSteppingAction(const G4Step*);
    
  private:
// special. user define their special methods below

};

#endif

