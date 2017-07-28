//
// Created by Alan on 11/08/2016.
//
#pragma once
#ifndef PCPP_ASSIGNMENT_SALESMANAGER_H
#define PCPP_ASSIGNMENT_SALESMANAGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include "Supplier.h"
#include "Item.h"
#include "PurchaseOrder.h"
#include "PurchaseRequisition.h"
#include "DailyItemWise.h"


class SalesManager {
private:
    int id;
    std::string name;
    std::string password;
public:
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

    virtual void logout();

    virtual void menu();

    SalesManager(int id, const std::string &name);

    SalesManager(int id, const std::string &name, const std::string &password);

    SalesManager();

    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    const std::string &getPassword() const;

    void setName(const std::string &name);

    void setPassword(const std::string &password);

    std::vector<Item> *getItems() const;

    void setItems(std::vector<Item> *items);

    std::vector<Supplier> *getSuppliers() const;

    void setSuppliers(std::vector<Supplier> *suppliers);

    std::vector<PurchaseOrder> *getPurchaseOrders() const;

    void setPurchaseOrders(std::vector<PurchaseOrder> *purchaseOrders);

    std::vector<PurchaseRequisition> *getPurchaseRequisitions() const;

    void setPurchaseRequisitions(std::vector<PurchaseRequisition> *purchaseRequisitions);

    std::vector<DailyItemWise> *getDailyItemWises() const;

    void setDailyItemWises(std::vector<DailyItemWise> *dailyItemWises);

protected:
    std::vector<Item> *items = new std::vector<Item>();
    std::vector<Supplier> *suppliers = new std::vector<Supplier>();
    std::vector<PurchaseOrder> *purchaseOrders = new std::vector<PurchaseOrder>();
    std::vector<PurchaseRequisition> *purchaseRequisitions = new std::vector<PurchaseRequisition>();
    std::vector<DailyItemWise> *dailyItemWises = new std::vector<DailyItemWise>();
};


#endif //PCPP_ASSIGNMENT_SALESMANAGER_H
