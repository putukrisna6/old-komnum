#include <iostream>

using namespace std;

#define TARGET 0.00001

double func(double x) {
    return (1 - (0.6 * x)) / x;
};

int main() {
    for (double i = 0; i <= 10; i = i + 1) {
        cout << func(i) << endl;
    }

    return 0;
}