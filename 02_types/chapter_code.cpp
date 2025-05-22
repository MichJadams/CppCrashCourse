#include <cstdio>
#include <iostream>

int main(){
  char x = 'H';
  char32_t y = U'\u0041';

  // okay, so if you terminal does not support unicode, it will
  // melt it down to a decimal 
  std::cout << " unicode? " << y << '\n';
  printf("Windows start with %c %c. \n", x,y);

  // I added this myself I was having trouble actually spotting the
  // difference between the wchar_t and the char.
  printf("this is the size difference %d %d", sizeof(x), sizeof(y));
  
  
}

