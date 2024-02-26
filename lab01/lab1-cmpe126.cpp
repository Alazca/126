#include <iostream>
#include "Flight.h"
#include "Time.h"
using namespace std;

int main() {
  Time t1;
  Time t2(3, 55);
  Time t3(5, 10);
  // Defined test cases
  // Time t4(-1);
  int minute = 10;
  cout << t1;
  cout << t2 << t3;
  // cout << t4;  Added range test
  t1 = t2 + t3;
  cout << t1;  // t1 = t3 + minute;

  t1 = t3 + minute;
  cout << t1;
  // support flight objects
  string src  = "SFO";
  string dest = "LAX";
  Flight f1(src, dest);  // Note that there should be no default value of src
                         // and dest
  f1.setDepartureTime(13, 45);  // Sets the departureTime field to 13:45
  cout << f1;  // Outputs flight information in a suitable format
  // Lab used variable t1 but changed to t4 for conciseness
  Time t4(6, 30);
  f1.setDepartureTime(t4);  // Sets the departureTime field to values
  cout << f1;
  return 0;
}
