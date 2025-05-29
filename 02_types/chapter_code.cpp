#include <cstdio>
#include <cstddef>
#include <cstdint>

struct PodStruct {
  uint64_t a;
  char b[256];
  bool c;
};

struct Taxonomist{
  Taxonomist(){
    printf("No argument\n");
  }
  Taxonomist(char c){
    printf("char %c\n", c);
  }
  Taxonomist(int i){
    printf("int :d\n", i);
  }
  Taxonomist(float f){
    printf("float %f\n", f);
  }
};

int main(){

  // Initializing a fundamental Type to Zero

  int a = 0;
  int b{};
  int c = {};
  int d;

  // Initializing a fundamental type to an arbitrary value

  int e = 42;
  int f{42};
  int g = {42};
  int h(42); // this one is crazy 


  // Initializing PODS

  PodStruct pod1{};
  PodStruct pod2 = {};
  PodStruct pod3 {42, "hello"};
  PodStruct pod4{42, "hello", true};

  // Initializing Arrays

  int arr1[]{1,2,3};
  int arr2[5]{};
  int arr3[5]{1,2,3};
  int arr4[5];

  // Fully Featured Classes

  Taxonomist t1;
  Taxonomist t2{'c'};
  Taxonomist t3{65537};
  Taxonomist t4{6.02f};
  Taxonomist t5('g');
  Taxonomist t6 = {'l'};
  Taxonomist t7{};
  //Taxonomist t8();
  
}

