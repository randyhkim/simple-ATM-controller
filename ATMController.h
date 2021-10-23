#ifndef SIMPLE_ATM_CONTROLLER_ATMCONTROLLER_H
#define SIMPLE_ATM_CONTROLLER_ATMCONTROLLER_H

#include "CashBinDev.h"
#include "ATMDisplayManagerDev.h"
#include "BankSystemDev.h"

class ATMController {
private:

    CashBinDev cashBin;
    ATMDisplayManagerDev displayManager;
    BankSystemDev bankSystem;

public:

    // Class Constructor
    explicit ATMController(BankSystemDev& givenBankSystem, size_t cashInBin);

    // Main loop for ATM Controller
    // Returns 1 if error
    int ATMControllerMainProcess();

    // takes care of account balance check, deposit, and withdraw
    // input value is account selection number from previous window
    // returns true when interrupt needed
    bool accountActionProcess(size_t accountSelection);

};

#endif //SIMPLE_ATM_CONTROLLER_ATMCONTROLLER_H
