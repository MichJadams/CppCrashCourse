#include <cstdio>
#include <utility>

template<typename T> 
struct SimpleUniquePointer
{
  SimpleUniquePointer() = default;
  SimpleUniquePointer(T* pointer): pointer{pointer}{}
  ~SimpleUniquePointer()
  {
    if(pointer) delete pointer;
  }

  // make the copy constructors not possible 
  SimpleUniquePointer(const SimpleUniquePointer&) = delete;
  SimpleUniquePointer& operator=(const SimpleUniquePointer&) = delete;

  // make the move constructor remove the pointer from
  // the original 
  SimpleUniquePointer(SimpleUniquePointer&& other) noexcept
    : pointer{other.pointer}
  {
    other.pointer = nullptr;
  }

  // make the move assignment operator
  // remove the pointer from the original
  // and return set this instance equal to the original
  // return this
  SimpleUniquePointer& operator=(SimpleUniquePointer&& other) noexcept
  {
    // this line is really key because failure to delete this pointer
    // leaks a resource! 
    if(pointer) delete pointer;

    
    pointer = other.pointer;
    other.pointer = nullptr;
    return *this;
  }
  T* get()
  {
    return pointer;
  }
private:
  T* pointer;

};

struct Tracer
{
  Tracer(const char* name) : name{name}
  {
    printf("%s constructed \n", name);
  }
  ~Tracer()
  {
    printf("%s destucted\n", name);
  }
private:
  const char* const name;
};

void consumer( SimpleUniquePointer<Tracer> consumer_ptr)
{
  printf("(cons) consumer_ptr: 0x%p\n", consumer_ptr.get());
}

template<typename T>
T square(T value)
{
  return value * value;
}

int main()
{
  char my_char{'T'};
  auto result = square(my_char);

  // I'm suprised this compiles and prints 00!!
  printf("this is the result: %c,  %c", result, my_char); 
}

  
  
