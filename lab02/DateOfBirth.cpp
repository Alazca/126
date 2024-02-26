#include "DateOfBirth.h"
#include <ctime>
using namespace std;

const int MIN_YEAR = 1900;

// global variable for user age alternate for
// const Date TODAY(2, 9, 2024);
//  system time method
time_t now = time(NULL);  // using system time
tm* ptrTime = localtime(&now);
int currentYear = (ptrTime->tm_year) + 1900;

Date::Date() {
  setDate(1, 1, MIN_YEAR);
}

Date::Date(int day_, int month_, int year_) {
  setDate(month_, day_, year_);
}

void Date::setDate(const int& day_, const int& month_, const int& year_) {
  bool leapYear = false;
  if ((year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0)) {
    leapYear = true;
  }
  switch (month_) {
    case 2:
      if (leapYear && day_ >= 1 && day_ <= 29) {
        this->day = day_;
      } else if (!leapYear && day_ >= 1 && day_ <= 28) {
        this->day = day_;
      }
      break;
    case 4:
    case 6:
    case 9:
    case 11:  // April, June, September, November statements
      if (day_ >= 1 && day_ <= 30) {
        this->day = day_;
      }
      break;
    default:  // All other months
      if (day_ >= 1 && day_ <= 31) {
        this->day = day_;
      } else {
        throw std::out_of_range("Invalid Date Option");
      }
      break;
  }
  if (month_ >= 1 && month_ <= 12) {
    this->month = month_;
  } else {
    throw std::out_of_range("Invalid Date Option - MONTH CHECK");
  }
  if (year_ >= MIN_YEAR && year_ <= currentYear) {
    this->year = year_;
  } else {
    throw std::out_of_range("Invalid Date Option - YEAR CHECK");
  }
}

void Date::setDate(Date date_) {
  bool leapYear = false;
  if ((date_.getYear() % 4 == 0 && date_.getYear() % 100 != 0) ||
      (date_.getYear() % 400 == 0)) {
    leapYear = true;
  }

  switch (date_.getMonth()) {
    case 2:
      if (leapYear && date_.getDay() > 1 && date_.getDay() < 29) {
        this->day = date_.getDay();
      } else if (!leapYear && date_.getDay() > 1 && date_.getDay() < 28) {
        this->day = date_.getDay();
      }
      break;
    case 4:
    case 6:
    case 9:
    case 11:  // April, June, September, November
      if (date_.getDay() > 1 && date_.getDay() < 30) {
        this->day = date_.getDay();
      }
      break;
    default:  // All other months
      if (date_.getDay() > 1 && date_.getDay() < 31) {
        this->day = date_.getDay();
      }
      break;
  }
  if (date_.getMonth() > 1 && date_.getMonth() < 12) {
    this->month = date_.getMonth();
  }
  if (date_.getYear() > MIN_YEAR && date_.getYear() < currentYear) {
    this->year = date_.getYear();
  }
}

int Date::getDay() const {
  return day;
}

int Date::getMonth() const {
  return month;
}

int Date::getYear() const {
  return year;
}

std::ostream& operator<<(std::ostream& out, Date& date) {
  out << date.getMonth() << "/" << date.getDay() << "/" << date.getYear()
      << std::endl;
  return out;
}

DateOfBirth::DateOfBirth(int day, int month, int year)
    : Date(day, month, year) {
  if (year < MIN_YEAR || year > currentYear) {
    throw std::out_of_range("Date Of Birth <INT>: Invalid Year input!");
  }
}

DateOfBirth::DateOfBirth(Date date) : Date(date) {}

int DateOfBirth::getAge() const {
  int age = currentYear - this->getYear();
  // int age = TODAY.getYear() - this->getYear();  // for global use method
  return age;
}
