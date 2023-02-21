#include <iostream>
#include <cmath>
#include "prob_1_Wk_14_source.cpp"

using namespace std;

int main()
{
    double n = 16, h = 1/n, yn = .5, y_bar, yn1, tn = 0, yt;
    cout << "n" << "    " << "Yn" << "          " << "Error" << endl;
    for (int k = 1; k <= n; k++)
    {
        // ! predict
        y_bar = yn + ( h * f(tn, yn) );

        // ! correct
        yn1 = yn + ( .5 * h * ( f(tn, yn) + f(tn + h, y_bar) ));
        yt = y_t(tn+h); //analytical calculation for comparison

        yn = yn1; tn = tn+h;
        cout << k << "    " << yn << "    " << error(yt,yn) << endl;
    }
}
