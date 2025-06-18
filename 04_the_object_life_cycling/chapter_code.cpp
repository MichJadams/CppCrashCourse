#include <cstdio>

struct Point
{
  int x, y;

  // if you want to ensure no copying of a class! 
  Point(const Point&) = delete;
  Point& operator=(const Point&) = delete; 
  
  Point(int x, int y): x{x}, y{y} {}

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

  p2 = p1; // Now this throws an error of "use of deleted function"
  

  p1.Print();
  p2.Print();
  
}
	 
