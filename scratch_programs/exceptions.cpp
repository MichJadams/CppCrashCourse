#include <stdexcept>

void throw_exception()
{
  throw std::runtime_error("goodbye cruel world!");
}

void with_except()
{
  throw_exception();
}

void with_no_except() noexcept
{
  throw_exception();
}
int main(){

  with_except();
  with_no_except();
}
// I compiled this with
// g++ -O2 -S -masm=intel -fno-asynchronous-unwind-tables exceptions.cpp
