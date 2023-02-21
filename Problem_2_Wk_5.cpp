#include <iostream>
#include <cmath>

using namespace std;

double rotation (double comps[], int comp, double angle)
{
    double output;
    switch(comp)
    {
        case(0):
        {
            output = comps[0]*cos(angle) - comps[1]*sin(angle);
            break;
        }
        case(1):
        {
            output = comps[0]*sin(angle) + comps[1]*cos(angle);
            break;
        }
        default:
        {
          output = 0;
          break;
        }
    }
    return output;
}

int main()
{
    double (*rotate)(double[], int, double) = rotation;
    char comp[2] = {'x', 'y'};
    double initial[2];
    double rotation_angle;

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter initial vector's " << comp[i] << " component: ";
        cin >> initial[i];
    }

    cout << "Enter rotation angle (rads): ";
    cin >> rotation_angle;

    cout << endl;

   for (int i = 0; i < 2; i++)
   {
       cout << "The " << comp[i] << " component of the rotated vector: ";
       cout << (*rotate)(initial, i, rotation_angle) << endl;
   }
}
