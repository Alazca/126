#include <iostream>
using namespace std;

bool isPalindrome(const int &num) {
  if (num == 0) {
    return true;
  }
  int temp = num;
  int reverse = reverse * 10 + temp % 10;
  temp /= 10;
  if (temp == reverse) {
    return true;
  } else {
    return false;
  }
}
