#include <cstdio>


// 3-4 Reimplement listing 3-11 using no explicit types (using auto)

int main()
{
  auto original = "hello";
  auto& original_ref = original;
  printf("original: %s\n", original);
  printf("Reference: %s\n", original_ref);

  printf("----------------\n");
  auto new_value = "different";
  original_ref = new_value;
  printf("Original: %s\n", original);
  printf("New Value: %s\n", new_value);
  printf("Reference: %s\n", original_ref);
}
