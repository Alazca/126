#include <iostream>
using namespace std;

bool palindromeHelper(const string& str, int start, int end) {
    if (start >= end) {
        return true; 
    }
    if (str[start] != str[end]) {
        return false; 
    }
    return palindromeHelper(str, start + 1, end - 1); 
}

bool check_palindrome(const int& num) {
    string str = to_string(num);
    return palindromeHelper(str, 0, str.length() - 1);
}
