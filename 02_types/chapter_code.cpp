#include <cstdio>
#include <iostream>

int main(){
  char x = 'H';
  char32_t y = U'\U0001F37A';

  const char* emoji = "other things ? \xF0\x9F\x98\x80";

  printf(" is this an emoji? %s", emoji);

  std::cout << " unicode? " << static_cast<int>(y) << std::endl;
  printf("Windows start \x41 with %c %b. \n", x,y);

  printf("this is the size difference %d %d", sizeof(x), sizeof(y));
  
  
}

