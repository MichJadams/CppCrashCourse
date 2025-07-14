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

template<typename V>
V mean(const V* values, size_t length)
{
  V result{};
  for(size_t i{}; i<length; i++)
    {
      result += values[i];
    }
  return result / length;
}

int main()
{
  const double nums_d[] {1.0, 2.0, 3.0, 4.0};
  const auto result1 = mean<double>(nums_d, 4);
  printf("double: %f\n", result1);

  const float nums_f[] {1.0f, 2.0f, 3.0f, 4.0f};
  const auto result2 = mean<float>(nums_f, 4);
  printf("float: %f\n", result2);

  const size_t nums_c[] {1,2,3,4};
  const auto result3 = mean<size_t>(nums_c, 4);
  printf("size_t: %zu\n", result3); // the book suggests using zu, I don't acutally know what
  // that does ??
}
