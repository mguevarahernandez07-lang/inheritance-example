# Inheritance Example – C++ Bank Project

This program demonstrates inheritance using three classes:
- `bankAccount` (base class)
- `checkingAccount` (child class)
- `savingsAccount` (child class)

The project lets the user:
- Deposit money  
- Withdraw money  
- Check balances  
- Print account details  
- Apply interest (for savings)

---

## bankAccount.h
```cpp
#pragma once
#include <iostream>

// This class represents a basic bank account.
// It stores two simple pieces of info: the account number and the balance.
class bankAccount {
private:
    int accountNumber; // the unique ID for the account
    double balance;    // how much money is currently inside

public:
    // Default account starts empty with ID 0.
    bankAccount();

    // Constructor that lets the user set the starting ID and balance.
    bankAccount(int accountNumber, double balance);

    // Set a new account number.
    void setAccountNumber(int number);

    // Return the account number (does not change anything).
    int getAccountNumber() const;

    // Return the current balance (again, no changes made).
    double getAccountBalance() const;

    // Add money to the balance.
    void deposit(double amount);

    // Take money out of the balance (no overdraft rules here).
    void withdraw(double amount);

    // Display account info neatly.
    void print() const;
};
```

## bankAccount.cpp
```cpp
#include "bankAccount.h"

bankAccount::bankAccount()
    : accountNumber(0), balance(0.0) {}

bankAccount::bankAccount(int accountNumber, double balance)
    : accountNumber(accountNumber), balance(balance) {}

void bankAccount::setAccountNumber(int number) {
    accountNumber = number;
}

int bankAccount::getAccountNumber() const {
    return accountNumber;
}

double bankAccount::getAccountBalance() const {
    return balance;
}

void bankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

void bankAccount::withdraw(double amount) {
    if (amount > 0) {
        balance -= amount;
    }
}

void bankAccount::print() const {
    std::cout << "Account Number: " << accountNumber << "\n";
    std::cout << "Balance: $" << balance << "\n";
}
```

## checkingAccount.h
```cpp
#pragma once
#include "bankAccount.h"

// This class represents a checking account.
// It inherits from bankAccount and adds rules:
// - interest rate
// - minimum balance
// - service charges when withdrawing a large amount
class checkingAccount : public bankAccount {
private:
    double interestRate;
    double minBalance;
    double serviceCharges;

public:
    checkingAccount();
    checkingAccount(int accountNumber,
                    double balance,
                    double interestRate,
                    double minBalance,
                    double serviceCharges);

    void setInterestRate(double rate);
    void setMinBalance(double amount);
    void setServiceCharges(double chargeRate);

    double getInterestRate() const;
    double getMinBalance() const;
    double getServiceCharges() const;

    // Shows what today’s interest would be, but doesn’t actually add it.
    void postInterest() const;

    // Checks if your balance meets the minimum requirement.
    bool verifyBalance() const;

    // Deposit works like base class — we keep it here for clarity.
    void deposit(double amount);

    // Withdraw but with checking-account rules.
    void withdraw(double amount);

    // Prints everything including the extra checking info.
    void print() const;
};
```

## checkingAccount.cpp
```cpp
#include "checkingAccount.h"
#include <iostream>
#include <iomanip>

checkingAccount::checkingAccount()
    : bankAccount(), interestRate(0.0), minBalance(0.0), serviceCharges(0.0) {}

checkingAccount::checkingAccount(int accountNumber,
                                 double balance,
                                 double interestRate,
                                 double minBalance,
                                 double serviceCharges)
    : bankAccount(accountNumber, balance),
      interestRate(interestRate),
      minBalance(minBalance),
      serviceCharges(serviceCharges) {}

void checkingAccount::setInterestRate(double rate) {
    interestRate = rate;
}

void checkingAccount::setMinBalance(double amount) {
    minBalance = amount;
}

void checkingAccount::setServiceCharges(double chargeRate) {
    serviceCharges = chargeRate;
}

double checkingAccount::getInterestRate() const {
    return interestRate;
}

double checkingAccount::getMinBalance() const {
    return minBalance;
}

double checkingAccount::getServiceCharges() const {
    return serviceCharges;
}

void checkingAccount::postInterest() const {
    double dailyInterest = getAccountBalance() *
                           (interestRate / 100.0 / 365.0);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Daily interest earned: $" << dailyInterest << "\n";
}

bool checkingAccount::verifyBalance() const {
    double bal = getAccountBalance();
    std::cout << "Your current balance is: $" << bal << "\n";

    return bal >= minBalance;
}

void checkingAccount::deposit(double amount) {
    bankAccount::deposit(amount);
}

void checkingAccount::withdraw(double amount) {
    double bal = getAccountBalance();

    if (amount <= 0) {
        std::cout << "Cannot withdraw a negative or zero amount.\n";
        return;
    }

    if (amount > bal) {
        std::cout << "Not enough money to withdraw this amount.\n";
        return;
    }

    if (amount > 500) {
        double fee = amount * (serviceCharges / 100.0);
        double total = amount + fee;

        if (total > bal) {
            std::cout << "After fees, you don't have enough money.\n";
            return;
        }

        bankAccount::withdraw(total);
        std::cout << "A service fee of $" << fee << " was applied.\n";
    } else {
        bankAccount::withdraw(amount);
    }

    std::cout << "New checking balance: $" << getAccountBalance() << "\n";
}

void checkingAccount::print() const {
    std::cout << "=== Checking Account Info ===\n";
    bankAccount::print();
    std::cout << "Interest Rate: " << interestRate << "%\n";
    std::cout << "Minimum Balance: $" << minBalance << "\n";
    std::cout << "Service Charges: " << serviceCharges << "%\n";
}
```

