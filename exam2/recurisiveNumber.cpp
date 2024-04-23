#include <iostream>

using namespace std;

unsigned int reverseNumber(unsigned int);

unsigned int reverseNumber(unsigned int num) {
  static unsigned int revNum = 0;
  if (num == 0) {
    unsigned int result = revNum;
    revNum = 0; 
    return result;
  }
  int lastDigit = num % 10;
  revNum = (revNum * 10) + lastDigit;
  return reverseNumber(num / 10);
}

/*
 *
 *
int main() {
	unsigned int n;
	n = reverseNumber(1234);
	cout << n << endl; //expects 4321

	n = reverseNumber(5);
	cout << n << endl; //expects 5

	n = reverseNumber(13);
	cout << n << endl; //expects 31

	return 0;
}
 *
 * */
//
