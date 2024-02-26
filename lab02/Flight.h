/*
 * Flight.h
 * Extended version for lab2
 *
 * Author: alazca
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_
#include "DateOfBirth.h"
#include "Time.h"

using namespace std;

class Flight {
private:
  string src;
  string dest;
  Time departureTime;
  double baseFare;
  Date dateOfTravel;

public:
  Flight();
  // Every flight must have a source and dest
  Flight(const string&, const string&);
  Flight(const string&, const string&, Date&);
  // If needed to create flight objects with a fare or date of travel
  Flight(const string&, const string&, double&, Date&);
  void setSrc(string&);
  void setDest(string&);
  // Setting departure time via parameters or Time objects
  void setDepartureTime(const int&, const int&);
  void setDepartureTime(Time&);
  Time getDepartureTime();
  string getSrc() const;
  string getDest() const;
  double getFare() const;
  void setFare(double);
  void setDate(Date);
  Date getDateOfTravel() const;
  friend ostream& operator<<(ostream&, Flight&);
};

#endif /* FLIGHT_H_ */
