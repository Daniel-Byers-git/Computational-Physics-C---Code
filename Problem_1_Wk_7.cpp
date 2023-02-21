#include <iostream>

using namespace std;

class Vect
{
    double x, y, z;
  public:
    Vect() : x(1), y(1), z(1) {}
    Vect(double i, double j, double k) : x(i), y(j), z(k) {}
    Vect operator ^ (const Vect&);
    void printVect();
};

Vect Vect::operator^(const Vect& rhs)
{
  Vect temp;
  temp.x = y*rhs.z - z*rhs.y;
  temp.y = z*rhs.x - x*rhs.z;
  temp.z = x*rhs.y - y*rhs.x;
  return temp;
}

void Vect::printVect()
{
  cout << "(" << x << ", " << y << ", " << z << ")";
}

int main()
{
  Vect * vectors = new Vect[2] { {4.5, 6.7, 2.9} , {6.4, 7.1, 5.76}};
  Vect results = vectors[0] ^ vectors[1];
  cout << "the cross product between "; vectors[0].printVect();
  cout << " and "; vectors[1].printVect(); 
  cout << " is "; results.printVect();
  cout << endl;
}