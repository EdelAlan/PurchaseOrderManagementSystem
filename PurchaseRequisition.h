//
// Created by Alan on 11/08/2016.
//
#pragma once
#ifndef PCPP_ASSIGNMENT_PURCHASEREQUISITION_H
#define PCPP_ASSIGNMENT_PURCHASEREQUISITION_H

#include <string>

class PurchaseRequisition {
private:
    int id;
    std::string item;
    std::string salesManager;
    int neededQuantity;
public:
    PurchaseRequisition(int id, const std::string &item, const std::string &salesManager, int neededQuantity);

    int getId() const;

    void setId(int id);

    int getNeededQuantity() const;

    void setNeededQuantity(int neededQuantity);

    const std::string &getSalesManager() const;

    void setSalesManager(const std::string &salesManager);

    const std::string &getItem() const;

    void setItem(const std::string &item);
};


#endif //PCPP_ASSIGNMENT_PURCHASEREQUISITION_H
