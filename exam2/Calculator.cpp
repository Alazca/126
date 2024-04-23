#include "Calculator.h"
#include <iostream>
using namespace std;


Calculator::Calculator(){
  result = 0;
}

Calculator::~Calculator(){
  result = 0;
  while (!operands.empty()) {
    operands.pop();
  }
}

void Calculator::add(double op2){
  result += op2; 
  operands.push(op2);
}

void Calculator::subtract(double op2){
  result -= op2;
  operands.push(-op2);
}

double Calculator::getResult(){
  return result;
}

void Calculator::undo(){
  if (!operands.empty()) {
    double lastOp = operands.top();
    undone.push(lastOp);
    result -= operands.top();
    operands.pop();
  } else{
    throw out_of_range("No More actions to undo!");
  }
}

void Calculator::redo(){
  if (!undone.empty()) {
    double lastUndone= undone.top();
    result += lastUndone;
    undone.pop();
    operands.push(lastUndone);
  } else{
    throw out_of_range("No More actions to redo!");
  }
}

void Calculator::printAllOperations(){
  cout << "Operations performed:" << endl;
  while (!operands.empty()) {
    cout << operands.top() << endl;
    operands.pop();
  }
}
