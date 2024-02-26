#ifndef TICKET_HPP_
#define TICKET_HPP_

#include "Flight.h"
#include "Passenger.h"

using namespace std;

class Ticket {
private:
  Passenger& passenger;
  Flight flight;
  double passengerFare;

public:
  Ticket(Passenger&, Flight);
  Passenger getName();
  Flight getFlight();
  void updateFare();
  double getFare();
  void setTicketFare(double);
  void updateFlight(Flight&);
  void setPassenger(Passenger);
  friend ostream& operator<<(ostream&, Ticket&);
};

#endif  // !TICKET_HPP_
