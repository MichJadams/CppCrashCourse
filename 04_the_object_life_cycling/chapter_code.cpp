#include <cstdio>

int add_one_to(int x)
{
  x++;
  return x;
}

int main()
{
  auto original = 1;
  auto result = add_one_to(original);
  printf("original %d; result: %d", original, result); 
}
	 
