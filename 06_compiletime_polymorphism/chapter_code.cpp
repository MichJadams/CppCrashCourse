#include <cstdio>
#include <utility> 


template<typename T>
T mean(T* list, size_t length)
{
  // I actually like this a lot 
  static_assert(std::is_default_constructible<T>(), "type must be default constructible.");
  static_assert(std::is_arithmetic<T>(), "type must support addition and division."); 
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

  
  
