#include <iostream>
using namespace std;

unsigned int padovan(const unsigned &);
bool check_palindrome(const int &);

int main() {
  // Pandovan
  unsigned int n = 7;
  unsigned int result = padovan(n);
  cout << "The " << n << "th Padovan number is: " << result << endl;
  // Palindrome checker
  cout << "\nPALINDROME CHECKER!\n" << endl;
  int pNum1 = 12321;
  int pNum2 = 1331;
  int pNum3 = 1246;
  cout << "Is " << pNum1 << " a palindrome? "
       << (check_palindrome(pNum1) ? "Yes" : "No") << endl;
  cout << "Is " << pNum2 << " a palindrome? "
       << (check_palindrome(pNum2) ? "Yes" : "No") << endl;
  cout << "Is " << pNum3 << " a palindrome? "
       << (check_palindrome(pNum3) ? "Yes" : "No") << endl;
  return 0;
}
