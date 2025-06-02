#include <cstdio>

int main(){
  int gettysburg{10};
  printf("gettsyburg: %d\n", gettysburg);
  int *gettysburg_address = &gettysburg;
  printf("&gettysburg: %p\n", gettysburg_address);

}

