#include "BankUserDev.h"

#include <utility>

BankUserDev::BankUserDev() : userName("Joe Doe") {
    accounts.insert(std::pair<std::string, int>("Default", 0) );
}

BankUserDev::BankUserDev(const std::string& nameInput, const std::string& accountName,
                         int initialDeposit, const std::string& userCardNumber, const std::vector<size_t>& pinInput) {
    userName = nameInput;
    accounts.insert(std::pair<std::string, int>(accountName, initialDeposit) );
    cardNumber = userCardNumber;
    pin = pinInput;
}

std::string BankUserDev::getUserName() {
    return userName;
}

std::string BankUserDev::getCardNumber() {
    return cardNumber;
}

void BankUserDev::changeUserName(const std::string& newName) {
    userName = newName;
}

void BankUserDev::changePinNumber(const std::vector<size_t>& newPin) {
    pin = newPin;
}

void BankUserDev::changeCardNumber(const std::string& newCardNumber) {
    cardNumber = newCardNumber;
}

std::vector<std::string> BankUserDev::getAccounts() {
    std::vector<std::string> accountVector;

    // iterate accounts map
    for(auto it = accounts.begin(); it != accounts.end(); it++) {
        accountVector.push_back(it->first);
    }

    return accountVector;
}

int BankUserDev::getAccountBalance(const std::string& accountName) {
    // iterate accounts map
    for(auto it = accounts.begin(); it != accounts.end(); it++) {
        if (it->first == accountName) {
            return it->second;
        }
    }

    // if account not found
    return 0;
}

// depositMoney
void BankUserDev::depositMoney(const std::string& accountName, size_t moneyAmount) {
    // iterate accounts map
    for(auto it = accounts.begin(); it != accounts.end(); it++) {
        if (it->first == accountName) {
            it->second += (int) moneyAmount;
        }
    }
}

// withdrawMoney
void BankUserDev::withdrawMoney(const std::string& accountName, size_t moneyAmount) {
    // iterate accounts map
    for(auto it = accounts.begin(); it != accounts.end(); it++) {
        if (it->first == accountName) {
            it->second -= (int) moneyAmount;
        }
    }
}

bool BankUserDev::addNewAccount(const std::string& accountName, int initialDeposit) {
    // check for duplicate return false if so
    for(auto it = accounts.begin(); it != accounts.end(); it++) {
        if (it->first == accountName) {
            return false;
        }
    }

    accounts.insert(std::pair<std::string, int>(accountName, initialDeposit) );
    return true;
}

bool BankUserDev::removeExistingAccount(const std::string& accountName) {
    size_t erased = accounts.erase(accountName);

    if (erased == 1) {
        return true;    // account found and erased
    } else {
        return false;   // account not found
    }
}

bool BankUserDev::authenticateUser(const std::string& userCardNumber, const std::vector<size_t>& userPin) {
    return (userCardNumber == cardNumber && userPin == pin);
}
