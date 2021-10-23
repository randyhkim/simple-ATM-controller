#ifndef SIMPLE_ATM_CONTROLLER_CASHBINDEV_H
#define SIMPLE_ATM_CONTROLLER_CASHBINDEV_H

#include <cstddef>

class CashBinDev {
private:

    size_t billsInBin;  // number of $1 bills - for  production, would have to implement other "bins" for different bills

public:

    // Default Constructor
    CashBinDev();

    // Constructor
    // For production, bin sensor will count number of bills put in at ATM startup
    CashBinDev(size_t billsAtStartup);

    // getNumBills
    // Gets number of bills currently in bin. For prodution, biill counter in bin HW function
    // would be called instead.
    size_t billCounterHWDev();

    // isEnoughBills
    // Checks if there are enough bills in the bin for next transaction (i.e. withdraw)
    bool isEnoughBills(size_t cashAmount);

    // removeBills
    // Removes bills in bin. Returns number of bills removed.
    size_t removeBills(size_t cashAmount);

    // addBills
    // Adds bills deposited by user. For production, function for deposit cash counter HW would
    // also be called
    void addBills(size_t cashAmount);

};


#endif //SIMPLE_ATM_CONTROLLER_CASHBINDEV_H