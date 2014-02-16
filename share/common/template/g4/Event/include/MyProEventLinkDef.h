/*
 *  $Id: MyProEventLinkDef.h, 2014-02-16 17:16:38 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 16/02/2014
*/

#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link off all namespaces;

#pragma link C++ class MyProEvtHeader+;
#pragma link C++ class MyProVEvtSubDet+;
#pragma link C++ class MyProVEvtHit+;
#pragma link C++ class MyProVRecord+;
#pragma link C++ class MyProEvtTrajectory+;

// Simulation classes
#pragma link C++ class MyProEvtMCHeader+;
#pragma link C++ class MyProVEvtMCHit+;

#endif
