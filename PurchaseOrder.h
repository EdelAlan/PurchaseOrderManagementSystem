//
// Created by Alan on 11/08/2016.
//
#pragma once
#ifndef PCPP_ASSIGNMENT_PURCHASEORDER_H
#define PCPP_ASSIGNMENT_PURCHASEORDER_H

#include <string>

class PurchaseOrder {
private:
    int ID;
    std::string purchaseManager;
    int prID;
public:
    PurchaseOrder(int ID, const std::string &purchaseManager, int prID);

    int getID() const;

    void setID(int ID);

    const std::string &getPurchaseManager() const;

    void setPurchaseManager(const std::string &purchaseManager);

    int getPrID() const;

    void setPrID(int prID);
};


#endif //PCPP_ASSIGNMENT_PURCHASEORDER_H
