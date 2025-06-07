#include <cstdio>
#include <cstring>

struct Element
{
  Element(const char *pfx, short operating_number) : operating_number{operating_number}
  {
    strncpy(prefix, pfx, sizeof(prefix));
    prefix[sizeof(prefix) - 1] = '\0';
  }

  Element *next{};
  char prefix[2];
  short operating_number;

  void insert_after(Element *new_elemenet)
  {
    new_elemenet->next = next;
    next = new_elemenet;
  }
};

void print_linked_list(Element *starting_element)
{
  printf("here?");
  Element *current_element = starting_element;
  printf("here %s", (*current_element).next);
  while (current_element)
  {
    printf("Element prefix: %d, elemenet operating number %d \n", current_element->prefix, current_element->operating_number);
    current_element = current_element->next;
  }
}

int main()
{
  Element one{"h", 10};
  Element two{"hi", 20};
  Element three{"no", 30};

  one.insert_after(&two);
  two.insert_after(&three);

  print_linked_list(&one);

}
