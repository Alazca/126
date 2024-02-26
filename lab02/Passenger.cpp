#include "Passenger.h"
#include <iostream>
#include <string>
#include "DateOfBirth.h"
using namespace std;

// Passenger class initialized using list method, I couldn't resolve errors from
// using "this" version from class
Passenger::Passenger(string firstName_, string lastName_, DateOfBirth dob_)
    : first_name(firstName_), last_name(lastName_), dob(dob_) {}

string Passenger::getFirstName() const {
  return first_name;
}

string Passenger::getLastName() const {
  return last_name;
}

DateOfBirth Passenger::getDateOfBirth() const {
  return dob;
}

void Passenger::setFirstName(string firstName_) {
  this->first_name = firstName_;
}

void Passenger::setLastName(string lastName_) {
  this->last_name = lastName_;
}

void Passenger::setFareDiscount(double rate) {
  // Implment check for values between 0 and 1
  if (rate < 0 || rate > 1) {
    throw std::out_of_range("Discount Rate must be between 0 and 1 inclusive");
  }
  this->fare_discount = rate;
}

double Passenger::getDiscount() {
  return fare_discount;
}

ostream& operator<<(ostream& out, Passenger& person) {
  out << "PASSENGER: " << person.getLastName() << ", " << person.getFirstName()
      << " "
      << "\nDOB: " << person.dob;
  return out;
}
