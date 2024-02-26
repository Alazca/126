#ifndef DATEOFBIRTH_HPP_
#define DATEOFBIRTH_HPP_
#include <iostream>

class Date {
private:
  int day;
  int month;
  int year;

public:
  Date();
  Date(int, int, int);
  void setDate(const int&, const int&, const int&);
  void setDate(Date);
  int getDay() const;
  int getMonth() const;
  int getYear() const;
  friend std::ostream& operator<<(std::ostream&, Date&);
};

class DateOfBirth : public Date {
public:
  DateOfBirth(int, int, int);
  DateOfBirth(Date);
  int getAge() const;
};

#endif
