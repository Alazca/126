#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <stack>
using namespace std;

class Calculator {
public:
	Calculator();
	~Calculator();
	void add(double);
	void subtract(double);
	double getResult();
	void undo();
	void redo();
	void printAllOperations();
private:
	double result;
	stack<double> operands;
  stack<double> undone;
};

#endif /* CALCULATOR_H_ */
