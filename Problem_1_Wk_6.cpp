#include <iostream>
#include <cmath>

using namespace std;

class shape
{
    double radius, width, length, height;
    double area;
  public:
    shape() : radius(0), width(0), length(0), height(0), area(0) {}
    shape(double r)
      {
        radius = r;
        area = .5 * ( 12 * r / sqrt(3) ) * r ;
      }
    shape(double l, double w, double h)
      {
        length = l;
        width = w;
        height = h;
        area = 2*w*l + 2*w*h + 2*l*h;
      }
    double getArea() {return area;}
};

int main()
{
  double r, l, w, h;

  cout << "Enter inner radius of hexagon: ";
  cin >> r;
  shape hexagon(r);
  cout << "The area of this hexagon is: " << hexagon.getArea() << endl;
  cout << endl;

  cout << "Enter width of parallelepiped: ";
  cin >> w;
  cout << "Enter length of parallelepiped: ";
  cin >> l;
  cout << "Enter height of parallelepiped: ";
  cin >> h;
  shape parpiped(l, w, h);
  cout << "The area of this parallelepiped is: " << parpiped.getArea() << endl;
}
