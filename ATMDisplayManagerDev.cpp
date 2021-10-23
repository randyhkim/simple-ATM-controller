#include "ATMDisplayManagerDev.h"

void ATMDisplayManagerDev::printScreenVector() {
    printNewLines();
    for (size_t i = 0; i < screenVector.size(); i++) {
        std::cout << screenVector[i];
    }
}

void ATMDisplayManagerDev::resetScreenVector() {
    screenVector = {
            topBottomRow, blankRow, atm, blankRow, blankRow, blankRow, blankRow, blankRow, blankRow, topBottomRow
    };

    if (showDevMessage) {
        screenVector[2] = atmDevMode;
        screenVector[8] = devRow;
    }
}

void ATMDisplayManagerDev::printNewLines() {
    std::cout << "\n\n\n\n\n\n\n\n\n\n";
}

void ATMDisplayManagerDev::addDevMessage(const std::string &message) {
    std::string devMessage = devRow;
    devMessage.replace(15, message.length(), message);

    screenVector[8] = devMessage;
}

ATMDisplayManagerDev::ATMDisplayManagerDev() : showDevMessage(false) {
    resetScreenVector();
}

void ATMDisplayManagerDev::devModeOn() {
    showDevMessage = true;
}

void ATMDisplayManagerDev::devModeOff() {
    showDevMessage = false;
}

void ATMDisplayManagerDev::drawWelcomeScreen() {
    resetScreenVector();

    screenVector[4] = welcome;
    screenVector[5] = enterCardNum;

    if (showDevMessage) {
        screenVector[2] = atmDevMode;
    }
    printScreenVector();
}

void ATMDisplayManagerDev::drawCardReadScreen() {
    resetScreenVector();

    screenVector[4] = readingCard;
    if (showDevMessage) {
        addDevMessage("Reading card...");
    }

    printScreenVector();
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

void ATMDisplayManagerDev::drawEnterPINScreen() {
    resetScreenVector();

    screenVector[4] = cardInserted;
    screenVector[5] = enterPinNum;
    if (showDevMessage) {
        addDevMessage("Card information read complete");
    }

    printScreenVector();
}

void ATMDisplayManagerDev::drawSelectAccountScreen(const std::string& userName, const std::vector<std::string>& accounts) {
    resetScreenVector();

    screenVector[3] = selectAccount;

    // welcome user name
    std::string row = blankRow;
    std::string userNameWelcome = "Welcome, ";
    userNameWelcome.append(userName);
    userNameWelcome.append("!");
    row.replace(4, userNameWelcome.length(), userNameWelcome);
    screenVector[4] = row;

    // account list
    size_t vector_index = 5;
    while (vector_index < screenVector.size() && vector_index- 5 < accounts.size()) {
        row = blankRow;
        std::string account;
        account.append(std::to_string(vector_index - 4));
        account.append(". ");
        account.append(accounts[vector_index - 5]);

        row.replace(4, account.length(), account);
        screenVector[vector_index] = row;
        vector_index++;
    }

    printScreenVector();
}

void ATMDisplayManagerDev::drawBalanceDepositWithdrawScreen(const std::string& account, int balance) {
    resetScreenVector();

    std::string row = blankRow;
    std::string accountString = "Account: ";
    accountString.append(account);
    row.replace(4, accountString.length(), accountString);
    screenVector[3] = row;

    std::string balanceRow = blankRow;
    std::string balanceString = "Balance: ";
    balanceString.append(std::to_string(balance));
    balanceRow.replace(4, balanceString.length(), balanceString);
    screenVector[4] = balanceRow;

    // actions
    screenVector[5] = deposit;
    screenVector[6] = withdraw;
    screenVector[7] = goBack;

    printScreenVector();
}

void ATMDisplayManagerDev::drawDepositScreen() {
    std::string enterAmount = "Enter amount of money to deposit";
    std::string row = blankRow;
    row.replace(4, enterAmount.length(), enterAmount);

    screenVector[5] = row;
    screenVector[6] = blankRow;
    screenVector[7] = blankRow;

    printScreenVector();
}

void ATMDisplayManagerDev::drawWithdrawScreen() {
    std::string enterAmount = "Enter amount of money to withdraw";
    std::string row = blankRow;
    row.replace(4, enterAmount.length(), enterAmount);

    screenVector[5] = row;
    screenVector[6] = blankRow;
    screenVector[7] = blankRow;

    printScreenVector();
}

void ATMDisplayManagerDev::drawNotEnoughBillsScreen() {
    std::string message1 = "Not enough money in ATM.";
    std::string message2 = "You will have received all available bills in the ATM.";
    std::string row1 = blankRow;
    std::string row2 = blankRow;
    row1.replace(4, message1.length(), message1);
    row2.replace(4, message2.length(), message2);

    screenVector[5] = row1;
    screenVector[6] = row2;

    printScreenVector();
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

void ATMDisplayManagerDev::drawNotAuthenticated() {
    resetScreenVector();

    screenVector[4] = notAuth;

    printScreenVector();
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}

void ATMDisplayManagerDev::drawExitScreen() {
    resetScreenVector();

    screenVector[4] = thankYou;
    screenVector[6] = takeCard;

    printScreenVector();
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}

void ATMDisplayManagerDev::drawErrorScreen() {
    resetScreenVector();

    screenVector[4] = error;
    if (showDevMessage) {
        addDevMessage("fatal error detected.");
    }

    printScreenVector();
}