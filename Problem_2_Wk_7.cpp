#include <iostream>
#include <vector>

using namespace std;

typedef vector<double> Vect; //creates "vector": really vector of doubles
typedef vector<Vect> Matrix; //Matrix is a vector of "vectors": vector of vectors of doubles

Vect operator * (const Matrix &r, const Vect &c)
{
    Vect product(r.size()); // makes vector "product" with r.size cells all equal to zero
    for (int row = 0; row < r.size(); row++) //This will navigate rows of Matrix
    {
        product[row] = 0;
        for (int column = 0; column < c.size(); column++) // Navigates comumns of matrix as well as rows of vector
        {
            product[row] += r[row][column] * c[column];
        }
    }
    return product;
}

void setValues (Vect &setVect)
{
  double value;
  cout << "Loops: " << setVect.size() << endl;
  for (int row = 0; row < setVect.size(); row++)
  {
    cout << "Enter [" << row + 1 << "] value: ";
    cin >> value;
    setVect.push_back(value);
  }
}

void setValues (Matrix &setMat, int n)
{
  Vect setVect(n);
  double value;
  for (int row = 0; row < setMat.size(); row++)
  {
    cout << "Row [" << row + 1 << "]: " << endl;
    setValues(setVect);
    setMat[row] = setVect;
  }
}

void printProduct(Vect& prodVec)
{
    for (int row = 0; row < prodVec.size(); row++)
    {
        cout << prodVec[row] << endl;
    }
}

int main()
{
    // * Main Variables
    int m, n;

    // * Matrix declaration
    cout << "Enter number of rows for Matrix: ";
    cin >> m;
    cout << "Enter number of columns for Matrix: ";
    cin >> n;
    cout << "Enter values in Matrix: " << endl;
    Matrix mainMat(m);
    setValues(mainMat, n);

    // * Vector declaration
    cout << "Enter vector values: ";
    Vect mainVect(n);
    setValues(mainVect);

    // * Multiply Marix with vector
    Vect productVector = mainMat * mainVect;
    cout << "The product of this matrix and vector is: " << endl;
    printProduct(productVector);

    return 0;
}
