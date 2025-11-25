#include <iostream>

using namespace std;

class Student {
  public:
    string name;
    int age;
    bool isEnrolled = false;

    Student(string n, int a) : name(n), age(a), isEnrolled(false) {}

    void enroll() {
      isEnrolled = true;
      cout << name << " has been enrolled." << endl;
    }

    void displayInfo() {
      cout << "Name: " << name << endl;
      cout << "Age: " << age << endl;
      cout << "Enrolled: " << (isEnrolled ? "Yes" : "No") << endl;
    }
};

// overloaded class constructor
class Pizza {
  public:
    string toppings;

    Pizza() {
      this->toppings = "Cheese";
      cout << "Default cheese pizza created." << endl;
    }

    Pizza(string topping1) {
      this->toppings = topping1;
      cout << "Pizza with " << topping1 << " created." << endl;
    }

    Pizza(string topping1, string topping2) {
      this->toppings = topping1 + " and " + topping2;
      cout << "Pizza with " << this->toppings << " created." << endl;
    }
    
};

// getter and setter example
class BankAccount {
  private:
    double balance;

  public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    double getBalance() {
      return balance;
    }

    void deposit(double amount) {
      if (amount > 0) {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
      } else {
        cout << "Deposit amount must be positive!" << endl;
      }
    }

    void withdraw(double amount) {
      if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrew: $" << amount << endl;
      } else {
        cout << "Invalid withdrawal amount!" << endl;
      }
    }
};

int main() {
  Student student1("Alice", 20);
  student1.displayInfo();
  student1.enroll();
  student1.displayInfo();

  cout << "*********" << endl;

  
  Pizza pizza1("Pepperoni");
  Pizza pizza2("Mushrooms", "Olives");
  Pizza pizza3;

  cout << "*********" << endl;

  BankAccount account(100.0);
  cout << "Initial Balance: $" << account.getBalance() << endl;
  account.deposit(50.0);
  cout << "Balance after deposit: $" << account.getBalance() << endl;
  account.withdraw(30.0);
  cout << "Balance after withdrawal: $" << account.getBalance() << endl;
  
  return 0;
}