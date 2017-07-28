//
// Created by Alan on 11/08/2016.
//
#pragma once
#ifndef PCPP_ASSIGNMENT_PURCHASEMANAGER_H
#define PCPP_ASSIGNMENT_PURCHASEMANAGER_H

#include <vector>
#include "SalesManager.h"

class PurchaseManager {
private:
    bool loginStatus;

    int id;
    std::string name;
    std::string password;
protected:
    virtual void createPO();

    virtual void displayItems();

    virtual void displaySuppliers();
    void displayPRs();
    void displayPOs();

    void logout();
public:
    SalesManager salesManager;

    void menu();

    PurchaseManager();

    PurchaseManager(int id, const std::string &name);

    PurchaseManager(int id, const std::string &name, const std::string &password);

    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    virtual const std::string &getPassword() const;

    bool isLoginStatus() const;

    void setLoginStatus(bool loginStatus);

    void setPassword(const std::string &password);

    const SalesManager &getSalesManager() const;

    void setSalesManager(const SalesManager &salesManager);
};


#endif //PCPP_ASSIGNMENT_PURCHASEMANAGER_H
