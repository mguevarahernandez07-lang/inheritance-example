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

