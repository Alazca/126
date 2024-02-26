#ifndef PASSENGER_HPP_
#define PASSENGER_HPP_
#include <string>
#include "DateOfBirth.h"

using namespace std;

class Passenger {
private:
  string first_name;
  string last_name;
  DateOfBirth dob;
  double fare_discount;

public:
  Passenger();
  Passenger(string, string, DateOfBirth);
  string getFirstName() const;
  string getLastName() const;
  DateOfBirth getDateOfBirth() const;
  void setFirstName(string);
  void setLastName(string);
  void setdob(DateOfBirth);
  void setFareDiscount(double);
  double getDiscount();
  friend ostream& operator<<(ostream&, Passenger&);
};

#endif
