#include "Time.h"
#include <iomanip>
using namespace std;

Time::Time() {
  sethr(0);
  setmin(0);
}

Time::Time(int hr) {
  sethr(hr);
  setmin(0);
}

// sethr provides value input correction
Time::Time(int hr, int m) {
  sethr(hr);
  setmin(m);
}

int Time::gethr() {
  return hour;
}

int Time::getmin() {
  return min;
}

void Time::sethr(int hr) {
  if (hr < 0 || hr > 23) {
    throw std::out_of_range("Hour must be between 0 and 23 inclusive!");
  }
  this->hour = hr;
}

void Time::setmin(int m) {
  if (m < 0 || m > 59) {
    throw std::out_of_range("Minute must be between 0 and 59 inclusive!");
  }
  this->min = m;
}

ostream &operator<<(ostream &os, Time &time) {
  os << time.gethr() << ":" << setw(2) << setfill('0') << time.getmin() << endl;
  return os;
}

Time Time::operator+(Time &rhs) {
  Time temp;
  temp.hour = hour + rhs.hour;
  temp.min  = min + rhs.min;
  if (temp.min >= 60) {
    temp.hour += (temp.min / 60);
    temp.min %= 60;
  }
  return temp;
}

Time Time::operator+(int &rhs) {
  Time temp;
  temp.min = temp.min + rhs;
  if (temp.min >= 60) {
    temp.hour += (temp.min / 60);
    temp.min %= 60;
  }
  return temp;
}
