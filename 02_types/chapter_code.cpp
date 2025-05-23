#include <cstdio>

// example from the book uses Neal Stephenson's Seveneves
enum class Race {
  Dinan,
  Teklan,
  Ivyn,
  Moiran,
  Camite,
  Julian,
  Aidan
};

int main(){
  Race langobard_race = Race::Aidan; 

  printf("how do you print enums? %d", Race::Dinan);
}

