#include "CashBinDev.h"

// Constructor
CashBinDev::CashBinDev() : billsInBin(0)
{}

CashBinDev::CashBinDev(size_t billsAtStartup) : billsInBin(billsAtStartup)
{}

size_t CashBinDev::billCounterHWDev() {
    return billsInBin;
}

bool CashBinDev::isEnoughBills(size_t cashAmount) {
    billsInBin = billCounterHWDev();
    return (cashAmount <= billsInBin);
}

size_t CashBinDev::removeBills(size_t cashAmount) {
    if (isEnoughBills(cashAmount)) {
        billsInBin -= cashAmount;
        return cashAmount;
    } else {
        // remove as much bills as possible
        size_t cashWithdrawn = billsInBin;
        billsInBin = 0;
        return cashWithdrawn;
    }
}

void CashBinDev::addBills(size_t cashAmount) {
    billsInBin += cashAmount;
}
