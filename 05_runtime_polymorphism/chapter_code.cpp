#include <cstdio>
#include <stdexcept>

struct Logger
{
  virtual ~Logger() = default;
  // =0 forces log_transfer to be defined 
  virtual void log_transfer(long from, long to, double amount) = 0; 
};

struct ConsoleLogger : Logger
{
  void log_transfer(long from, long to, double amount) override
  {
    printf("[console] %ld -> %ld: %f\n", from, to, amount);

  }
};

enum class LoggerType
  {
    Console,
    File
  };


struct FileLogger : Logger
{
  void log_transfer(long from, long to, double amount) override
  {
    printf("[file] %ld -> %ld: %f\n", from, to, amount);
  }
};

struct Bank
{
  Bank(Logger* logger): logger { logger }{}

  void set_logger(Logger* new_logger)
  {
    logger = new_logger;
  }
  void make_transfer(long from, long to, double amount)
  {
    logger->log_transfer(from, to, amount);
  }
  Logger* logger; 
};

struct BaseClass
{
  ~BaseClass()
  {
    printf("called the base class deconstructor");
  }
};

struct DerivedClass : BaseClass
{
  char* leaked= nullptr;
  DerivedClass()
  {
    printf("DerivedClass() invoked \n");
    leaked = new char[100]; 
  }

  ~DerivedClass()
  {
    delete leaked;
    printf("~DerivedClass() invokved. \n");
  }

};

int main()
{
  // this code is allocating a new DerivedClass and setting a baseclss pointer to
  // point to it.
  // I have to think about this a lot. But its really interesting! 
  BaseClass* x { new DerivedClass{} };
  printf("deleted x as a baseclass*.\n");
  delete x;
  // because here the compiler is callsing the BaseClass
  // deconstructor, it does not call the derivedClass deconstructor! 
}
 
