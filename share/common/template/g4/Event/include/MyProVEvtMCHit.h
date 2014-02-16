/*
 *  $Id: MyProVEvtMCHit.h, 2014-02-16 23:58:20 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 16/02/2014
*/

#ifndef MyProVEvtMCHit_H
#define MyProVEvtMCHit_H

class TVector3;

//-------------------------------------------------------------------
class MyProVEvtMCHit{
public:
  MyProVEvtMCHit();
  virtual ~MyProVEvtMCHit();

protected:
  TVector3  *fPosition;
  int fEnergy;

};

#endif
