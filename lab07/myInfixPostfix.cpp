#include "arrayList.h"
#include <stack>
#include <string>

using namespace std;

// Function to get precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

string infixToPostfix(string arg){
  stack<char> stack1;
  arrayList<char> stack;

  string postfixExpression;
  // Empty check
  if (arg.size() == 0){
    return "Empty String!";
  }
  for (int i = 0; i < arg.length(); i++) {
        char ch = arg[i];
        if (arg[i] == ' '){
          continue;
        }
    // Used alnum for efficient character expression
        if (isalnum(ch)) {
            postfixExpression += ch;
        } else if (ch == '(') {
            stack.push('(');
        } else if (ch == ')') {
            while (stack.top() != '(') {
                postfixExpression += stack.top();
                stack.pop();
            }
            stack.pop();  
        } else {
            while (!stack.empty() && precedence(ch) <= precedence(stack.top())) {
                postfixExpression += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }
    while (!stack.empty()) {
        postfixExpression += stack.top();
        stack.pop();
    }
  return postfixExpression;
}

int main() {
    string infixExpression1 = "A+B-C";
    string infixExpression2 = "(A+B)*C";
    string infixExpression3 = "(A+B)*(C-D)";
    string infixExpression4 = "A + B * (C + D) - E / F * G + H";
    
    string postfixExpression = infixToPostfix(infixExpression1);
    cout << "Postfix expression: " << postfixExpression << endl;
    postfixExpression = infixToPostfix(infixExpression2);
    cout << "Postfix expression: " << postfixExpression << endl;
    postfixExpression = infixToPostfix(infixExpression3);
    cout << "Postfix expression: " << postfixExpression << endl;
    postfixExpression = infixToPostfix(infixExpression4);
    cout << "Postfix expression: " << postfixExpression << endl;
    return 0;
}
