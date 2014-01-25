/*=============================================================================
#       FileName :          MyProAnalysisManager.h
#       Version  :          0.0.1
#       Author   :          Chi    (chiwang@mail.ustc.edu.cn)
#       Time     :          2013-06-24   10:00:21
#
#------------------------------------------------------------------------------
#       Description  :
#
#
#------------------------------------------------------------------------------
#       History  :
#                                          Update:  2013-06-24   10:00:21
=============================================================================*/

#ifndef MyProAnalysisManager_H
#define MyProAnalysisManager_H

class G4Run;
class G4Event;
class G4Step;
class TFile;

class MyProAnalysisManager{
 public:
  ~MyProAnalysisManager();
  static MyProAnalysisManager* GetInstance();

  void BeginOfRun(const G4Run*);
  void EndOfRun(const G4Run*);
  void BeginOfEvent(const G4Event*);
  void EndOfEvent(const G4Event*);
  void UserStepping(const G4Step*);

 private:
  MyProAnalysisManager();
  void DrawTrajectory(const G4Event*);        //private, called in EndOfEvent(); Print trajectory

  static MyProAnalysisManager*    fInstance;
  TFile*    fRFile;
 // special data menbers

};

#endif
