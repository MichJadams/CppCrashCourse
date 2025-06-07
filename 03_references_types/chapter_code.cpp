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

  const char* get_prefix() const
  {
    return prefix;
  }

  void insert_after(Element *new_elemenet)
  {
    new_elemenet->next = next;
    next = new_elemenet;
  }
};

void print_linked_list(Element *starting_element)
{
    Element *current_element = starting_element;
    while (current_element)
  {
    printf("Element prefix: %s, elemenet operating number %d \n", current_element->get_prefix(), current_element->operating_number);
    current_element = current_element->next;
  }
}

int main()
{

  Element one{"i", 10};
  print_linked_list(&one);

}
