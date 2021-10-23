#ifndef SIMPLE_ATM_CONTROLLER_BANKUSERDEV_H
#define SIMPLE_ATM_CONTROLLER_BANKUSERDEV_H

#include <string>
#include <map>
#include <vector>

// BankUserDev
// Object containing user information like name, card number, PIN, accounts and their balances
class BankUserDev {
private:

    // For production, must use more secure data structure!!!
    // For dev purpose only
    std::string userName;
    std::map<std::string, int> accounts;
    std::string cardNumber;
    std::vector<size_t> pin;

public:

    // Default Constructor
    BankUserDev();

    // Alternate Constructor
    BankUserDev(const std::string& nameInput, const std::string& accountName,
                int initialDeposit, const std::string& userCardNumber, const std::vector<size_t>& pinInput);

    // getUserName
    // return user name
    std::string getUserName();

    // getCardNumber
    // returns card number
    std::string getCardNumber();

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

    // authenticateUser
    // Checks if card number and PIN matches.
    // If so, returns true. If not, returns false.
    bool authenticateUser(const std::string& inputCardNumber, const std::vector<size_t>& userPin);

};


#endif //SIMPLE_ATM_CONTROLLER_BANKUSERDEV_H
