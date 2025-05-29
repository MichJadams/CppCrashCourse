#include <cstdio>
#include <cstddef>
#include <cstdint>

struct PodStruct {
  uint64_t a;
  char b[256];
  bool c;
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

  PodStruct items[] = {pod1, pod2, pod3, pod4};
  
  for(PodStruct item : items){
    printf("a: %d b: %s c: %d \n", item.a, item.b, item.c);
  }

}

