#include <stdio.h>
#include <iostream>

int main(){ 
  printf("Hello World from C/C++\n"); 
  std::cout << "Hello World " << "from C++\n"; 

  int x=20; 
  double y=3; 
  std::cout << x  
        <<"/" 
        <<y 
        <<"=" 
        <<x/y 
        <<std::endl; 
  return 0; 
}
