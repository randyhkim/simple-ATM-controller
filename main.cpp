#include <iostream>
#include "ATMController.h"
#include "BankSystemDev.h"

// size_t DEBUG = 1;
std::string testCardNumber = "1234000056780000";
std::vector<size_t>testPin = {1, 2, 3, 4};

// Enter your test card number and pin here
std::string yourName = "Your Name";
std::string yourCardNumber = "1111222233334444";
int yourDeposit = 10000;
std::vector<size_t>yourPin = {2, 0, 2, 1};

int main() {

    // Create BankSystem
    BankSystemDev bankSystem;

    // Add test user
    bankSystem.addNewUser("Randy Kim", "Default", 1000, testCardNumber, testPin);
    bankSystem.addNewUser(yourName, "Default", yourDeposit, yourCardNumber, yourPin);

    // Test user log in
    bankSystem.userLogIn(testCardNumber, testPin);
    bankSystem.addNewAccount("Savings", 10000);

    // print accounts
//    std::cout << "Account List under " << bankSystem.getUserName() << ":\n";
//    std::vector<std::string> accounts = bankSystem.getAccounts();
//    for (size_t i = 0; i < accounts.size(); i++) {
//        std::cout << "\t" << i + 1 << ". " << accounts[i] << "\n";
//    }
//    std::cout << "\n";

    // Test user logout
    bankSystem.userLogOut();

    // Create ATM Controller
    ATMController atm = ATMController(bankSystem, 10000);

    // Call ATM Controller Main Loop
    return atm.ATMControllerMainProcess();

}
