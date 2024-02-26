#include "Ticket.h"
#include "DateOfBirth.h"
#include "Flight.h"

using namespace std;

Ticket::Ticket(Passenger& passenger, Flight flight)
    : passenger(passenger), flight(flight) {
  this->updateFare();
}

Passenger Ticket::getName() {
  return passenger;
}

Flight Ticket::getFlight() {
  return flight;
}

double Ticket::getFare() {
  return passengerFare;
}

void Ticket::setTicketFare(double fare) {
  this->passengerFare = fare;
}

void Ticket::setPassenger(Passenger passenger) {
  this->passenger = passenger;
  this->passenger.setFareDiscount(passenger.getDiscount());
}

void Ticket::updateFare() {
  double fare = flight.getFare();
  double discount = this->passenger.getDiscount();
  setTicketFare(fare * (1 - discount));
}

void Ticket::updateFlight(Flight& flight_) {
  string src = flight_.getSrc();
  string dest = flight_.getDest();
  Date newDate(flight_.getDateOfTravel());
  flight.setDate(newDate);
  flight.setSrc(src);
  flight.setDest(dest);
  cout << "NEW FLIGHT:" << flight_.getSrc() << " TO " << flight_.getDest()
       << " ON DATE:  " << newDate.getMonth() << "-" << newDate.getDay() << "-"
       << newDate.getYear() << endl;
}

ostream& operator<<(ostream& out, Ticket& ticket) {
  out << "FLIGHT: " << ticket.getFlight().getSrc() << " TO "
      << ticket.getFlight().getDest()
      << "\nPassenger: " << ticket.getName().getLastName() << ","
      << ticket.getName().getFirstName();
  return out;
}
