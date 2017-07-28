#include <stdio.h>
#include "admin.h"

using namespace std;

void admin::menu() {
    std::cout << "Signed as Admin" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Item Entry" << std::endl;
    std::cout << "2. Supplier Entry" << std::endl;
    std::cout << "3. Daily Sales Entry" << std::endl;
    std::cout << "4. Create a Purchase Requisition" << std::endl;
    std::cout << "5. Display Requisitions" << std::endl;
    std::cout << "6. Display Purchase Orders" << std::endl;
    std::cout << "7. Display Items" << std::endl;
    std::cout << "8. Display Suppliers" << std::endl;
    std::cout << "9. Register New User" << std::endl;
    std::cout << "0. Log out" << std::endl;

    int i;
    std::cout << "Enter the number: ";
    std::cin >> i;
    std::cout << std::endl;
    if (i == 1) itemEntry();
    else if (i == 2) supplierEntry();
    else if (i == 3) dailySalesEntry();
    else if (i == 4) createPR();
    else if (i == 5) displayPRs();
    else if (i == 6) displayPOs();
    else if (i == 7) displayItems();
    else if (i == 8) displaySuppliers();
    else if (i == 9) registerUser();
    else if (i == 0) logout();
    else menu();
}

admin::admin() {}

const std::string &admin::getUsername() const {
    return username;
}

const std::string &admin::getPassword() const {
    return password;
}

void admin::createPO() {
    PurchaseManager::createPO();
    menu();
}

void admin::displayItems() {
    for (unsigned int i = 0; i < salesManager.getItems()->size(); ++i) {
        cout << i + 1 << ". ID - " << salesManager.getItems()->at(i).getId()
             << ". Name - " << salesManager.getItems()->at(i).getName()
             << ". Quantity - " << salesManager.getItems()->at(i).getQuantity()
             << ". Supplier - " << salesManager.getItems()->at(i).getSupplier() << endl;
    }
    menu();
}

void admin::displaySuppliers() {
    for (unsigned int i = 0; i < salesManager.getSuppliers()->size(); ++i) {
        cout << i + 1 << ". ID: " << salesManager.getSuppliers()->at(i).getId() << ". Name: "
             << salesManager.getSuppliers()->at(i).getName() << endl;
    }
    menu();
}

void admin::itemEntry() {
    cout << "Item Entry Menu" << endl;
    cout << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Delete Item" << endl;
    cout << "3. Edit Item" << endl;
    cout << "0. Exit to Main Menu" << endl;

    int i;
    cout << "Enter the number: ";
    cin >> i;
    if (i == 1) addItem();
    else if (i == 2) deleteItem();
    else if (i == 3) editItem();
    else if (i == 0) menu();
    else itemEntry();
}

void admin::addItem() {
    SalesManager::addItem();
}

void admin::deleteItem() {
    SalesManager::deleteItem();
}

void admin::editItem() {
    SalesManager::editItem();
}

void admin::supplierEntry() {
    cout << "Supplier Entry Menu" << endl;
    cout << endl;
    cout << "1. Add Supplier" << endl;
    cout << "2. Delete Supplier" << endl;
    cout << "3. Edit Supplier" << endl;
    cout << "0. Exit to Main Menu" << endl;

    int i;
    cout << "Enter the number: ";
    cin >> i;
    if (i == 1) addSupplier();
    else if (i == 2) deleteSupplier();
    else if (i == 3) editSupplier();
    else if (i == 0) menu();
    else supplierEntry();
}

void admin::addSupplier() {
    SalesManager::addSupplier();
}

void admin::deleteSupplier() {
    SalesManager::deleteSupplier();
}

void admin::editSupplier() {
    SalesManager::editSupplier();
}

void admin::dailySalesEntry() {
    int id;
    int quantity;

    cout << "Daily Sales Entry Menu" << endl;
    cout << endl;
    cout << "Enter id: " << endl;
    cin >> id;
    cout << "Enter quantity: " << endl;
    cin >> quantity;

    int choose;

    for (unsigned int i = 0; i < items->size(); ++i) {
        cout << i + 1 << ". ID - " << items->at(i).getId()
             << ". Name - " << items->at(i).getName()
             << ". Quantity - " << items->at(i).getQuantity()
             << ". Supplier - " << items->at(i).getSupplier() << endl;
    }

    cout << endl;
    cout << "Enter item's number: ";
    cin >> choose;

    cout << endl;

    if (quantity < 0) {
        cout << "Wrong input" << endl;
        menu();
    } else {
        items->at(choose - 1).setQuantity(items->at(choose - 1).getQuantity() - quantity);
        cout << "Item - " << items->at(choose - 1).getName() << endl
             << "New quantity - " << items->at(choose - 1).getQuantity() << endl;
    }
    DailyItemWise *dailyItemWise = new DailyItemWise(id, quantity);
    dailyItemWises->push_back(*dailyItemWise);
    menu();
}

void admin::createPR() {
    SalesManager::createPR();
    menu();
}

