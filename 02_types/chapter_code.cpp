#include <cstdio>
#include <cstddef>

union Variant {
  char string[10];
  int integer;
  double floating_point;
  std::byte bytes[10]; 
};

int main(){

  Variant v;
  v.integer = 42;
  printf("as bytes: %s\n", v.bytes);

  printf("The Answer: %d\n", v.integer);

  v.floating_point = 2.7182818284;
  printf("Euler number e: %f\n", v.floating_point);
  
  printf("as bytes: %b\n", v.bytes);
  printf("A dumpster fire: %d\n", v.string);
}

