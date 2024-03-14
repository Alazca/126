#ifndef BOX_H_
#define BOX_H_
#include "imperialWeight.h"
using namespace std;

class Box {
private:
  std::string name;
  imperialWeight weight;

public:
  Box();
  ~Box(){};
  Box(const string&, imperialWeight&);
  string getName() const;
  imperialWeight getWeight() const;
  void setName(string&);
  void setWeight(int&, int&);
  Box addBox(const Box&);
  imperialWeight totalWeight();
};

#endif
