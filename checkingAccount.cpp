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

