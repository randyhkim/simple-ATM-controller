#include "BankSystemDev.h"

BankUserDev* BankSystemDev::authenticateUser(const std::string& cardNumber, const std::vector<size_t>& userPin) {

    // find user
    for (size_t i = 0; i < userVector.size(); i++) {
        if (userVector[i].authenticateUser(cardNumber, userPin)) {

            return &userVector[i];
        }
    }

    // user not found
    return nullptr;
}


BankSystemDev::BankSystemDev() : loggedInUser(nullptr)
{}

bool BankSystemDev::addNewUser(const std::string& nameInput, const std::string& accountName,
                               int initialDeposit, const std::string& cardNumber, const std::vector<size_t>& pinInput) {
    // search for duplicate user by checking card number
    for (size_t i = 0; i < userVector.size(); i++) {
        if (userVector[i].getCardNumber() == cardNumber) {
            return false;
        }
    }

    BankUserDev user = BankUserDev(nameInput, accountName, initialDeposit, cardNumber, pinInput);
    userVector.push_back(user);
    return true;
}

bool BankSystemDev::removeUser(const std::string& cardNumber) {
    for (auto it = userVector.begin(); it != userVector.end(); it++) {
        if (it->getCardNumber() == cardNumber) {
            userVector.erase(it);
            return true;
        }
    }

    // user not found
    return false;
}

bool BankSystemDev::userLogIn(const std::string& cardNumber, const std::vector<size_t>& userPin) {
    loggedInUser = authenticateUser(cardNumber, userPin);

    return (loggedInUser != nullptr);
}

void BankSystemDev::userLogOut() {
    loggedInUser = nullptr;
}

bool BankSystemDev::isUserLoggedIn() {
    return (loggedInUser != nullptr);
}

std::string BankSystemDev::getUserName() {
    return loggedInUser->getUserName();
}

void BankSystemDev::changeUserName(const std::string& newName) {
    loggedInUser->changeUserName(newName);
}

void BankSystemDev::changePinNumber(const std::vector<size_t>& newPin) {
    loggedInUser->changePinNumber(newPin);
}

void BankSystemDev::changeCardNumber(const std::string& newCardNumber) {
    loggedInUser->changeCardNumber(newCardNumber);
}

std::vector<std::string> BankSystemDev::getAccounts() {
    return loggedInUser->getAccounts();
}

int BankSystemDev::getAccountBalance(const std::string& accountName) {
    return loggedInUser->getAccountBalance(accountName);
}

void BankSystemDev::depositMoney(const std::string& accountName, size_t moneyAmount) {
    loggedInUser->depositMoney(accountName, moneyAmount);
}

void BankSystemDev::withdrawMoney(const std::string& accountName, size_t moneyAmount) {
    loggedInUser->withdrawMoney(accountName, moneyAmount);
}

bool BankSystemDev::addNewAccount(const std::string& accountName, int initialDeposit) {
    return loggedInUser->addNewAccount(accountName, initialDeposit);
}

bool BankSystemDev::removeExistingAccount(const std::string& accountName) {
    return loggedInUser->removeExistingAccount(accountName);
}

