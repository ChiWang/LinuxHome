/*=============================================================================
#       FileName :          MyXSteppingAction.hh
#       Version  :          0.0.1
#       Author   :          Chi    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-06-20   15:41:50
#
#------------------------------------------------------------------------------
#       Description  :
#
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-06-20   15:41:50
=============================================================================*/

#ifndef MyXSteppingAction_H
#define MyXSteppingAction_H 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class MyXSteppingAction : public G4UserSteppingAction{
  public:
    MyXSteppingAction();
    virtual ~MyXSteppingAction();
	  
    virtual void UserSteppingAction(const G4Step*);
    
  private:
// special. user define their special methods below

};

#endif

