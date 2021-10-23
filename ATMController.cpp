#include "ATMController.h"

#include <utility>

ATMController::ATMController(BankSystemDev& givenBankSystem, size_t cashInBin) {
    cashBin = CashBinDev(cashInBin);
    displayManager = ATMDisplayManagerDev();
    bankSystem = givenBankSystem;
}

int ATMController::ATMControllerMainProcess() {

    bool interrupt = false;

    while (!interrupt) {
        displayManager.drawWelcomeScreen();

        std::string cardNumber;
        std::cin >> cardNumber;

        // dev mode override
        if (cardNumber == "dev") {
            displayManager.devModeOn();
            ATMControllerMainProcess();
        }

        // for production, would actually be reading card info
        displayManager.drawCardReadScreen();

        displayManager.drawEnterPINScreen();
        std::string input;
        std::cin >> input;
        std::vector<size_t> inputPin;

        for (size_t i = 0; i < input.length(); i++) {
            inputPin.push_back(input[i] - '0');
        }

        bool userAuthenticated = bankSystem.userLogIn(cardNumber, inputPin);

        if (userAuthenticated) {

            // account selection
            displayManager.drawSelectAccountScreen(bankSystem.getUserName(), bankSystem.getAccounts());
            size_t accountSelection;
            std::cin >> accountSelection;

            // error when out of bounds number selection (for demonstration purpose)
            if (accountSelection >=  bankSystem.getAccounts().size()) {
                interrupt = true;
                displayManager.drawErrorScreen();
                return 1;
            }

            // check balance, deposit, withdraw
            interrupt = accountActionProcess(accountSelection);

            if (interrupt) {
                displayManager.drawErrorScreen();
                return 1;
            }

            // log out
            bankSystem.userLogOut();
        } else {
            // draw error message
            displayManager.drawNotAuthenticated();

            // restart process
            ATMControllerMainProcess();
        }
    }

    displayManager.drawErrorScreen();
    return 1;
}

bool ATMController::accountActionProcess(size_t accountSelection) {
    std::string accountName = bankSystem.getAccounts()[accountSelection - 1];
    int balance = bankSystem.getAccountBalance(accountName);

    displayManager.drawBalanceDepositWithdrawScreen(accountName, balance);

    std::string actionSelection;
    std::cin >> actionSelection;
    size_t actionInt = std::stoi(actionSelection);

    switch(actionInt) {
        case 1:
            displayManager.drawDepositScreen();
            size_t depositMoney;
            std::cin >> depositMoney;
            bankSystem.depositMoney(accountName, depositMoney);

            // add money to cash bin
            cashBin.addBills(depositMoney);

            // return to account actions
            accountActionProcess(accountSelection);
            break;
        case 2:
            displayManager.drawWithdrawScreen();
            size_t withdrawMoney;
            std::cin >> withdrawMoney;

            size_t actuallyWithdrawn;
            actuallyWithdrawn = cashBin.removeBills(withdrawMoney);

            if (actuallyWithdrawn < withdrawMoney) {
                // message that not enough cash in bin
                displayManager.drawNotEnoughBillsScreen();
            }

            // withdraw from bank system
            bankSystem.withdrawMoney(accountName, actuallyWithdrawn);

            // return to account actions
            accountActionProcess(accountSelection);
            break;
        case 3:
            displayManager.drawExitScreen();
            ATMControllerMainProcess();
            break;
        default:
            return true;
    }
    return false;
}
