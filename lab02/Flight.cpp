#include "Flight.h"
#include <iomanip>
#include <string>
#include "DateOfBirth.h"
#include "Time.h"

Flight::Flight(const string& src_, const string& dest_)
    : src(src_), dest(dest_) {}

Flight::Flight(const string& src_, const string& dest_, Date& date_)
    : src(src_), dest(dest_), dateOfTravel(date_) {}

Flight::Flight(const string& src_, const string& dest_, double& fare_,
               Date& dateOfTravel_)
    : src(src_), dest(dest_), baseFare(fare_), dateOfTravel(dateOfTravel_) {}

void Flight::setDepartureTime(Time& t) {
  departureTime.sethr(t.gethr());
  departureTime.setmin(t.getmin());
}

void Flight::setDepartureTime(const int& hr, const int& m) {
  departureTime.sethr(hr);
  departureTime.setmin(m);
}

void Flight::setSrc(string& src_) {
  this->src = src_;
}

void Flight::setDest(string& dest_) {
  this->dest = dest_;
}

string Flight::getSrc() const {
  return src;
}

string Flight::getDest() const {
  return dest;
}

Time Flight::getDepartureTime() {
  return departureTime;
}

double Flight::getFare() const {
  return baseFare;
}

void Flight::setFare(double fare_) {
  this->baseFare = fare_;
}

void Flight::setDate(Date date_) {
  dateOfTravel.setDate(date_);
}

Date Flight::getDateOfTravel() const {
  return dateOfTravel;
}

ostream& operator<<(ostream& os, Flight& flight_) {
  os << flight_.getSrc() << " DEPARTS at " << setw(2) << setfill('0')
     << flight_.getDepartureTime().gethr() << ":"
     << flight_.getDepartureTime().getmin() << " to " << flight_.getDest()
     << endl;
  return os;
}
