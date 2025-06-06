#include <cstdio>

struct College{
  char name[256];
};

void print_name(College* college){
  printf("%s College\n", (*college).name);
}

int main(){
  College best_colleges[]{"Princeton", "University", "other", "No college"};
  print_name(best_colleges + 2);
}

