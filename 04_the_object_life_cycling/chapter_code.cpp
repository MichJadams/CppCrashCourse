#include <cstdio>
#include <stdexcept>

struct Tracer
{
  Tracer(const char* name) :name {name}
  {
    printf("%s constructed.\n", name);
  }

  ~Tracer()
  {
    printf("%s destructed.\n", name);
  }

private:
  const char * const name; //so many consts
};

  static Tracer t1 { "static variable" };
thread_local Tracer t2{ "thread-local variable"};

struct Groucho
{
  void forget(int x)
  {
    if(x == 0xFACE)
      {
	throw std::logic_error{"It's not about who wrong""it's not aobut who right"};
      }
    printf("Forgot 0x%x\n", x);
  }
};

void ops() noexcept
{
  throw std::runtime_error {"Goodbye, cruel world!"};
}

int main()
{


  Groucho groucho;
  try
    {
        ops();
      groucho.forget(0xC0DE);
      groucho.forget(0xFACE);
      groucho.forget(0xC0ffee);

    }
  catch(const std::exception& e)
    {
      printf("exception caught with message: %s\n", e.what());
    }
 
}
	 
