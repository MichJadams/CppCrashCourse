#include <cstdio>

struct Point
{
  int x, y;
  
  // the addition of this single line below completely
  // changes the behavior of the make_transpose function
  // below!!!!
  Point(int x, int y): x{x}, y{y} {}

  // and then adding this means that it goes back to
  // behaving like a fundamental type or a POD!
  Point(const Point& other)
  {
    x = 10;
    y = 100;
    printf("----\n");
    //    other.Print();
    printf("X: %d, Y: %d\n", other.x, other.y);
       printf("----\n");
  }
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
  Point p2{5,6};

  p2 = p1; // another way to copy things....
  

  p1.Print();
  p2.Print();
  
}
	 
