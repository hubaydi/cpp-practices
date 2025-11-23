#include <iostream>
#include <iomanip>
#include <limits>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main() {
    double balance = 14.0;
    int choice = 0;

    do {
        std::cout << "\nBanking Menu:\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
    std::cin >> choice;

    // If extraction failed (e.g. user entered non-numeric text), clear the
    // error state so we can continue. In either case, discard the rest of
    // the line so leftover input doesn't interfere with the next read.
    if (std::cin.fail()) {
      std::cin.clear();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                showBalance(balance);
                break;
            case 2: 
                balance += deposit();
                showBalance(balance);
                break;
            case 3: {
                balance -= withdraw(balance);
                showBalance(balance);
                break;
            }
            case 4:
                std::cout << "Exiting the application. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);
    return 0;
}

void showBalance(double balance) {
  std::cout << "Your current balance is: $" << std::setprecision(2) << std::fixed << balance << std::endl;
};

double deposit() {
  double amount;
  
  std::cout << "Enter amount to deposit: ";
  std::cin >> amount;
  if (amount < 0) {
    std::cout << "Invalid amount. Deposit canceled." << std::endl;
    return 0;
  } else {
    std::cout << "Successfully deposited: $" << std::setprecision(2) << std::fixed << amount << std::endl;
  }
  return amount;
};

double withdraw(double balance) {
  double amount;

  std::cout << "Enter amount to withdraw: ";
  std::cin >> amount;
  if (amount > balance) {
    std::cout << "Insufficient funds. Withdrawal canceled." << std::endl;
    return 0;
  } else if (amount < 0) {
    std::cout << "Invalid amount. Withdrawal canceled." << std::endl;
    return 0;
  } else {
    std::cout << "Please take your cash: $" << std::setprecision(2) << std::fixed << amount << std::endl;
  }
  return amount;
};