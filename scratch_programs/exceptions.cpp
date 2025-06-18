#include <cstdio>

int main(){

  int a = 10;
  int* b = nullptr; // cool
  int& ref = nullptr; // uncool 

    
}

// I compiled this with
// g++ -O2 -S -masm=intel -fno-asynchronous-unwind-tables exceptions.cpp
