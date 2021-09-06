#include <iostream>
#include <cmath>

#define MID (lower + upper) / 2.0
#define TARGET 0.00001

using namespace std;

double funcx(double X) {
    return (log(X) - (1.0 / X / X) - 1.0);
}

void bolzano_method (double lower, double upper) {
    double  mid_point = MID, \
            fXt = funcx(mid_point);

    while (abs(fXt) > TARGET) {
        if (fXt > 0) upper = mid_point;
        else lower = mid_point;

        mid_point = MID;
        fXt = funcx(mid_point);
    }

    cout.precision(10);
    cout << "Diperoleh f(x) mendekati 0 dengan x = " << fixed << mid_point << " \ndengan f(" << fixed << mid_point << ") = " << fixed << fXt << endl; 
}

int main() {
    //mulai prediksi dengan menggunakan x1 = 3 dan x2 = 4
    bolzano_method(3, 4);
}