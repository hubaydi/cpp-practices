#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>


void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
// returns the winner character ('X' or 'O'), or '-' if no winner yet
char checkWinner(char *spaces);
bool checkTie(char *spaces);



int main() {

  char spaces[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
  char player = 'X';
  char computer = 'O';
  bool gameOver = false;

  // seed random once
  std::srand(static_cast<unsigned>(std::time(nullptr)));

  drawBoard(spaces);

  while (!gameOver) {
    playerMove(spaces, player);
    drawBoard(spaces);

    {
      char winner = checkWinner(spaces);
      if (winner == player) {
        std::cout << "Player wins!" << std::endl;
        gameOver = true;
        break;
      } else if (winner == computer) {
        std::cout << "Computer wins!" << std::endl;
        gameOver = true;
        break;
      }
    }
    if (checkTie(spaces)) {
      std::cout << "It's a tie!" << std::endl;
      gameOver = true;
      break;
    }

    computerMove(spaces, computer);
    drawBoard(spaces);

    {
      char winner = checkWinner(spaces);
      if (winner == player) {
        std::cout << "Player wins!" << std::endl;
        gameOver = true;
        break;
      } else if (winner == computer) {
        std::cout << "Computer wins!" << std::endl;
        gameOver = true;
        break;
      }
    }
    if (checkTie(spaces)) {
      std::cout << "It's a tie!" << std::endl;
      gameOver = true;
      break;
    }
  }
  return 0;
}

void drawBoard(char *spaces) {
  std::cout << " " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << " \n";
  std::cout << "-----------\n";
  std::cout << " " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << " \n";
  std::cout << "-----------\n";
  std::cout << " " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << " \n";
  std::cout << std::endl;
};

void playerMove(char *spaces, char player) {
  int number;

  while (true) {
    std::cout << "Enter a number (1-9) to place your " << player << ": ";
    if (!(std::cin >> number)) {
      // non-integer input
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a number between 1 and 9." << std::endl;
      continue;
    }

    number--; // Adjust for 0-based index

    if (number < 0 || number > 8) {
      std::cout << "Invalid input. Please enter a number between 1 and 9." << std::endl;
      continue;
    }
    if (spaces[number] != '-') {
      std::cout << "That space is already taken. Please choose another." << std::endl;
      continue;
    }

    // valid move
    spaces[number] = player;
    break;
  }

}
void computerMove(char *spaces, char computer) {
  int number;

  // do {
  //   number = rand() % 9;
  // } while (spaces[number] != '-');
  // spaces[number] = computer;

  while (true) {
    number = rand() % 9;

    if (spaces[number] == '-') {
      spaces[number] = computer;
      break;
    }
  }
}; 
char checkWinner(char *spaces) {
  // return 'X' or 'O' if found, otherwise '-'
  auto checkLine = [&](int a, int b, int c) -> char {
    if (spaces[a] == spaces[b] && spaces[b] == spaces[c] && spaces[a] != '-') {
      return spaces[a];
    }
    return '-';
  };

  char w = checkLine(0, 1, 2);
  if (w != '-') return w;
  w = checkLine(3, 4, 5);
  if (w != '-') return w;
  w = checkLine(6, 7, 8);
  if (w != '-') return w;
  w = checkLine(0, 3, 6);
  if (w != '-') return w;
  w = checkLine(1, 4, 7);
  if (w != '-') return w;
  w = checkLine(2, 5, 8);
  if (w != '-') return w;
  w = checkLine(0, 4, 8);
  if (w != '-') return w;
  w = checkLine(2, 4, 6);
  if (w != '-') return w;

  return '-';
}
bool checkTie(char *spaces) {
  for (int i = 0; i < 9; i++) {
    if (spaces[i] == '-') {
      return false;
    }
  }
  return true;
};

