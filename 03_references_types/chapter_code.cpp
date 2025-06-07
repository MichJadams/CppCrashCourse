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

struct ClockOfTheLongNow
{
  int get_year() const
  {
    return year;
  }
  void add_year()
  {
    year++;
  }
      
  int year{10};
};
struct Avout {
  const char* name = "Erasmas";
  ClockOfTheLongNow apert;
};
void does_not_compile(const Avout& avout)
{
  avout.apert.add_year();
}
  
int main()
{

  ClockOfTheLongNow clock{};
  int year = clock.get_year();

  printf("The year: %d", year);

}
