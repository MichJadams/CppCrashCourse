#include <cstdio>

struct College
{
  char name[256];
};

void print_names(College *colleges, size_t n_colleges)
{
  for (int i = 0; i < n_colleges; i++)
  {
    College* college = colleges + i;
    printf("%s\n", college->name);
  };
}

int main()
{
  College best_colleges[]{"Princeton", "University", "other", "No college"};
  print_names(best_colleges, sizeof(best_colleges)/sizeof(College));
}
