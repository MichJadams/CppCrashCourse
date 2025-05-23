#include <cstdio>


int main(){


  // debugger commands for setting values manually
  // run
  // break *line number* (do the lin that the print statement is on)
  // print &holder
  //  x/10cb &holder <-- this one prints the memory around the value that holder is pointing at
  // set {char}0x5fe9c = 0x64
  // or
  // set {char}0x5fe9c = 100
  // replace 0x5fe9c with your own memory addresses. 
  int letter = 97;
  char holder[] = {letter};
 
  printf("upper case \n %s", holder);
}

