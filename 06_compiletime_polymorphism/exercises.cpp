#include <cstdio>
#include <concepts>
//6-5 Using the example from Chater 5, make a bank template class that
// accepts a template parameter.
// use this type parameter as the type of an account rather than long.
// verify that you code still works using a Bank<long> class. 

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

template<std::integral T>
struct Account
{
  T id;
  float initial_amount;
};
  
template<typename T>
struct Bank
{
  Bank(size_t max_size) : max_size{max_size}
  {
    accounts = new Account<T>[max_size]; 
  }
  
  void add_new_account(T id,float initial_amount)
  {
    if(sizeof(accounts) < max_size)
      {
	accounts[length].id = id;
	accounts[length].initial_amount = initial_amount;
	length++;
      }
  }

private:
  Account<T>* accounts = nullptr;
  int length = 0;
  T account;
  size_t max_size;
};

int main()
{
  Bank<long> b{10};
  b.add_new_account(100, 100); 
}
