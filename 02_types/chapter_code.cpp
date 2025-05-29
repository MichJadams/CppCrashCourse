#include <cstdio>

struct John{
  bool gold = true;
  int year_of_smelting_accident{1970};

  // interesting I cannot do this
  // I have to specify the length of the char array it seems
  char key_location[] = "x-rated";
  // cannot do
  // int year(10); 

};

int main(){

  John john;
  printf("location %s", john.key_location);
  float a = {1};
  float b = {2};

  // to me this looks like a function call
  // and I kept searching in the book as to why the
  // narrowed_result function was never defined
  int narrowed_result(a/b); // silent
  int result{a/b}; // warning 
}

