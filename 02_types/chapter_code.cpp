#include <cstdio>
#include <cstddef>

struct ClockOfTheLongNow {
  void add_year(){
    year++;
  }

  bool set_year(int new_year){
    if(new_year < 2019) return false;
    year = new_year;
    return true;
  }
  
  int get_year(){
    return year;
  }
private:   
  int year;
};

class ClassyLongNow {
  int year;
public:
  void set_year(int new_year){
    if(new_year < 2019) return false;
    year = new_year;
    return true;
  }
  bool add_year(){
    year++;
  }
  int get_year(){
    return year;
  }
}

int main(){

  ClockOfTheLongNow clock;
  clock.set_year(2020);
  clock.add_year();
  printf("year %d\n", clock.get_year());
}

