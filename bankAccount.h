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

