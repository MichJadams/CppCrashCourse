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
private:
  // everything under here is not inherited by the derived class!
  const char* holistic_detective = "Dirk Gently";
};

struct DerivedClass : BaseClass
{
  void announce_agency()
  {
    // holistic_detective is a private memeber of BaseClass  
    printf("%s's holistic detective agency\n", holistic_detective);
  }
};

int main()
{
  DerivedClass x;
  x.announce_agency();

}
 
