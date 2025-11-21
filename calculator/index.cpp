#include <iostream>
#include <cmath>

int main() {

  char op;
  double num1;
  double num2;
  double result;

  std::cout << "Enter Number 1: ";
  std::cin >> num1;
  
  std::cout << "Enter Operation: ";
  std::cin >> op;

  std::cout << "Enter Number 2: ";
  std::cin >> num2;

  

  switch(op) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      result = num1 / num2;
      break;
    default:
      std::cout << "You Entered wrong Operation!";
  }

  std::cout << "The result is:" << result;


  return 0;
}