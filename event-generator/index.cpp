#include <iostream>
#include <ctime>

int main() {
  srand(time(0)); // Seed for random number generation

  int randNum = rand() % 5 + 1; 

  std::cout << "Generated random number: " << randNum << std::endl;

  switch(randNum) {
    case 1:
      std::cout << "Event 1 triggered!" << std::endl;
      break;
    case 2:
      std::cout << "Event 2 triggered!" << std::endl;
      break;
    case 3:
      std::cout << "Event 3 triggered!" << std::endl;
      break;
    case 4:
      std::cout << "Event 4 triggered!" << std::endl;
      break;
    case 5:
      std::cout << "Event 5 triggered!" << std::endl;
      break;
    default:
      std::cout << "No event triggered." << std::endl;
      break;
  }
  return 0;
}