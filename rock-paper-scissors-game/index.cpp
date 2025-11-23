#include <iostream>
#include <cmath>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void determineWinner(char userChoice, char computerChoice);

int main() {
  
  char userChoice;
  char computerChoice;

  userChoice = getUserChoice();
  std::cout << "You chose: ";
  showChoice(userChoice);

  computerChoice = getComputerChoice();
  std::cout << "Computer chose: ";
  showChoice(computerChoice);

  determineWinner(userChoice, computerChoice);
  return 0;
}

char getUserChoice() {
  char userChoice;
  std::cout << "Rock-Paper-Scissors Game" << std::endl;
  std::cout << "<-     ****    -<" << std::endl;


  do {
    std::cout << "choice one of the following:" << std::endl;
    std::cout << "Enter 'r' for Rock" << std::endl;
    std::cout << "Enter 'p' for Paper" << std::endl;
    std::cout << "Enter 's' for Scissors" << std::endl;
    
    std::cin >> userChoice;
  } while (userChoice != 'r' && userChoice != 'p' && userChoice != 's');

  return userChoice;
};

char getComputerChoice() {
  srand(time(0));
  int randomNum = rand() % 3 + 1;

  switch (randomNum) {
    case 1:
      return 'r';
      break;
    case 2:
      return 'p';
      break;
    case 3:
      return 's';
      break;
  }

  return 0;
};
void showChoice(char choice) {
  switch (choice) {
    case 'r':
      std::cout << "Rock" << std::endl;
      break;
    case 'p':
      std::cout << "Paper" << std::endl;
      break;
    case 's':
      std::cout << "Scissors" << std::endl;
      break;
    default:
      break;
  }
};

void determineWinner(char userChoice, char computerChoice) {
  switch (userChoice) {
    case 'r':
      if (computerChoice == 'r') {
        std::cout << "It's a tie!" << std::endl;
      } else if (computerChoice == 'p') {
        std::cout << "Computer wins!" << std::endl;
      } else if (computerChoice == 's') {
        std::cout << "You win!" << std::endl;
      }
      break;
    case 'p':
      if (computerChoice == 'r') {
        std::cout << "You win!" << std::endl;
      } else if (computerChoice == 'p') {
        std::cout << "It's a tie!" << std::endl;
      } else if (computerChoice == 's') {
        std::cout << "Computer wins!" << std::endl;
      }
      break;
    case 's':
      if (computerChoice == 'r') {
        std::cout << "Computer wins!" << std::endl;
      } else if (computerChoice == 'p') {
        std::cout << "You win!" << std::endl;
      } else {
        std::cout << "It's a tie!" << std::endl;
      }
      break;
    default:
      break;
  }
};