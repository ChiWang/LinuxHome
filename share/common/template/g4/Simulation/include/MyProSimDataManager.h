/*
 *  $Id: MyProSimDataManager.h, 2014-02-19 14:49:08 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 19/02/2014
*/

#ifndef MyProSimDataManager_H
#define MyProSimDataManager_H

class TTree;
class G4Run;
class MyProEvtHeader;
class MyProSimVUserSubDetDataManager;

class MyProSimDataManager{
pubic:
  static MyProSimDataManager* GetDataManager();
  ~MyProSimDataManager();
  void BookFile(const G4Run*);      // invoked from BeginOfRunAction()
  void SaveFile();                  // invoked from EndOfRunAction()
  //void PerpareNewEvent();
  MyProEvtHeader* GetEventHeader() const {return fEventHeader;}   // invoked from BeginOfEventAction() to record information of primary particle
  void FillEvent(const G4Event*);   // invoked from EndOfEventAction()
  //void FillStep();                // invoked from UserSteppingAction()

private:
  MyProSimDataManager();

private:
  static MyProSimDataManager    *fDataManager;
  TTree     *fTree;
  MyProEvtHeader    *fEventHeader;

};

#endif


