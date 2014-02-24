/*
 *  $Id: MyProSimVUserSubDetDataManager.h, 2014-02-19 16:24:17 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 19/02/2014
*/

#ifndef MyProSimVUserSubDetDataManager_H
#define MyProSimVUserSubDetDataManager_H

class TTree;
class G4Event;

cass MyProSimVUserSubDetDataManager{
/*
 *  must add a correspond event Hit class as a new data member for the classes which inherited from the abstruct class MyProSimVUserSubDetDataManager.
 *  and, override the virtual function BookBranch in order to call the TTree::Branch(branchName,className, &p_object) by using the exact class name of the event hit class
 */

public:
  MyProSimVUserSubDetDataManager();
  virtual ~MyProSimVUserSubDetDataManager();
  virtual void BookBranch(TTree*)=0;
// *
// *  TODO:
// *
  virtual void HandleThisEvent(const G4Event*);

private:


};

#endif

