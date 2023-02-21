#include "prob_1_Wk_14.h"
#include <cmath>

double f(double t, double y) { return -y * log(y); }

double y_t(double t) { return exp( (-log(2)) * exp(-t) ); }

double error (double yt, double yp) { return abs(yt - yp); }
