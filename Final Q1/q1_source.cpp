#include "q1_head.h"

double fhar(double theta, double omega, double t)
{
    return -theta;
}

double fnl(double theta, double omega, double t)
{
    return -sin(theta);
}

double RK4(double theta0, double omega0, double t0, double tf, double (*f)(double, double, double), int Niter)
{
    double h = (tf - t0) / Niter;
    double k1a,k2a,k3a,k4a;
    double k1b,k2b,k3b,k4b;

	for (int i=0;i<Niter;i++)
	{
        k1a = h*omega0;
        k1b = h*f(theta0,omega0,t0);
        k2a = h*(omega0 + k1b/2.);
        k2b = h*f(theta0 + k1a/2., omega0+k1b/2, t0+h/2.);
        k3a = h*(omega0 + k2b/2.);
        k3b = h*f(theta0+k2a/2., omega0+k2b/2., t0+h/2.);
        k4a = h*(omega0+k3b);
        k4b = h*f(theta0+k3a, omega0+k3b, t0+h);

		theta0+=k1a/6.+k2a/3.+k3a/3.+k4a/6.;
        omega0+=k1b/6.+k2b/3.+k3b/3.+k4b/6.;
	}
	return theta0;
}