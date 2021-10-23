#ifndef SIMPLE_ATM_CONTROLLER_ATMDISPLAYMANAGERDEV_H
#define SIMPLE_ATM_CONTROLLER_ATMDISPLAYMANAGERDEV_H

#include <string>
#include <vector>
#include <iostream>
#include <thread>

class ATMDisplayManagerDev {
private:

    bool showDevMessage;
    std::vector<std::string> screenVector;

    void printScreenVector();
    void resetScreenVector();
    void printNewLines();
    void addDevMessage(const std::string& message);

    std::string topBottomRow =  "+------------------------------------------------------------------------------+\n";
    std::string blankRow =      "|                                                                              |\n";
    std::string devRow =        "| DEV MESSAGE:                                                                 |\n";
    std::string atm =           "|                                 Simple ATM                                   |\n";
    std::string atmDevMode =    "|                             Simple ATM DEV MODE                              |\n";
    std::string welcome =       "|                                  Welcome!                                    |\n";
    std::string error =         "|                 Fatal error. Please contact customer service.                |\n";
    std::string enterCardNum =  "|                Insert Card to use service (enter card number)                |\n";
    std::string readingCard =   "|            Reading card information... Please wait for a moment.             |\n";
    std::string cardInserted =  "|                           Card has been inserted                             |\n";
    std::string enterPinNum =   "|        Enter PIN Number for authentication (Press 'Enter' when done)         |\n";
    std::string selectAccount = "|           Select account by pressing number and 'Enter' when done            |\n";
    std::string deposit       = "|   1. Deposit                                                                 |\n";
    std::string withdraw      = "|   2. Withdraw                                                                |\n";
    std::string goBack       =  "|   3. Exit and Leave                                                          |\n";
    std::string thankYou     =  "|                       Thank you for using Simple ATM                         |\n";
    std::string takeCard     =  "|                          Card Ejected. Take Card!                            |\n";
    std::string notAuth =       "|           Card number or PIN not authenticated. Please try again.            |\n";

public:

    // Constructor
    // showDevMessage false by default
    ATMDisplayManagerDev();

    // devModeOn
    // Turns dev mode on and shows dev messages
    void devModeOn();

    // devModeOff
    // Turns dev mode off and does not show dev messages
    void devModeOff();

    // draws welcome screen
    void drawWelcomeScreen();

    // reading card screen
    void drawCardReadScreen();

    // drawn when card reading complete. Prompts user for PIN input
    void drawEnterPINScreen();

    // drawn when authentication succeeded. Prompts user for account selection.
    void drawSelectAccountScreen(const std::string& userName, const std::vector<std::string>& accounts);

    // drawn when account selection complete. Prompts user for action selection
    void drawBalanceDepositWithdrawScreen(const std::string& account, int balance);

    void drawDepositScreen();

    void drawWithdrawScreen();

    void drawNotEnoughBillsScreen();

    // user not authenticated
    void drawNotAuthenticated();

    // user exits ATM
    void drawExitScreen();

    // fatal error in system. Drawn before system closes
    void drawErrorScreen();
};


#endif //SIMPLE_ATM_CONTROLLER_ATMDISPLAYMANAGERDEV_H
