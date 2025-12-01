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

