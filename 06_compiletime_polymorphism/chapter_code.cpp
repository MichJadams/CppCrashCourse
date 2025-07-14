#include <cstdio>
#include <utility>
#include <type_traits>
#include <concepts>

template<typename T>
requires requires(T a, T b)
{
  {a + b} -> std::same_as<T>;
  {a / size_t{1}} -> std::same_as<T>;
}
T mean(T* list, size_t length)
{
  T result{};
  for(int i{}; i< length; i++)
    {
      result += list[i];
    }
  return result / length; 
}

int main()
{
  float values[]{1,2,3,4};
  float result = mean(values, 4);

  printf("mean %f\n", result);
}

  
  
