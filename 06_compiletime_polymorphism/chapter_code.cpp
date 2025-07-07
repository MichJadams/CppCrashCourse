#include <cstdio>
#include <stdexcept>


template<typename To, typename From>
To narrow_cast(From value)
{
  const auto converted = static_cast<To>(value);
  const auto backwards = static_cast<From>(converted);
  if( value != backwards) throw std::runtime_error{ "narrowed!"};
  return converted;
}

int main()
{
  int perfect {496};
  const auto perfect_short = narrow_cast<short>(perfect); 
  try
    {
      int cyclib {142857};
      const auto cyclib_short = narrow_cast<short>(cyclib);
    }
  catch(std::runtime_error& e)
    {
      printf("Error: %s", e.what());
    }
}
