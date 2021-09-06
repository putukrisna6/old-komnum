#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

//F(x) = ln x - (1 / x^2) - 1

double function_X(double X) {
 return (log(X) - (1.0 / X / X) - 1.0);
}

double bolzano_method(double start, double end) {
 double mid_point, FXt;

 mid_point = (start + end) / 2.0;
 FXt = function_X(mid_point);

 while (abs(FXt) > 0.000000001) {
  cout << "jalan" << endl;
  if (FXt > 0) {
   end = mid_point;
  }
  else {
   start = mid_point;
  }
  mid_point = (start + end) / 2.0;
  FXt = function_X(mid_point);
 }
 cout << setprecision(10) << mid_point << ' ' << FXt << endl;
 return (FXt);
}

int main() {

 bolzano_method(3, 4);
 cout << function_X(3.03125) << endl;

 return 0;
}