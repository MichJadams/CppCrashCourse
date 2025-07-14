#include <cstdio>
#include <utility>
#include <type_traits>
#include <concepts>


template<typename T>
concept Averageable = std::is_default_constructible<T>::value
    && requires(T a, T b)
    {
      // this first constraint fails when working with floats
      {a + b} -> std::same_as<T>;

      // this works just fine, because it is a looser constraint
      {a / size_t{1}} -> std::convertible_to<T>;
    };



template<Averageable T>
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
  float val1{1};
  float val2{3};
  float* values[]{&val1, &val2};
  float result = mean(values, 4);

  printf("mean %f\n", result);
}

  
  
