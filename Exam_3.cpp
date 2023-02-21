#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef vector <double> row;
typedef vector <row> matrix;

const row ti = {0.0, 0.4, 0.8, 1.2, 1.6, 2.0, 2.4, 2.8, 3.2, 3.6, 4.0};
const row y_exp = {1.99, 0.84, 0.43, 0.26, 0.150, 0.098, 
                   0.065, 0.0425, 0.0280, 0.0187, 0.0125};
const row oi = {0.0597, 0.0252, 0.0129, 0.0078, 0.0045, 0.00294, 
                0.00195, 0.001275, 0.00084, 0.000561, 0.000375};

void B(row &B, const matrix A) 
{
  double val;
  for (int i = 0; i < A.size(); i++) 
  {
    val = A[i][A.size()];
    B.push_back(val);
  }
}

void mult(const row T, row &B, double x) 
{
  for (int i = 0; i < T.size(); i++) 
  {
    B[i] -= T[i] * x;
  }
}

void pivot(matrix &A) 
{
  int n = A.size();
  double large;
  int p;
  row ex;
  for (int i = 0; i < n; i++) 
  {
    large = abs(A[i][i]);
    p = 0;
    for (int j = i + 1; j < n; j++) 
    {
      if (abs(A[j][i]) > large) 
      {
        large = abs(A[j][i]);
        p = j;
      }
    }
    if (p > i) 
    {
      ex = A[i];
      A[i] = A[p];
      A[p] = ex;
      ex.clear();
    }
  }
}

void eliminate(matrix &A) 
{
  int n = A.size();
  double x;
  for (int i = 0; i < n; i++) 
  {
    for (int j = i + 1; j < n; j++) 
    {
      x = A[j][i] / A[i][i];
      mult(A[i], A[j], x);
    }
  }
}

void backsolve(const matrix A, const row B, row &X) 
{
  int n = A.size();
  double sum;
  X[n - 1] = ( B[n - 1] ) / ( A[n - 1][n - 1] );
  for (int i = n - 2; i >= 0; i--) 
  {
    sum = 0.0;
    for (int j = i + 1; j < n; j++) 
    {
      sum += A[i][j] * X[j];
    }
    X[i] = (B[i] - sum) / ( A[i][i] );
  }
}

double S (int xp, int yp)
{
    double S = 0;
    int Nd = ti.size();
    for (int i = 0; i < Nd; i++)
    {
        S += ( (pow(ti[i], xp)) * (pow(y_exp[i], yp)) ) / ( pow(oi[i], 2) );
    }
    return S;
}

double g_x(const row a, int i)
{
  return a[0] + (a[1] * ti[i]) + (a[2] * (pow(ti[i], 2))) + (a[3] * (pow(ti[i], 3))) + (a[4] * (pow(ti[i], 4))) + (a[5] * (pow(ti[i], 5))) + (a[6] * (pow(ti[i], 6)));
}

double chisquare(const row a)
{
  double chisq = 0.0; double val;
  for (int i = 0; i < ti.size(); i++)
  {
    val = ( y_exp[i] - g_x(a, i) ) / oi[i];
    chisq += pow(val, 2.0);
  } 
  return chisq;
}

double f(double t, double y){ return (-1)*y - pow(y,2.0); }

double f_ana(double t){ return 1 / (1.5*exp(t) - 1); }

int main()
{
    cout << endl;

    // ! Runge-Kutta //
    cout << "Runge-Kutta Algorithm:: " << endl;
    row rk = {2}; double n = 310, h = 4 / n, k1, k2, k3, k4, yn = 2, yn1, y_ana, tn = 0, diff; int tnc = n / 10;
    cout << " For n = " << n << " and h = " << h << ": " << endl;
    cout << "   t  " << "       " << "y_ana" << "       "     << "y_rk" << "         "     << "diff" << endl;
    cout << "   0.0" << "       " << yn      << "           " << yn     << "             " << 0.0    << endl;
    for(int i = 1; i <= n; i++)
        {
            k1 = h * f(tn, yn);
            k2 = h * f(tn + .5*h, yn + .5*k1);
            k3 = h * f(tn + .5*h, yn + .5*k2);
            k4 = h * f(tn + h, yn + k3);
            yn1 = yn + (k1 + 2*k2 + 2*k3 + k4)/6.0;
            y_ana = f_ana(tn+h);
            tn += h;
            diff = abs(y_ana - yn1);
            if(i % tnc == 0)
            {
                rk.push_back(yn1);
                cout << "   " << tn << "     " << y_ana << "     " << yn1 << "       " << diff << endl;
            }
            yn = yn1;
        }
    cout << endl;

    // ! chi-square //
    cout << "6th Degree Polynomial Fitting:: " << endl;
    row S0 = {S(0,0), S(1,0), S(2,0), S(3,0), S(4,0),  S(5,0),  S(6,0),  S(0,1)},
        S1 = {S(1,0), S(2,0), S(3,0), S(4,0), S(5,0),  S(6,0),  S(7,0),  S(1,1)},
        S2 = {S(2,0), S(3,0), S(4,0), S(5,0), S(6,0),  S(7,0),  S(8,0),  S(2,1)},
        S3 = {S(3,0), S(4,0), S(5,0), S(6,0), S(7,0),  S(8,0),  S(9,0),  S(3,1)},
        S4 = {S(4,0), S(5,0), S(6,0), S(7,0), S(8,0),  S(9,0),  S(10,0), S(4,1)},
        S5 = {S(5,0), S(6,0), S(7,0), S(8,0), S(9,0),  S(10,0), S(11,0), S(5,1)},
        S6 = {S(6,0), S(7,0), S(8,0), S(9,0), S(10,0), S(11,0), S(12,0), S(6,1)};
    matrix A = {S0, S1, S2, S3, S4, S5, S6};
    row b, g; row a = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    // Gaussian elimination of S matrix to find a0, a1, a2, a3, a4, a5, a6 //
    pivot(A);
    eliminate(A);
    B(b, A);
    backsolve(A, b, a);
    cout << " Parameter values for 6th order quadratic fit: " << endl;
    cout << "   g(x) = (" << a[0] << ") + (" << a[1] << ")x + (" << a[2] << ")x^2 + (" 
         << a[3] << ")x^3 + (" << a[4] << ")x^4 + (" << a[5] << ")x^5 + (" << a[6] << ")x^6 " << endl;
    cout << "    Chi-square: " << chisquare(a) << endl;
    cout << "    Goodness (chi-square/Npts): " << chisquare(a) / ti.size() << endl;
    for (double i = 0; i < ti.size(); i++) { g.push_back(g_x(a,i)); }
    cout << endl;

    // ! comparison of Runge-Kutta and polynomial fitting //
    cout << "Comparison of Runge-Kutta and Polynomial Fitting:: " << endl;
            cout << "   t" << "       " << "g(x)" << "          " << "Runge-Kutta" << endl;
    for (int i = 0; i < ti.size(); i++)
    { cout << "   " << ti[i] << "      " << g[i] << "        "       << rk[i] << endl; }
    cout << endl;
}