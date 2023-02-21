#include <iostream>

using namespace std;

int main() 
{
  char comp[3] = {'X', 'Y', 'Z'};
  char *pcomp = comp;

  //Trace
  double trace[9];

  double * ptrace = trace;
  
 cout << "Enter 3x3 matrix for trace calculation: " << endl;
  for (int j = 1, k = 0; j < 4; j++, k+=3)
  {
    for(int i = 0; i < 3; i++)
    {
      cout << pcomp[i] << j << " = ";
      cin >> *(ptrace+i+k);
    }
  }


  double matrixTrace = (*ptrace) * (*(ptrace+4)) * (*(ptrace+8));

  cout << "The trace of this matrix = " << matrixTrace << endl;

  cout << endl;

  //Matrix multiplication
  double rowMatrix [9]; //{1, 2, 3, 4, 5, 6, 7, 8, 9};
  double colMatrix [9]; //{9, 8, 7, 6, 5, 4, 3, 2, 1};
  double * pRmatrix = rowMatrix;
  double * pCmatrix = colMatrix;

  double ** ppmatrix[2] = {&pRmatrix, &pCmatrix};

  // cout << (*(*ppmatrix[0])+1);

  cout << "Enter two matrices to calculate their product: "  << endl;

  cout << "First matrix: " << endl;

  for (int j = 1, k = 0; j < 4; j++, k+=3)
  {
    for(int i = 0; i < 3; i++)
    {
      cout << pcomp[i] << j << " = ";
      cin >> *(pRmatrix+i+k);
    }
  }
  cout << endl;
  cout << "Second Matrix: " << endl;
    for (int j = 1, k = 0; j < 4; j++, k+=3)
  {
    for(int i = 0; i < 3; i++)
    {
      cout << pcomp[i] << j << " = ";
      cin >> *(pCmatrix+i+k);
    }
  }

  cout << endl;
  cout << "The product of these two 3x3 vectors is: " << endl;
  double product[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  int h = 0;

  for (int y = 0; y < 3; y++)
  {
    for (int f = 0; f < 3; f++)
    { 
      for (int i = 0, k = f; i < 3; i++, k+=3)
      {
        product[y][f] += (*((*ppmatrix[0])+i+h)) * (*((*ppmatrix[1])+k));
      }
      cout << product[y][f] << " ";
    }
    h += 3;
    cout << endl;
  }
}