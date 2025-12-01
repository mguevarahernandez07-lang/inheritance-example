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

