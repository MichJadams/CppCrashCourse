
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

struct CyberdyneSeries800
{
  CyberdyneSeries800()
  {
    printf("I'm a friend of sarah connor.");
  }

  ~CyberdyneSeries800()
  {
    throw std::runtime_error{"I'll be back!"};
  }

};

int main()
{
try
  {
    CyberdyneSeries800 t800;
    throw std::runtime_error{"on no, we created a monster!"};
  } catch(const std::exception& e)
  {
    printf("Caught exception: %s\n", e.what());
  }


 
}
	 
