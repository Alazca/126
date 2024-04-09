#include <iostream>

using namespace std;

unsigned int padovan(const unsigned &n) {
  cout << "Function call: padovan(" << n << ")" << endl;
  if (n <= 2) {
    return 1;
  }
  unsigned int result = padovan(n - 2) + padovan(n - 3);
  cout << "Return " << result << endl;
  return result;
}
