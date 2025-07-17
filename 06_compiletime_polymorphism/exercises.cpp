#include <cstdio>

// the mode of a series of vlaues ithe value that appears most commonly.
// implement a mode function using the following signature: int mode(constint* values, size_t length)
// if you encounter  an error condition, return zero;

struct Frequency
{
  int value = 0;
  int frequency = 0;
};

struct Frequencies
{
  Frequencies(size_t max_length): max_length{max_length}
  {
    frequencies = new Frequency[max_length];
    frequencies_index = 0;
  }
  void add_value_occurance(int value)
  {
    bool not_found = true; 
    for(int i{}; i< frequencies_index; i++)
      {
	if(frequencies[i].value == value)
	  {
	    not_found = false;
	    frequencies[i].frequency += 1;
	  }
      }
    
    if(not_found)
      {
	frequencies[frequencies_index].value = value;
	frequencies[frequencies_index].frequency = 1; 
	frequencies_index += 1; 
      }
  }
  
  int find_most_frequent_value()
  {
    Frequency* highest_frequency = &frequencies[frequencies_index];
    for(int i{}; i< frequencies_index; i++)
      {
	if(frequencies[i].frequency > highest_frequency->frequency)
	  {
	    highest_frequency = &frequencies[i];
	  }
      }

    return highest_frequency->value; 
  }
  
private:
  size_t max_length; 
  Frequency* frequencies;
  size_t frequencies_index; 
};

int mode(const int* values, size_t length)
{
  Frequencies f{length};
  for(int i{}; i < length; i ++)
    {
      int value = values[i];
	f.add_value_occurance(value);
    }
  
  return f.find_most_frequent_value(); 
}
int main()
{
  int test[] = {1, 4, 5, 7, 3, 8, 2, 5, 5, 10, 10, 10, 10, 10, 10, 10, 10};
  int result = mode(test, sizeof(test)/sizeof(int));
  printf("result %d \n", result);
}
