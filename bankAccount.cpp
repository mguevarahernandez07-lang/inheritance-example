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

