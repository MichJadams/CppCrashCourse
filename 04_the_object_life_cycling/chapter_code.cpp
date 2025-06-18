#include <cstdio>
#include <utility>

struct Point
{
  int x, y;

  
  Point(const Point&) = default;
  
  Point(int x, int y): x{x}, y{y} {}

  void Print()
  {
    printf("X: %d, Y: %d\n", x, y);
  }
};

struct PointOwner
{
  PointOwner(const Point& my_point) : point{my_point}{}

public:
  Point point;

};
Point make_transpose(Point& p)
{
  
  int tmp = p.x;
  p.x = p.y;
  p.y = tmp;
  return p;
}

void ref_type(int &x)
{
  printf("lvalue reference %d\n", x);
}

void ref_type(int &&x)
{
  printf("rvalue reference %d\n", x);
}

int main()
{

  auto x = 1;
  ref_type(std::move(x)); // no clue why you would ever want to do this?
  ref_type(2);
  ref_type(x+2);
  
}
	 