## savingsAccount.h
```cpp
#pragma once
#include "bankAccount.h"

// This class represents a savings account.
// It has its own interest rate and simpler withdraw rules.
class savingsAccount : public bankAccount {
private:
    double interestRate;

public:
    savingsAccount();
    savingsAccount(int accountNumber,
                   double balance,
                   double interestRate);

    void setInterestRate(double rate);
    double getInterestRate() const;

    // Actually adds interest to the balance.
    void postInterest();

    // Only allows withdrawal if enough balance exists.
    void withdraw(double amount);

    void print() const;
};
```

## savingsAccount.cpp
```cpp
#include "savingsAccount.h"
#include <iostream>

savingsAccount::savingsAccount()
    : bankAccount(), interestRate(0.0) {}

savingsAccount::savingsAccount(int accountNumber,
                               double balance,
                               double interestRate)
    : bankAccount(accountNumber, balance),
      interestRate(interestRate) {}

void savingsAccount::setInterestRate(double rate) {
    interestRate = rate;
}

double savingsAccount::getInterestRate() const {
    return interestRate;
}

void savingsAccount::postInterest() {
    double bal = getAccountBalance();
    double interest = bal * (interestRate / 100.0);
    deposit(interest);

    std::cout << "Interest added: $" << interest << "\n";
}

void savingsAccount::withdraw(double amount) {
    double bal = getAccountBalance();

    if (amount > bal) {
        std::cout << "Not enough money in savings to withdraw that amount.\n";
        return;
    }

    bankAccount::withdraw(amount);
    std::cout << "New savings balance: $" << getAccountBalance() << "\n";
}

void savingsAccount::print() const {
    std::cout << "=== Savings Account Info ===\n";
    bankAccount::print();
    std::cout << "Interest Rate: " << interestRate << "%\n";
}
```

## main.cpp
```cpp
#include <iostream>
#include "checkingAccount.h"
#include "savingsAccount.h"

int main() {
    int num;
    double bal, rate, minBal, service;

    std::cout << "Enter checking account number: ";
    std::cin >> num;
    std::cout << "Enter starting balance: ";
    std::cin >> bal;
    std::cout << "Enter interest rate (%): ";
    std::cin >> rate;
    std::cout << "Enter minimum balance: ";
    std::cin >> minBal;
    std::cout << "Enter service charge (%): ";
    std::cin >> service;

    checkingAccount chk(num, bal, rate, minBal, service);

    int choice;
    double amt;

    do {
        std::cout << "\n1) Deposit\n2) Withdraw\n3) Print Info\n4) Post Interest\n0) Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Deposit amount: ";
                std::cin >> amt;
                chk.deposit(amt);
                break;
            case 2:
                std::cout << "Withdraw amount: ";
                std::cin >> amt;
                chk.withdraw(amt);
                break;
            case 3:
                chk.print();
                break;
            case 4:
                chk.postInterest();
                break;
        }

    } while (choice != 0);

    return 0;
}
```

---

# How to Compile
Use this command:

```
g++ main.cpp bankAccount.cpp checkingAccount.cpp savingsAccount.cpp -o program
```

Run the program:

```
./program
```

---

