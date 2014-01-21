/*=============================================================================
#       FileName :          MyProEventAction.hh
#       Version  :          0.0.1
#       Author   :          Chi    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-06-18   12:38:02
#
#------------------------------------------------------------------------------
#       Description  :
#           This is a UserEventAction template.
#
#         generally, user only need to override BeginOfEventAction(const G4Event*) and EndOfEventAction(const G4Event*).
#         We will use method BeginEvent(const G4Event*) of class UserAnanlysisManager in BeginOfEventAction(const G4Event*) for conveniente.
#
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-06-18   12:38:02
=============================================================================*/

#ifndef MyProEventAction_H
#define MyProEventAction_H

#include "G4UserEventAction.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
                              
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


