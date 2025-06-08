#include <cstdio>
#include <exception>

// Read about CVE-2001-0500
// 3-3 add a previous to the linked list making it a doubly linked list
// and add an insert_before to element
// traverse the list back and forth using two seperate for loops 

struct Element
{
  int data; 
  void insert_after(Element* next_element)
  {
    next_element->next = next; 
    next = next_element;
    next_element->previous = this;
   }

  void insert_before(Element* new_element)
  {
    new_element->previous = previous;
    previous = new_element;
    new_element->next = this;
    
  }
  Element* next;
  Element* previous;
  
};

void print_linked_list_forward(Element* start)
{
  Element* current_element = start;
  while(current_element)
    {
      printf("element data: %d\n", current_element->data);
      current_element = current_element->next;
    }
};

void print_linked_list_backward(Element* end)
{
  Element* current_element = end;
  while(current_element)
    {
      printf("Element data: %d\n", current_element->data);
      current_element = current_element->previous;
    }
  
}

int main()
{
  Element one{10};
  Element two{20};
  Element three{30};

  one.insert_after(&two);
  two.insert_after(&three);

  print_linked_list_forward(&one);
  print_linked_list_backward(&three);
}
