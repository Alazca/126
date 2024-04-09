#include <iostream>
using namespace std;

bool check_palindrome(const int& num) {
    if (num < 0) {
        return false; 
    }
    int reverse = 0;
    int temp = num; 
    while (temp != 0) {
        reverse = (reverse * 10) + temp % 10; 
        temp /= 10; 
    }
    return num == reverse;
}
