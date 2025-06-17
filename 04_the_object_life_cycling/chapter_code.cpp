#include <cstdio>

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

  
int main()
{
  const auto t2_ptr = &t2;
  printf("A\n");
  Tracer t3{"Automatic variable" };
  printf("B\n");
  const auto* t4 = new Tracer{"Dynamic variable"};
  // no delete called here, so memory from t4 is leaked!
  printf("C\n"); 
 
}
	 
