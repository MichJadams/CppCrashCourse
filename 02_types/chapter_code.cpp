#include <cstdio>


int main(){

  char alphabet[27];

  int letter = 97;
  for(int i = 0; i < 26; i ++){
    alphabet[i] = letter;
    letter ++;
  }
  printf("alphabeter \n %s", alphabet);

  for (int i =0; i < 26; i ++){
    alphabet[i] = i + 65;
  }
  printf("upper case \n %s", alphabet);
}

