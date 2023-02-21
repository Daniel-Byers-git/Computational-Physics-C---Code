#include <cmath>

#define PI 3.1415926535
#define NRK 100
#define Npt 20

double fnl(double theta, double omega, double t);
double fhar(double theta, double omeg, double t);
double RK4(double theta0, double omega0, double t0, double tf, double(*f)(double, double, double), int Niter);