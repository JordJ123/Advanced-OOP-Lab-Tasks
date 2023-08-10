#include <iostream>
#include "intvector.h"

#define INTVECTOR_INIT_SIZE 10

int main() {

    IntVector intVector(INTVECTOR_INIT_SIZE);
    
    intVector.push(1);
    std::cout << intVector;
      
    intVector.push(2);
    std::cout << intVector;

    intVector.pop();
    std::cout << intVector;
  
    intVector.pop();
    std::cout << intVector; 

    intVector.resize(14);
    std::cout << intVector; 

    intVector.resize(2);
    std::cout << intVector; 
    
}