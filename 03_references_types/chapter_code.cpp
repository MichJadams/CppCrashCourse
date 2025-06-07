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
  int original = 100;
  int& original_ref = original;
  printf("original: %d\n", original);
  printf("Reference: %d\n", original_ref);

  int new_value = 200;
  original_ref = new_value;
  
  // This is the weird part. Original gets the changes that were
  // propagated back up by chaning the reference to original.
  // maybe kinda like unions? at least in my head.
  printf("Original: %d\n", original);
  
  printf("New Value: %d\n", new_value);
  printf("Reference: %d\n" original_ref); 

}
