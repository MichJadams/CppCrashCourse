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


int main()
{
  Bank bank{new FileLogger{}};
  bank.make_transfer(100, 200, 49.95);
  bank.make_transfer(2000, 4000, 20.00);

  bank.set_logger(new ConsoleLogger{});

  bank.make_transfer(7777, 8390, 4.4);

}
 
