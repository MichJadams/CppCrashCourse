#include <cstdio>
#include <stdexcept>

struct ConsoleLogger
{
  static void log_transfer(long from, long to, double amount)
  {
    printf("%ld -> %ld: %f\n", from, to, amount);

  }
};



enum class LoggerType
  {
   Console,
   File
  };


struct FileLogger
{
  static void log_transfer(long from, long to, double amount)
  {
    printf("[cons] %ld -> %ld: %f\n", from, to, amount);
  }
};

struct Bank
{
  Bank(): type { LoggerType::Console }{}

  void set_logger(LoggerType new_type)
  {
    type = new_type;
  }
  void make_transfer(long from, long to, double amount)
  {
    switch(type)
      {
      case(LoggerType::File) :
	{
	  FileLogger::log_transfer(from, to, amount);
	  break;
      	}
      case(LoggerType::Console) :
	{
	  ConsoleLogger::log_transfer(from, to, amount);
	  break;
	}
      default:
	{
	  throw std::logic_error("Unknown logger type");
	}
			  
      };
  }
  LoggerType type; 
};


int main()
{
  Bank bank;
  bank.make_transfer(100, 200, 49.95);
  bank.make_transfer(2000, 4000, 20.00);

  bank.set_logger(LoggerType::File);

  bank.make_transfer(7777, 8390, 4.4);

}
 
