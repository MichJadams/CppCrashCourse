#include <cstdio>


int main(){

  unsigned long maximum = 0;

  int arr[] = {10,20,4,100,1000};

  for(int val: arr){
    if(maximum < val){
      maximum = val;
    }
  }
  printf("this is the max %d.\n", maximum);
}

