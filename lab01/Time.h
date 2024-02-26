/*
 * Time.h
 *
 *  Created on: Feb 6, 2024
 *      Author: andyl
 */

#ifndef TIME_H_
#define TIME_H_

#include <iostream>

using namespace std;

class Time {
private:
  int hour;
  int min;

public:
  Time();
  Time(int);       // Expects only hour int
  Time(int, int);  // Expects full time format
  void sethr(int);
  void setmin(int);
  int gethr();
  int getmin();
  friend ostream &operator<<(ostream &, Time &);  // Overload << operator
  Time operator+(Time &);                         // Overload add operator
  Time operator+(int &);
};

#endif /* TIME_H_ */
