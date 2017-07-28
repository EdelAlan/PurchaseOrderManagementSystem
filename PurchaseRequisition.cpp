//
// Created by Alan on 11/08/2016.
//

#include <stdio.h>
#include "PurchaseRequisition.h"

int PurchaseRequisition::getId() const {
    return id;
}

void PurchaseRequisition::setId(int id) {
    PurchaseRequisition::id = id;
}

int PurchaseRequisition::getNeededQuantity() const {
    return neededQuantity;
}

void PurchaseRequisition::setNeededQuantity(int neededQuantity) {
    PurchaseRequisition::neededQuantity = neededQuantity;
}

const std::string &PurchaseRequisition::getSalesManager() const {
    return salesManager;
}

void PurchaseRequisition::setSalesManager(const std::string &salesManager) {
    PurchaseRequisition::salesManager = salesManager;
}

PurchaseRequisition::PurchaseRequisition(int id, const std::string &item, const std::string &salesManager,
                                         int neededQuantity) : id(id), item(item), salesManager(salesManager),
                                                               neededQuantity(neededQuantity) {}

const std::string &PurchaseRequisition::getItem() const {
    return item;
}

void PurchaseRequisition::setItem(const std::string &item) {
    PurchaseRequisition::item = item;
}


