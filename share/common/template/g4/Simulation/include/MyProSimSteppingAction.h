/*
 *  $Id: MyProSimSteppingAction.h, 2014-02-16 23:43:39 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 20/06/2013
*/ 
 
#ifndef MyProSimSteppingAction_H
#define MyProSimSteppingAction_H

#include "G4UserSteppingAction.hh"
#include "globals.hh"

//-------------------------------------------------------------------
class MyProSimSteppingAction : public G4UserSteppingAction{
  public:
    MyProSimSteppingAction();
    virtual ~MyProSimSteppingAction();
	  
    virtual void UserSteppingAction(const G4Step*);
    
  private:
// special. user define their special methods below

};

#endif

