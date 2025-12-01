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

