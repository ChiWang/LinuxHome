/*=============================================================================
#       FileName :          MyProRunAction.h
#       Version  :          0.0.1
#       Author   :          Chi    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-06-18   09:27:46
#
#------------------------------------------------------------------------------
#       Description  :
#           This is a UserRunAction template.
#
#         generally, user only need to override BeginOfRunAction(const G4Run*) and EndOfRunAction(const G4Run*).
#         We will use method BeginRun(const G4Run*) of class UserAnanlysisManager in BeginOfRunAction(const G4Run*) for conveniente.
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-06-18   09:27:46
=============================================================================*/

#ifndef MyProRunAction_H
#define MyProRunAction_H

#include "G4UserRunAction.hh"       // already has class G4Run;
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

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


