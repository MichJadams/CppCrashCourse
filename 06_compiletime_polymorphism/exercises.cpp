#include <cstdio>
#include <concepts>
//6-4 refactor mean to accept an array rather than a pointer and length arguments. 

template<typename T>
struct Frequency
{
  T value = 0;
  int frequency = 0;
};

template<typename T>
struct Frequencies
{
  Frequencies(size_t max_length): max_length{max_length}
  {
    frequencies = new Frequency<T>[max_length];
    frequencies_index = 0;
  }
  void add_value_occurance(T value)
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
    Frequency<T>* highest_frequency = &frequencies[frequencies_index];
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
  size_t max_length = 0;  
  Frequency<T>* frequencies = nullptr;
  size_t frequencies_index = 0; 
};

template<std::integral T, size_t Length>
T mode(const T (&values)[Length])
{
  Frequencies<T> f{Length};
  for(int i{}; i < Length; i ++)
    {
      T value = values[i];
      f.add_value_occurance(value);
    }
  
  return f.find_most_frequent_value(); 
}

int main()
{
  int test[] = {1, 4, 5, 7, 3, 8, 2, 5, 5, 10, 10, 10, 10, 10, 10, 10, 10};
  int result = mode<int>(test);
  printf("result %d \n", result);
}
