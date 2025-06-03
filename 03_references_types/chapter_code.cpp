#include <cstdio>

int main(){

  int gettysburg{};
  int* gettysburg_address = &gettysburg;
  printf("Value at gettysburg_address: %d\n", *gettysburg_address);
  printf("Gettysburg Address: %p\n", gettysburg_address);

  *gettysburg_address = 17325e10;
  printf("value at gettysburg_address: %d\n", *gettysburg_address);
  printf("Gettysburg Address: %p\n", gettysburg_address);
}

