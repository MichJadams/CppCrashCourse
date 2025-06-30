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
  ConsoleLogger(const char* tag): tag{tag}{};
  
  void log_transfer(long from, long to, double amount) override
  {
    printf("[%s] %ld -> %ld: %f\n",tag, from, to, amount);

  }
private:
  const char* tag;
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
  Bank(Logger& logger): logger { logger }{}

  void set_logger(Logger& new_logger)
  {
    logger = new_logger;
  }
  void make_transfer(long from, long to, double amount)
  {
    logger.log_transfer(from, to, amount);
  }
  Logger& logger; 
};

int main()
{
  ConsoleLogger logger{"special"}; 
  Bank bank{ logger };
  bank.make_transfer(100,200, 49.5); 
}
 
