//
// Created by Alan on 11/08/2016.
//

#include <stdio.h>
#include "PurchaseOrder.h"

int PurchaseOrder::getID() const {
    return ID;
}

void PurchaseOrder::setID(int ID) {
    PurchaseOrder::ID = ID;
}

const std::string &PurchaseOrder::getPurchaseManager() const {
    return purchaseManager;
}

void PurchaseOrder::setPurchaseManager(const std::string &purchaseManager) {
    PurchaseOrder::purchaseManager = purchaseManager;
}

PurchaseOrder::PurchaseOrder(int ID, const std::string &purchaseManager, int prID) : ID(ID),
                                                                                     purchaseManager(purchaseManager),
                                                                                     prID(prID) {}


int PurchaseOrder::getPrID() const {
    return prID;
}

void PurchaseOrder::setPrID(int prID) {
    PurchaseOrder::prID = prID;
}
