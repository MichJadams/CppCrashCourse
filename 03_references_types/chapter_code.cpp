#include <cstdio>

struct ClockOfTheLongNow{
  ClockOfTheLongNow(){}
  ClockOfTheLongNow(int year): year{year}{}
  int get_year() {
    return year;
  }
  void set_year(int year) {
      this->year = year;
  }
private:
  int year;
};

int main(){
  ClockOfTheLongNow clock;
  ClockOfTheLongNow* clock_ptr = &clock;
  clock_ptr->set_year(2022);
  printf("address of the clock: %p\n", clock_ptr);
  printf("Value of clock's year: %d", clock_ptr->get_year());
}

