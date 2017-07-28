//
// Created by Alan on 11/08/2016.
//
#pragma once
#ifndef PCPP_ASSIGNMENT_ADMIN_H
#define PCPP_ASSIGNMENT_ADMIN_H

#include "PurchaseManager.h"

class admin: public SalesManager, public PurchaseManager  {

private:
    std::string username = "root";
    std::string password = "root";
    void registerUser();

    void registerSm();

    void registerPm();

    void logout();

    std::vector<SalesManager> *salesManagers = new std::vector<SalesManager>();
    std::vector<PurchaseManager> *purchaseManagers = new std::vector<PurchaseManager>();
protected:
    virtual void createPO();

    virtual void displayItems();

    virtual void displaySuppliers();

    virtual void itemEntry();

    virtual void addItem();

    virtual void deleteItem();

    virtual void editItem();

    virtual void supplierEntry();

    virtual void addSupplier();

    virtual void deleteSupplier();

    virtual void editSupplier();

    virtual void dailySalesEntry();

    virtual void createPR();

    virtual void displayPRs();

    virtual void displayPOs();

public:
    void login();

    admin();

    void menu();

    const std::string &getUsername() const;

    const std::string &getPassword() const;
};


#endif //PCPP_ASSIGNMENT_ADMIN_H
