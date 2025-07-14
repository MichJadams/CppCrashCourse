#include <cstdio>
#include <utility> 
#include <stdexcept>

template<typename T, size_t length>
T& get(T(&arr)[length], size_t index)
{
  if( index >= length) throw std::out_of_range{ "out of bounds"};
  return arr[index];
}

int main()
{
  float values[]{1,2,7,8,9,10};


  printf("mean %f\n", get(values, 2));
}

  
  
