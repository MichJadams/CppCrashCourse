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
  int the_answer() const {return 43;}
  const char* member = "gold";
  virtual void final_message() const
  {
    printf("hello from the base!"); 
  }
private:
  // everything under here is not inherited by the derived class!
  const char* holistic_detective = "Dirk Gently";
};

struct DerivedClass : BaseClass
{
  void final_message() const override
  {
    printf("hello from the derived class!");
  }
};

int main()
{
  BaseClass base;
  DerivedClass derived;
  BaseClass& ref = derived;

  base.final_message();
  derived.final_message();
  ref.final_message(); 

}
 
