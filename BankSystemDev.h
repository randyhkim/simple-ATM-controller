#ifndef SIMPLE_ATM_CONTROLLER_BANKSYSTEMDEV_H
#define SIMPLE_ATM_CONTROLLER_BANKSYSTEMDEV_H

#include "BankUserDev.h"

// BankSystemDev
// Contains multiple users, represented by BankUserDev objects
// Checks if information like PIN sent from ATMController is correct and returns
// user data back to the ATMController
class BankSystemDev {
private:

    std::vector<BankUserDev> userVector;
    BankUserDev* loggedInUser;

    BankUserDev* authenticateUser(const std::string& cardNumber, const std::vector<size_t>& userPin);

public:

    // Constructor
    BankSystemDev();

    // addUser
    // add BankUserDev object to BankSystemDev
    // returns true if successful, false if not
    bool addNewUser(const std::string& nameInput, const std::string& accountName,
                    int initialDeposit, const std::string& cardNumber, const std::vector<size_t>& pinInput);

    // removeUser
    // removes exiting user from system
    // returns true if successful, false if not
    bool removeUser(const std::string& cardNumber);

    // userLogIn
    // checks if user CardNumber and PIN is correct and logs user in
    // sets loggedInUser pointer to that user and loggedIn as true
    // retuns true if successful, false if not
    bool userLogIn(const std::string& cardNumber, const std::vector<size_t>& userPin);

    // userLogOUt
    // removes pointer to loggedInUser immediately
    void userLogOut();

    // isUserLoggedIn
    // checks if user is currently logged in
    bool isUserLoggedIn();

    // the following functions only work when user is logged in, and will cause error if
    // called when logged out (nullptr call)
    // getUserName
    // returns user name
    std::string getUserName();

    // changeUserName
    // changes userName to newName
    void changeUserName(const std::string& newName);

    // changePinNumber
    // changes pin to newPin
    void changePinNumber(const std::vector<size_t>& newPin);

    // changeCardNumber
    // changes cardNumber to newCardNumber
    void changeCardNumber(const std::string& newCardNumber);

    // getAccounts
    // Returns vector of all accounts of this user
    std::vector<std::string> getAccounts();

    // getAccountBalance
    int getAccountBalance(const std::string& accountName);

    // depositMoney
    void depositMoney(const std::string& accountName, size_t moneyAmount);

    // withdrawMoney
    void withdrawMoney(const std::string& accountName, size_t moneyAmount);

    // addNewAccount
    // Adds new account to accounts map.
    // If successful, returns true. If error, returns false.
    bool addNewAccount(const std::string& accountName, int initialDeposit);

    // removeExistingAccount
    // Removes exsiting account from accounts map.
    // If successful, returns true. If error, returns false.
    bool removeExistingAccount(const std::string& accountName);
};


#endif //SIMPLE_ATM_CONTROLLER_BANKSYSTEMDEV_H