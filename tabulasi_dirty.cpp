#include <iostream>
#include <climits>

#define TARGET 0.00001
#define SOLUTION pair<long double, long double>

using namespace std;

int times = 0;

long double func(long double x) {
    return -2.1 + 6.21*x - 3.9*x*x + 0.667*x*x*x;
    // return -0.874*x*x + 1.75*x + 2.627;
    // return (1 - (0.6 * x)) / x;
};

void printX(long double x) {
    cout.precision(7);
    cout << "f(x) mendekati 0 di x = " << x << endl;
    cout << "dengan f(" << x << ") = " << fixed << func(x) << endl; 
}

void tabulasi(long double lower, long double upper, long double inc, SOLUTION nearest){
    cout << endl;
    cout << "lower: " << lower << " upper: " << upper << endl;
    cout << "inc: " << inc << " nearest result: " << nearest.second << endl;

    // if (times == 7) return;

    if (abs(nearest.second) < TARGET || nearest.second == 0) {
        printX(nearest.first);
        return;
    }

    for (long double x = lower; x <= upper; x = x + inc) {
        long double curr_fx = func(x);
        // cout << "x: " << x << " fx: " << curr_fx << endl;
        // if (abs(0 - curr_fx) < nearest.second) {
        //     nearest.first = x;
        //     nearest.second= abs(curr_fx);
        // }

        if (curr_fx <= 0) {
            cout << "fx is: " << curr_fx << endl;
            double prev_fx = func(x - inc);
            if (abs(0 - curr_fx) < abs(0 - prev_fx)) {
                cout << "neg is nearer\n";
                nearest.first = x;
                nearest.second= abs(curr_fx);
                upper = x;
                lower = x - inc;
            }
            else {
                cout << "pos is nearer\n";
                nearest.first = x - inc;
                nearest.second= abs(prev_fx);
                lower = nearest.first;
                upper = x;
            }
            break;
        }
    }
    
    times++;
    tabulasi(lower, upper, inc/10, nearest);
    return;
}


int main() {
    tabulasi(1, 10, 1, make_pair(0, INT_MAX));
    return 0;
}