#include <iomanip>
#include <iostream>
#include "DateOfBirth.h"
#include "Flight.h"
#include "Passenger.h"
#include "Ticket.h"

using namespace std;

int main() {
  Date d1;
  Date d2(2, 15, 2024);
  DateOfBirth d3(5, 10, 1970);
  DateOfBirth d4(d1);
  cout << d1;
  cout << d2;
  cout << d3 << d4;
  cout << d3.getAge() << " years old" << endl;
  string first_name = "John";
  string last_name = "Smith";
  DateOfBirth d5(5, 10, 1970);
  Passenger p1(first_name, last_name, d5);
  cout << p1;  // Outputs Passenger information
  p1.setFareDiscount(0.25);
  string src = "SFO";
  string dest = "LAX";
  double fare1 = 235.85;
  Flight f1(src, dest, fare1, d2);
  f1.setDepartureTime(13, 45);
  cout << f1;  // Outputs flight information in a suitable format
  // Lab handout used variable t1 but changed to t4 for conciseness
  Time t4(6, 30);
  f1.setDepartureTime(t4);
  cout << f1;
  Ticket ticket(p1, f1);
  cout << ticket << endl;
  p1.setFareDiscount(0.5);
  ticket.updateFare();
  cout << "PAID FARE: $" << setprecision(5) << ticket.getFare() << endl;
  // Changed variable to d6 for conciseness
  Date d6(3, 18, 2024);
  // string src2  = "SD";
  // string dest2 = "DEN";
  Flight f2("SD", "DEN", d6);
  ticket.updateFlight(f2);
  return 0;
}
