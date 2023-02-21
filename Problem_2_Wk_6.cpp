#include <iostream>
#include <cmath>
using namespace std;

class vect
{
  public:
    double x, y, z;
    vect(double xcomp, double ycomp, double zcomp) :
      x(xcomp), y(ycomp), z(zcomp) {}
};

class ppiped
{
    vect u, v, w;
    double volume;
  public:
    ppiped(vect a, vect b, vect c) :
      u(a), v(b), w(c) 
      {
        double icomp = w.x * (u.y*v.z - u.z*v.y);
        double jcomp = (-1) * w.y * (u.x*v.z - u.z*v.x);
        double kcomp = w.z * (u.x*v.y - u.y*v.x);
        volume = abs( icomp + jcomp + kcomp );
      }
    double getVolume(){return volume;}
};

int main()
{
  vect w(1.5, 3.7, 9.1), u(2.1, 3.2, 4.5), v(5.6, 7.3, 8.9);
  ppiped parallelePiped1( u, v, w);

  cout << parallelePiped1.getVolume() << endl;
}
