#include <iostream>
#ifdef DEBUG
#include <assert.h>
#endif


//------------------------------------------------------------------------------
void Usage(){
  std::cout<<"\tUsage:\t"<<std::endl;
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]){
  std::cout<<"\n\tProject \"MyX\" in main function"<<std::endl;
  Usage();
  assert(argc == 2);

  return 0;
}

