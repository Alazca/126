#include <iostream>
using namespace std;

unsigned int padovan(const unsigned &);
bool isPalindrome(const int &);

int main() {
  // Pandovan
  unsigned int n = 7;
  unsigned int result = padovan(n);
  cout << "The " << n << "th Padovan number is: " << result << endl;
  // Palindrome checker
  int pNum1 = 12321;
  int pNum2 = 1222;
  cout << "Is " << pNum1 << " a palindrome? "
       << (isPalindrome(pNum1) ? "Yes" : "No") << endl;
  cout << "Is " << pNum2 << " a palindrome? "
       << (isPalindrome(pNum2) ? "Yes" : "No") << endl;
  return 0;
}
