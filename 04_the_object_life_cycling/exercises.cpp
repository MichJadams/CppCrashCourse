#include <chrono>
#include <cstring>
#include <cstdio>
#include <utility>

struct Timer
{
  Timer(const char* name): name{name}
  {
    start = std::chrono::steady_clock::now();
  }

  Timer(const Timer& t): start{t.start}, name{t.name}
  {
    printf("copy constructor\n");

  }

  Timer& operator=(const Timer& t)
  {
    printf("copy assignment\n");

    start = t.start;
    name = t.name;
    return *this;
  }

  Timer(Timer&& t) noexcept : start{t.start}, name{t.name}
  {
    printf("move constructor\n");
    t.moved_from = true;

  }

  Timer& operator=(Timer&& t) noexcept
    {
      printf("move assignment\n");
      if(this == &t) return *this;
      start = t.start;
      name = t.name;
      t.moved_from = true;
      
      return *this; 
    }
  ~Timer()
  {
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    auto age_in_seconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    if(moved_from) return; 
    printf("Timer %s -> Lifespan: %d\n", name, age_in_seconds);
  };

private:
  std::chrono::steady_clock::time_point start;
  bool moved_from{false};
  const char* name;
};

int function_that_needs_timing(Timer timer)
{
  int i = 0;
  while(i < 1000)
    {
      int result = i * i *i;
      i ++;
    }
  return 0;
}

static Timer static_clock{"static"};

int main()
{
  Timer clock{"one"};

  function_that_needs_timing(std::move(clock));
  

}

