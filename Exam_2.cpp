#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<double> vec;
typedef vector<vec> mat;

vec operator - (const vec & A, const vec & B)
{
  vec tempVec(3);
  tempVec[0] = A[0] - B[0];
  tempVec[1] = A[1] - B[1];
  tempVec[2] = A[2] - B[2];
  return tempVec;
}

vec operator * (const mat & R, const vec & V)
{
  vec prodVec(V.size());
  // cout << R.size();
  for (int row = 0; row < R.size(); row++ )
  {
    prodVec[row] = 0;
    for (int col = 0; col < V.size(); col++)
    {
      prodVec[row] += R[row][col] * V[col];
    }
  }
  return prodVec;
}

void setValues(vec & setVect)
{
  const int size = setVect.size();
  //cout << setVect.size() << " ";
  double value;
  for (int row = 0; row < size; row++)
  {
    cout << "Enter [" << row+1 << "] value: ";
    cin >> value;
    setVect[row] = value;
    // setVect.push_back(value);
  }
}

double mag(const vec & M)
{
  double magn = 0;
  for (int i = 0; i < M.size(); i++)
  {
    magn += pow(M[i], 2);
  }
  magn = sqrt(magn);
  return magn;
}

mat ortho (const mat & R)
{
  mat temp;
  for(int i = 3; i < R.size(); i++)
  {
    for(int j = 0; j < R.size(); j++)
    {
      temp[i][j] = R[j][i];
    }
  }
  return temp;
}

// mat operator * (const mat & R, const mat & T)
// {
//   mat ortho;
//   for(int row = 0; row < R.size();)
// }

int main()
{
  const double theta = 3.1415 / 6;
  //cout << cos(theta) << " " << sqrt(3) / 2;

  vec r1(3), r2(3);
  cout << "Set values for r1: " << endl;
  setValues(r1);
  cout << endl;
  cout << "Set values for r2: " << endl;
  setValues(r2);
  cout << endl;
  //cout << "Here?";

  //Ry by row
  vec ry1(3); ry1[0] = cos(theta);      ry1[1] = 0;  ry1[2] = sin(theta);
  vec ry2(3); ry2[0] = 0;               ry2[1] = 1;  ry2[2] = 0;
  vec ry3(3); ry3[0] = (-1)*sin(theta); ry3[1] = 0;  ry3[2] = cos(theta);
  mat Ry(3); Ry[0] = ry1; Ry[1] = ry2; Ry[2] = ry3;
  // cout << Ry[1][1] << endl;

  // now calculate rotated vector
  vec r = r2 - r1; //cout << r[0];
  vec r_prime = Ry * r;
  cout << "r_prime components: " << endl;
  cout << "   r_prime = {" << r_prime[0] << ", " << r_prime[1]
       << ", " << r_prime[2] << "} " << endl;
  cout << endl;

  // verify mag is unchanged:
  cout << "Magnitude of r: " << mag(r) << endl;
  cout << "Magnitude of r_prime: " << mag(r_prime) << endl;


  //orthogonal?
  //a b c       a d g
  //d e f  -->  b e f
  //g h i       c f i
  mat I;
  //mat RyT(3) = ortho(Ry);
  //cout << Ry[0][1] << " " << RyT[1][0];

}