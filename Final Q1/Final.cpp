// Runge-Kutta fourth order

// given non-linear pendulum:
// d^2 s  =  L * d^2 theta  = -g * sin(theta)
// -----        ---------
// dt^2          dt^2
// 
//   d^2 theta  =  -g  * theta --> theta = Asin(Bt + phi), B = sqrt(g/L) //! S.H.O
//   ---------    ----
//   dt^2           L
//
//  w = dtheta --> dw  =  f(theta, w, t) = -B^2 * sin(theta)
//      ------     --
//      dt         dt

// where,
// theta(t + h) = theta(t) + (k1a + 2*2k2a + 2*k3a + k4a)/6
// w(t+h) = w(t) + (k1b + 2*k2b + 2*k3b + k4b)/6

#include "q1_source.cpp"
#include <iostream>

using namespace std;

int main(void)
{
    double tmax = 25.;
    double tmin = 0.;
    double t[Npt + 1] = {0.};
    double theta0;
    double omega0 = 0.;

    cout << "theta0 = .0001*pi: " << endl;
    theta0 = .0001*PI;
    for(int i = 0; i <= Npt; i++)
    {
        t[i] = (tmax - tmin) * i/Npt + tmin;
        cout << "t = " << t[i] << " " 
             << "RK4 = " << RK4(theta0, omega0, tmin, t[i], fhar, NRK) << " "
             << RK4(theta0, omega0, tmin, t[i], fnl, NRK) << endl;
    }
    cout << endl << "theta0 = .5*pi: " << endl;
    theta0 = .5*PI;
    for(int i = 0; i <= Npt; i++)
    {
        t[i] = (tmax - tmin) * i/Npt + tmin;
        cout << "t = " << t[i] << " " 
             << "RK4 = " << RK4(theta0, omega0, tmin, t[i], fhar, NRK) << " "
             << RK4(theta0, omega0, tmin, t[i], fnl, NRK) << endl;
    }
}