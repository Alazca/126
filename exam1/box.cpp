#include "box.h"

Box::Box(const string& name, imperialWeight& weight)
    : name(name), weight(weight) {}

string Box::getName() const {
  return name;
}

imperialWeight Box::getWeight() const {
  return weight;
}

void Box::setName(string& name_) {
  this->name = name_;
}

void Box::setWeight(int& lbs, int& oz) {
  this->setWeight(lbs, oz);
}

Box Box::addBox(const Box& addBox) {
  Box newBox(addBox);
  return newBox;
}
