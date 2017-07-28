#include <stdio.h>
#include "PurchaseManager.h"
using namespace std;

PurchaseManager::PurchaseManager(int id, const std::string &name) : id(id), name(name) {}

const std::string &PurchaseManager::getPassword() const {
    return password;
}

void PurchaseManager::setPassword(const std::string &password) {
    PurchaseManager::password = password;
}

int PurchaseManager::getId() const {
    return id;
}

void PurchaseManager::setId(int id) {
    PurchaseManager::id = id;
}

const std::string &PurchaseManager::getName() const {
    return name;
}

void PurchaseManager::setName(const std::string &name) {
    PurchaseManager::name = name;
}

void PurchaseManager::menu() {
    cout << endl;
    cout << "Signed as Purchase Manager" << endl;
    cout << endl;
    cout << "1. Create Purchase Order" << endl;
    cout << "2. Display Items" << endl;
    cout << "3. Display Suppliers" << endl;
    cout << "4. Display Requisitions" << endl;
    cout << "5. Display Purchase Orders" << endl;
    cout << "0. Log out" << endl;

    int i;
    cout << "Enter the number: ";
    cin >> i;
    cout << endl;
    if (i == 1) {
        createPO();
        menu();
    }
    else if (i == 2) displayItems();
    else if (i == 3) displaySuppliers();
    else if (i == 4) displayPRs();
    else if (i == 5) displayPOs();
    else if (i == 0) logout();
    else menu();
}

void PurchaseManager::createPO() {
    int poID;
    int choose;

    cout << endl << "Pending Purchase Requisitions";

    displayPRs();

    cout << endl << "Choose Purchase Requisition to approve: ";
    cin >> choose;

    cout << "Chosen Purchase Requisition ID - " << salesManager.getPurchaseRequisitions()->at(choose - 1).getId() << endl;
    cout << endl;

    cout << endl << "Enter Purchase Order ID: ";
    cin >> poID;
    string purchaseManager = "ID" + to_string(this->getId()) + ", " + this->getName();
    int prID = salesManager.getPurchaseRequisitions()->at(choose - 1).getId();
    PurchaseOrder *purchaseOrder = new PurchaseOrder(poID, purchaseManager, prID);

    cout << endl << "Purchase Order was created"
         << endl << "Purchase Order ID - " << purchaseOrder->getID()
         << endl << "Purchase Requisition ID - " << purchaseOrder->getPrID()
         << endl << "Purchase Order is created by Purchase Manager - ID" << this->getId() << ", " << this->getName();
}

void PurchaseManager::displayItems() {
    for (unsigned int i = 0; i < salesManager.getItems()->size(); ++i) {
        cout << i + 1 << ". ID - " << salesManager.getItems()->at(i).getId()
             << ". Name - " << salesManager.getItems()->at(i).getName()
             << ". Quantity - " << salesManager.getItems()->at(i).getQuantity()
             << ". Supplier - " << salesManager.getItems()->at(i).getSupplier() << endl;
    }
    menu();
}

void PurchaseManager::displaySuppliers() {
    for (unsigned int i = 0; i < salesManager.getSuppliers()->size(); ++i) {
        cout << i + 1 << ". ID: " << salesManager.getSuppliers()->at(i).getId() << ". Name: "
             << salesManager.getSuppliers()->at(i).getName() << endl;
    }
    menu();
}

void PurchaseManager::displayPRs() {
    for (unsigned int i = 0; i < salesManager.getPurchaseRequisitions()->size(); ++i) {
        cout << endl
             << endl << "Purchase Requisition ID - " << salesManager.getPurchaseRequisitions()->at(i).getId()
             << endl << "Item - ID" << salesManager.getPurchaseRequisitions()->at(i).getItem()
             << endl << "Quantity asked - " << salesManager.getPurchaseRequisitions()->at(i).getNeededQuantity()
             << endl << "Created by Sales Manager - ID" << salesManager.getPurchaseRequisitions()->at(i).getSalesManager() << endl;
    }
    menu();
}

void PurchaseManager::displayPOs() {
    for (unsigned int i = 0; i < salesManager.getPurchaseOrders()->size(); ++i) {
        cout << endl
             << endl << "Purchase Order ID - " << salesManager.getPurchaseOrders()->at(i).getID()
             << endl << "Purchase Requisition ID - " << salesManager.getPurchaseOrders()->at(i).getPrID()
             << endl << "Approved by Purchase Manager - ID" << salesManager.getPurchaseOrders()->at(i).getPurchaseManager();
    }
    menu();
}

void PurchaseManager::logout() {
    loginStatus = true;
}

bool PurchaseManager::isLoginStatus() const {
    return loginStatus;
}

void PurchaseManager::setLoginStatus(bool loginStatus) {
    PurchaseManager::loginStatus = loginStatus;
}



const SalesManager &PurchaseManager::getSalesManager() const {
    return salesManager;
}

void PurchaseManager::setSalesManager(const SalesManager &salesManager) {
    PurchaseManager::salesManager = salesManager;
}




