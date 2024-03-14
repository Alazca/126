#ifndef IMPERIALWEIGHT_H_
#define IMPERIALWEIGHT_H_

#include <iostream>
using namespace std;

class imperialWeight {
private:
  int ounces;
  int pounds;

public:
  imperialWeight();
  imperialWeight(const int&, const int&);
  ~imperialWeight(){};
  int getOunces() const;
  int getPounds() const;
  void setOunces(const int&);
  void setPounds(const int&);
  friend ostream& operator<<(ostream&, imperialWeight&);
  imperialWeight operator+(imperialWeight&);
  bool operator>(imperialWeight&);
  bool operator<(imperialWeight&);
  bool operator>=(imperialWeight&);
  bool operator<=(imperialWeight&);
};
#endif
