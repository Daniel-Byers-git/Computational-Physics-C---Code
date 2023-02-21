#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector <double> row;
typedef vector <row> mat;

int main()
{
    double K = 237; // W / m*K
    double C = 900; // J / kg*K
    double p = 2700; // kg / m^3
    double N = K / (C*p); // equals = 9.753e-5
    // cout << N << endl;
    double const pi = 3.14159;
    double dt = .5, dx = .05;
    double t = 0, x = 0, temp;
    row t_row;
    mat temp_mat;

    t_row.push_back(0);
    for(x=dx; x<=1-dx; x+=dx)
    {
        temp = 100;
        t_row.push_back(temp);
    }
    t_row.push_back(0);
    temp_mat.push_back(t_row); // for(int i = 0; i < t_row.size(); i++){cout << temp_mat[0][i] << endl;}
    t_row.clear();


    double j1_temp;
    int t_in, x_in;
    int pos;
    for(t = dt; t <= 1000; t+=dt)
    {
        t_row.push_back(0);
        for(x = dx; x < 1-dx; x+=dx)
        {
            t_in = t/dt;
            x_in = x/dx;
            // cout << t_in << " " << x_in << endl; // ! 
            j1_temp = temp_mat[t_in-1][x_in] + ((N*(dt))/pow(dx,2))*(temp_mat[t_in-1][x_in+1] + temp_mat[t_in-1][x_in-1] - 2 * temp_mat[t_in-1][x_in]);
            // cout << j1_temp << " "; // ! 
            t_row.push_back(j1_temp);
        }
        t_row.push_back(0);
        temp_mat.push_back(t_row);
        // cout << endl << endl << endl; // ! 
        pos = t_row.size();
        t_row.clear();
    }

    ofstream outdata;
    outdata.open("tempdata.dat");
    if(outdata.is_open())
    {
        for(t = 0; t < 1000; t+=dt)
        {
            for(x = 0; x < 1; x+=dx)
            {
                t_in = t/dt;
                x_in = x/dx;
                outdata << t << "    " << x << "    " << temp_mat[t_in][x_in] << endl;
            }
        }   
        outdata.close();
    }
    else {cout << "Unable to open file" << endl;}
 

    
    return 0;
}