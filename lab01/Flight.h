/*
 * Flight.h
 *
 *  Created on: Feb 6, 2024
 *      Author: andyl
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_
#include "Time.h"

using namespace std;

class Flight {
private:
  string src;
  string dest;
  Time departureTime;

public:
  // Every flight must have a source and dest
  Flight(string &, string &);
  void setSrc(string &);
  void setDest(string &);
  // Setting departure time via parameters or Time objects
  void setDepartureTime(const int &, const int &);
  void setDepartureTime(Time &);
  Time getDepartureTime();
  string getSrc() const;
  string getDest() const;
  friend ostream &operator<<(ostream &, Flight &);
};

#endif /* FLIGHT_H_ */
