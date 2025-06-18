#include <cstdio>

struct Point
{
  int x, y;
  void Print()
  {
    printf("X: %d, Y: %d\n", x, y);
  }
};

Point make_transpose(Point p)
{
  
  int tmp = p.x;
  p.x = p.y;
  p.y = tmp;
  return p;
}

int add_one_to(int x)
{
  x++;
  return x;
}

int main()
{
  Point p1{1,3};
  auto p2 = make_transpose(p1);

  p1.Print();
  p2.Print();
  
}
	 
