#include <iostream>
#include <climits>

#define TARGET 0.00001
#define SOLUTION pair<double, double>

using namespace std;

class tabby {
private:
    //fungsi pada soal
    double func(double x) {
        return (1 - (0.6 * x)) / x;
    }
    void getAnswer(SOLUTION a) {
        cout.precision(7);
        cout << "f(x) mendekati 0 di x = " << a.first << endl;
        cout << "dengan f(" << a.first << ") = " << fixed << a.second << endl; 
    }

public:
    void tabulasi(double lower, double upper, double inc, SOLUTION nearest){
        if (abs(nearest.second) < TARGET || nearest.second == 0) {
            getAnswer(nearest);
            return;
        }
        for (double x = lower; x <= upper; x = x + inc) {
            double curr_fx = func(x);

            if (curr_fx <= 0) {
                double prev_fx = func(x - inc);

                if (abs(0 - curr_fx) < abs(0 - prev_fx)) {
                    nearest.first = x;
                    nearest.second= abs(curr_fx);
                    upper = x;
                    lower = x - inc;
                }
                else {
                    nearest.first = x - inc;
                    nearest.second= abs(prev_fx);
                    lower = x - inc;
                    upper = x;
                }
                break;
            }
        }
        tabulasi(lower, upper, inc/10, nearest);
        return;
    }
};

int main() {
    tabby SOAL_2E;
    //mulai prediksi dengan menggunakan nilai x mulai dari 1 hingga sepuluh dengan increment 1
    SOAL_2E.tabulasi(1, 10, 1, make_pair(0, INT_MAX));
    return 0;
}