#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

#define Nx 100
#define Nt 1000

int main()
{  
    // T(x = 0, t) = T(x = L, t) = 0K
    // T(x, t = 0) = 100K
    double K = 237.;  // W  / m*K
    double C = 900.;  // J  / kg*K
    double p = 2700.; // kg / m^3

    double xmin = 0., xmax = 1., dx = (xmax - xmin) / Nx;
    double tmin = 0., tmax = 2.33333, dt = (tmax - tmin) / Nt;

    double n = (dt * K) / (C * p * pow(dx,2));

    double T[Nt][Nx];

    // initial conditions
    for (int j = 0; j < Nt; j++)
    {
        T[j][0] = 0; // K 
        T[j][99] = 0; // K
    }
    for (int i = 1; i < Nt - 1; i++)
    {
        T[0][i] = 100; // K
    }
    for (int j = 1; j < Nt; j++)
    {
        for (int i = 1; i < Nx - 1; i++)
        {
            T[j][i] = T[j-1][i] + n * (T[j-1][i-1] + T[j-1][i+1] - 2 * T[j-1][i]);
        }
    }    

    // print temp values to file
    ofstream file;
    file.open("temp_val.dat");
    if(file.is_open())
    {
        cout << "open" << endl;
        for(int j = 0; j < Nt; j++)
        {
            for(int i = 0; i < Nx; i++)
            {
                file << j*dt << " " << i*dx << " " << T[j][i] << endl;
            }
        }
        file.close();
    }
    else {cout << "Failed to open 'file'" << endl;}

    return 0;
}