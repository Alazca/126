#include "Flight.h"
#include <iomanip>
#include <string>
#include "Time.h"

Flight::Flight(string &src_, string &dest_) {
  this->src  = src_;
  this->dest = dest_;
}

void Flight::setDepartureTime(Time &t) {
  departureTime.sethr(t.gethr());
  departureTime.setmin(t.getmin());
}

void Flight::setDepartureTime(const int &hr, const int &m) {
  departureTime.sethr(hr);
  departureTime.setmin(m);
}

void Flight::setSrc(string &src_) {
  this->src = src_;
}

void Flight::setDest(string &dest_) {
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

ostream &operator<<(ostream &os, Flight &flight_) {
  os << flight_.getSrc() << " DEPARTS at " << setw(2) << setfill('0')
     << flight_.getDepartureTime().gethr() << ":"
     << flight_.getDepartureTime().getmin() << " to " << flight_.getDest()
     << endl;
  return os;
}
