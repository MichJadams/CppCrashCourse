#include <cstdio>
struct ClockOfTheLongNow
{
  int get_year()
  {
    return year;
  }

  void set_year(int val)
  {
    year = val;
  }

private:
  int year = 10;
};

void add_year(ClockOfTheLongNow& clock)
{
  clock.set_year(clock.get_year() + 1);
}
int main()
{

  ClockOfTheLongNow clock;
  printf("The year is %d \n", clock.get_year());
  add_year(clock);
  printf("The year is %d\n", clock.get_year());
}
