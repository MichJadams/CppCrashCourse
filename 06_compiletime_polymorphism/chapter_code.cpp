#include <cstdio>

short increment_as_short(void* target)
{
  auto as_short = static_cast<short*>(target);
  *as_short = *as_short + 1;
  return *as_short;
}

int main()
{
  auto timer = reinterpret_cast<const unsigned long*>(0x1000);
  printf("Timer is %lu", *timer);

}
