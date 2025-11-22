#include <iostream>
#include <ctime>

int main() {
  int num;
  int guess;
  int tries;

  srand(time(NULL)); 
  int randNum = (rand() % 100) + 1; 

  std::cout << "***** NUMBER GUESSING GAME ***********" << randNum << std::endl;

  do {
    std::cout << "Enter your guess (1-100): ";
    std::cin >> guess;
    tries++;

    if (guess > randNum) {
      std::cout << "Too high! Try again." << std::endl;
    } else if (guess < randNum) {
      std::cout << "Too low! Try again." << std::endl;
    } else {
      std::cout << "Congratulations! You've guessed the number " << randNum << " in " << tries << " tries." << std::endl;
    }
  } while (guess != randNum);
  return 0;
}