void admin::displayPRs() {
    for (unsigned int i = 0; i < purchaseRequisitions->size(); ++i) {
        cout << endl
             << endl << "Purchase Requisition ID - " << purchaseRequisitions->at(i).getId()
             << endl << "Item - ID" << purchaseRequisitions->at(i).getItem()
             << endl << "Quantity asked - " << purchaseRequisitions->at(i).getNeededQuantity()
             << endl << "Created by Sales Manager - ID" << purchaseRequisitions->at(i).getSalesManager() << endl;
    }
    menu();
}

void admin::displayPOs() {
    for (unsigned int i = 0; i < purchaseOrders->size(); ++i) {
        cout << endl
             << endl << "Purchase Order ID - " << purchaseOrders->at(i).getID()
             << endl << "Purchase Requisition ID - " << purchaseOrders->at(i).getPrID()
             << endl << "Approved by Purchase Manager - ID" << purchaseOrders->at(i).getPurchaseManager();
    }
    menu();
}

void admin::logout() {
    login();
}

void admin::registerUser() {
    std::cout << "Register Menu" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Register Sales Manager" << std::endl;
    std::cout << "2. Register Purchase Manager" << std::endl;
    std::cout << "0. Menu" << std::endl;

    int i;
    std::cout << "Enter the number: ";
    std::cin >> i;
    std::cout << std::endl;
    if (i == 1) registerSm();
    else if (i == 2) registerPm();
    else menu();
}

void admin::registerPm() {
    std::string null = "0";
    int id;
    std::string name;
    std::string password;

    std::cout << std::endl;

    std::cout << "Enter Purchase Manager's ID, enter 0 to exit: ";
    std::cin >> id;
    if (id == 0) { registerUser(); }
    else {
        for (unsigned int i = 0; i < purchaseManagers->size(); ++i) {
            if (purchaseManagers->at(i).getId() == id) {
                std::cout << std::endl << " Purchase Manager with such Id already exists" << std::endl;
                registerUser();
                break;
            } else continue;
        }
        std::cout << std::endl;
        std::cout << "Enter Purchase Manager's name, enter 0 to exit: ";
        std::cin >> name;
        if (name == null) { registerUser(); }
        else {
            for (unsigned int i = 0; i < purchaseManagers->size(); ++i) {
                if (purchaseManagers->at(i).getName() == name) {
                    std::cout << " Purchase Manager with such name already exists" << std::endl;
                    registerUser();
                    break;
                } else continue;
            }

            std::cout << "Create password: ";
            std::cin >> password;
            std::cout << std::endl;

            PurchaseManager *purchaseManager = new PurchaseManager(id, name, password);
            purchaseManagers->push_back(*purchaseManager);

            std::cout << std::endl << "New Purchase Manager was saved"
                 << std::endl << "ID: " << id
                 << std::endl << "Name: " << name << std::endl;
            registerUser();
        }
    }
}

void admin::registerSm() {
    std::string null = "0";
    int id;
    std::string name;
    std::string password;

    std::cout << std::endl;

    std::cout << "Enter Sales Manager's ID, enter 0 to exit: ";
    std::cin >> id;
    if (id == 0) { registerUser(); }
    else {
        for (unsigned int i = 0; i < salesManagers->size(); ++i) {
            if (salesManagers->at(i).getId() == id) {
                std::cout << std::endl << " Sales Manager with such Id already exists" << std::endl;
                registerUser();
                break;
            } else continue;
        }
        std::cout << std::endl;
        std::cout << "Enter Sales Manager's name, enter 0 to exit: ";
        std::cin >> name;
        if (name == null) { registerUser(); }
        else {
            for (unsigned int i = 0; i < salesManagers->size(); ++i) {
                if (salesManagers->at(i).getName() == name) {
                    std::cout << " Sales Manager with such name already exists" << std::endl;
                    registerUser();
                    break;
                } else continue;
            }

            std::cout << "Create password: ";
            std::cin >> password;
            std::cout << std::endl;

            SalesManager *salesManager = new SalesManager(id, name, password);
            salesManagers->push_back(*salesManager);

            std::cout << std::endl << "New Sales Manager was saved"
                      << std::endl << "ID: " << id
                      << std::endl << "Name: " << name << std::endl;
            registerUser();
        }
    }
}

void admin::login() {
    std::string username;
    std::string password;

    std::cout << std::endl << "Login Menu" << std::endl;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (username == this->getUsername() && password == this->getPassword()) {
        this->menu();
    }

    for (unsigned int i = 0; i < purchaseManagers->size(); ++i) {
        if (username == purchaseManagers->at(i).getName() && password == purchaseManagers->at(i).getPassword()) {
            purchaseManagers->at(i).menu();

        }
    }

    for (unsigned int i = 0; i < salesManagers->size(); ++i) {
        if (username == salesManagers->at(i).getName() && password == salesManagers->at(i).getPassword()) {
                salesManagers->at(i).menu();
        } else if (username == this->getUsername() && password == this->getPassword()) {
            this->menu();
        }
    }
    std::cout << "wrong input" << std::endl;
    login();
}
