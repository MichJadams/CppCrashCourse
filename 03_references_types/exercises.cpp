#include <cstdio>
#include <exception>

// Read about CVE-2001-0500
// 3-2 add a read_from and a write_to function to listing 3-6.

void write_to(char* str, char letter_to_insert,  int index)
{
  if(index < sizeof(str))
  {
    str[index] = letter_to_insert;
   
  } else
    {
      throw std::exception();
    }
}

char read_from(char* string, int index)
{
  if(index < sizeof(string)/sizeof(char))
    {
      return string[index];
    }
  else
    {
      return '\0';
    }
}

int main()
{
  char lower[] = "abc?e";
  char upper[] = "ABC?E";

  char* upper_ptr = upper;

  write_to(lower, 'd', 3);
  write_to(upper, 'D', 3);
 
  char letter_d = read_from(lower, 3);;
  char letter_D = read_from(upper, 3);;

  printf("This is string one: %s\nThis is string two %s\n", lower, upper);
}
