#include <cstdio>

template<typename T> 
struct SimpleUniquePointer
{
  SimpleUniquePointer() = default;
  SimpleUniquePointer(T* pointer): pointer{pointer}{}
  ~simpleUniquePointer()
  {
    if(pointer) delete pointer;
  }

  // make the copy constructors not possible 
  SimpleUniquePointer(const SimpleUniquePointer&) = delete;
  SimpleUniquePointer& operator=(const SimpleUniquePointer&) = delete;

  // make the move constructor remove the pointer from
  // the original 
  SimeplUniquePointer(SimpleUniquePointer&& other) noexcept
    : pointer{other.pointer}
  {
    other.pointer = nullptr;
  }

  // make the move assignment operator
  // remove the pointer from the original
  // and return set this instance equal to the original
  // return this
  SimpleUniquePointer& operator=(const SimpleUniquePointer&& other) noexcpet
  {
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
