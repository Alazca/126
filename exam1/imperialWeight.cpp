#include "imperialWeight.h"

imperialWeight::imperialWeight() {
  setOunces(0);
  setPounds(0);
}

imperialWeight::imperialWeight(const int& lbs, const int& oz) {
  setPounds(lbs);
  setOunces(oz);
}

int imperialWeight::getOunces() const {
  return ounces;
}

int imperialWeight::getPounds() const {
  return pounds;
}

void imperialWeight::setOunces(const int& oz) {
  if (oz < 0 || oz > 15) {
    throw out_of_range("OUNCES OUT OF RANGE");
  }
  this->ounces = oz;
}

void imperialWeight::setPounds(const int& lbs) {
  if (lbs < 0) {
    throw out_of_range("POUNDS OUT OF RANGE");
  }
  this->pounds = lbs;
}

ostream& operator<<(ostream& os, imperialWeight& weight) {
  os << weight.getPounds() << "lbs, " << weight.getOunces() << "oz" << endl;
  return os;
}

bool imperialWeight::operator<(imperialWeight& rhs) {
  bool flag = false;
  if (this->getPounds() < rhs.getPounds()) {
    flag = true;
  } else if (this->getPounds() == rhs.getPounds() &&
             this->getOunces() < rhs.getOunces()) {
    flag = true;
  }
  return flag;
}

bool imperialWeight::operator<=(imperialWeight& rhs) {
  bool flag = false;
  if (this->getPounds() <= rhs.getPounds()) {
    flag = true;
  } else if (this->getPounds() == rhs.getPounds() &&
             this->getOunces() <= rhs.getOunces()) {
    flag = true;
  }
  return flag;
}

bool imperialWeight::operator>(imperialWeight& rhs) {
  bool flag = false;
  if (this->getPounds() > rhs.getPounds()) {
    flag = true;
  } else if (this->getPounds() == rhs.getPounds() &&
             this->getOunces() > rhs.getOunces()) {
    flag = true;
  }
  return flag;
}

bool imperialWeight::operator>=(imperialWeight& rhs) {
  bool flag = false;
  if (this->getPounds() >= rhs.getPounds()) {
    flag = true;
  } else if (this->getPounds() == rhs.getPounds() &&
             this->getOunces() >= rhs.getOunces()) {
    flag = true;
  }
  return flag;
}

imperialWeight imperialWeight::operator+(imperialWeight& rhs) {
  imperialWeight temp;
  temp.pounds = pounds + rhs.pounds;
  temp.ounces = ounces + rhs.ounces;
  if (temp.ounces >= 16) {
    temp.pounds += (temp.ounces / 16);
    temp.ounces %= 16;
  }
  return temp;
}
