#include <cstdio>


int main(){

  unsigned long maximum = 0;

  int arr[] = {10,20,4,100,1000};

  for(int i =0; i < 5; i++){
    if(maximum < arr[i]){
      maximum = arr[i];
    }
  }
  printf("this is the max %d.\n", maximum);
}

