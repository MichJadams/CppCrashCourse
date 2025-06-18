
#include <cstdio>
#include <stdexcept>
#include <cstdio>
#include <cstring>
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


struct SimpleString
{
  SimpleString(int max_size): max_size{max_size}, length{}
  {
    buffer = new char[max_size];
    buffer[0] = 0; 
  }

  void append_line(const char* x)
  {
    int x_len = strlen(x);
    std::strncpy(buffer + length, x, max_size - length);
    length += x_len;
    buffer[length++] = '\n';
    buffer[length] = 0; 

  }

  void print()
  {
    printf("%s", buffer);
  }

private:
  int max_size;
  int length;
  char* buffer;
};
int main()
{

  SimpleString string {115};
  string.append_line("hey!");
  string.append_line("nothing but the rain");
  string.print();
		
 
}
	 
