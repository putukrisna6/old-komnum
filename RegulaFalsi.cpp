#include <iostream>
#include <cmath>

#define TARGET 0.00001

using namespace std;


double func (double x) {
    return (log(x) - (1.0 / x / x) - 1.0);
}

void regula (double *x, double x0, double x1, double fx0, double fx1, int *num_of_itr) {
    *x = x0 - ((x1 - x0) / (fx1 - fx0))*fx0;
    ++(*num_of_itr);
}

void wrapper(double x0, double x1, double error, int maxItr) {
    int num_of_iter = 0;
    double x2, x3;

    regula (&x2, x0, x1, func(x0), func(x1), &num_of_iter);

    while (num_of_iter <= maxItr) {
        if (func(x0) * func(x2) < 0) x1 = x2;
        else x0 = x2;

        regula (&x3, x0, x1, func(x0), func(x1), &num_of_iter);

        if (abs(x3 - x2) < error) {
            cout << "f(x) mendekati 0 dengan nilai x = " << x3 << endl;
            cout.precision(10);
            cout << "dimana f(" << x3 << ") = " << fixed << func(x3) << endl;
            return;
        } 
        x2 = x3;
    }

    cout << "Fungsi tidak memiliki solusi\n";
    return;
}

int main() {
    int maxItr = 10;
    double x0 = 3, x1 = 10, error = TARGET;
    //mulai prediksi dengan x0 = 3 dan x1 = 10
    wrapper (x0, x1, error, maxItr);

    return 0;
}