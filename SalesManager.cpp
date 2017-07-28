#include <stdio.h>
#include "SalesManager.h"

using namespace std;

void SalesManager::menu() {
    cout << "Signed as Sales Manager" << endl;
    cout << endl;
    cout << "1. Item Entry" << endl;
    cout << "2. Supplier Entry" << endl;
    cout << "3. Daily Sales Entry" << endl;
    cout << "4. Create a Purchase Requisition" << endl;
    cout << "5. Display Requisitions" << endl;
    cout << "6. Display Purchase Orders" << endl;
    cout << "0. Log out" << endl;

    int i;
    cout << "Enter the number: ";
    cin >> i;
    cout << endl;
    if (i == 1) itemEntry();
    else if (i == 2) supplierEntry();
    else if (i == 3) dailySalesEntry();
    else if (i == 4) createPR();
    else if (i == 5) displayPRs();
    else if (i == 6) displayPOs();
    else if (i == 0) logout();
    else menu();
};

void SalesManager::itemEntry() {
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

void SalesManager::addItem() {
    string null = "0";
    string name;
    int itemId;
    int itemQuantity;
    int supplier;

    cout << endl;

    cout << "Enter item ID, enter 0 to exit: ";
    cin >> itemId;
    if (itemId == 0) { itemEntry(); }
    else {
        for (unsigned int i = 0; i < items->size(); ++i) {
            if (items->at(i).getId() == itemId) {
                cout << endl << " Item with such Id already exists" << endl;
                addItem();
                break;
            } else continue;
        }
        cout << endl;
        cout << "Enter item name, enter 0 to exit: ";
        cin >> name;
        if (name == null) { itemEntry(); }
        else {
            cout << endl;
            cout << "Enter item quantity: ";
            cin >> itemQuantity;
            if (itemQuantity < 0) {
                cout << "Wrong input" << endl;
                addItem();
            } else {
                for (unsigned int i = 0; i < items->size(); ++i) {
                    if (items->at(i).getName() == name) {
                        cout << " Item with such name already exists" << endl;
                        addItem();
                        break;
                    } else continue;
                }
                cout << endl;
                cout << "Choose supplier, enter 999 to create new supplier for this item, enter 0 to exit: " << endl;
                for (unsigned int i = 0; i < suppliers->size(); ++i) {
                    cout << i + 1 << ". ";
                    cout << "ID " << suppliers->at(i).getId() << ". Name: " << suppliers->at(i).getName() << endl;
                }
                cin >> supplier;

                if (supplier == 0) { itemEntry(); }
                else if (supplier == 999) {
                    string supplierName;
                    int id;

                    cout << endl;

                    cout << "Enter supplier ID, enter 0 to exit: ";
                    cin >> id;
                    if (id == 0) { itemEntry(); }
                    else {
                        for (unsigned int i = 0; i < suppliers->size(); ++i) {
                            if (suppliers->at(i).getId() == id) {
                                cout << "Supplier with such Id already exists" << endl;
                                addItem();
                                break;
                            } else continue;
                        }
                        cout << endl;
                        cout << "Enter supplier name, enter 0 to exit: ";
                        cin >> supplierName;
                        if (supplierName == null) { itemEntry(); }
                        else {
                            for (unsigned int i = 0; i < suppliers->size(); ++i) {
                                if (suppliers->at(i).getName() == supplierName) {
                                    cout << "Supplier with such name already exists" << endl;
                                    addItem();
                                    break;
                                } else continue;
                            }
                            cout << endl;
                            Item *newItem = new Item(itemId, itemQuantity, name);
                            Supplier *newSupplier = new Supplier(id, supplierName);
                            suppliers->push_back(*newSupplier);
                            string strSupplier = "ID" + to_string(newSupplier->getId()) + ", " + newSupplier->getName();
                            newItem->setSupplier(strSupplier);
                            items->push_back(*newItem);

                            cout << endl << "New item was saved"
                                 << endl << "ID - " << newItem->getId() //id
                                 << endl << "Name - " << newItem->getName() //name
                                 << endl << "Quantity - " << newItem->getQuantity() //quantity
                                 << endl << "Supplied by - " << newItem->getSupplier() << endl;
                            cout << endl;
                            itemEntry();
                        }
                    }
                } else {
                    for (unsigned int i = 0; i < suppliers->size(); ++i) {
                        if (supplier - 1 == i) {
                            string strSupplier = "ID" + to_string(suppliers->at(i).getId()) + ", " + suppliers->at(i).getName();
                            Item *item = new Item(itemId, itemQuantity, name, strSupplier);
                            items->push_back(*item);
                            cout << endl << "New item was saved"
                                 << endl << "ID - " << itemId
                                 << endl << "Name - " << name
                                 << endl << "Quantity - " << itemQuantity
                                 << endl << "Supplied by - " << suppliers->at(i).getName() << endl;
                            itemEntry();
                            break;
                        } else {
                            cout << "Wrong input" << endl;
                            itemEntry();
                        }
                    }
                }
            }
        }
    }
}

void SalesManager::deleteItem() {
    int choose;

    for (unsigned int i = 0; i < items->size(); ++i) {
        cout << i + 1 << ". ID - " << items->at(i).getId()
             << ". Name - " << items->at(i).getName()
             << ". Quantity - " << items->at(i).getQuantity()
             << ". Supplier - " << items->at(i).getSupplier() << endl;
    }

    cout << endl;
    cout << "Enter item's number, enter 0 to exit: ";
    cin >> choose;
    cout << endl;
    if (choose == 0) { itemEntry(); }
    else {
        for (unsigned int i = 0; i < items->size(); ++i) {
            if (choose - 1 == i) {
                cout << items->at(i).getName() << " item was deleted" << endl;
                items->erase(items->begin() + (choose-1));
                itemEntry();
            } else itemEntry();
        }
        itemEntry();
    }
}

void SalesManager::editItem() {
    string null = "0";
    string itemName;
    int itemId;
    int supplier;
    int choose;
    int itemQuantity;

    cout << endl;

    cout << "Item Editing Menu" << endl;
    cout << endl;
    cout << "1. Edit Item" << endl;
    cout << "2. Add Item's quantity" << endl;
    cout << "0. Exit to Main Menu" << endl;

    int i;
    cout << "Enter the number: ";
    cin >> i;
    if (i == 1) {
        for (unsigned int i = 0; i < items->size(); ++i) {
            cout << i + 1 << ". ID - " << items->at(i).getId()
                 << ". Name - " << items->at(i).getName()
                 << ". Quantity - " << items->at(i).getQuantity()
                 << ". Supplier - " << items->at(i).getSupplier() << endl;
        }

        cout << endl;
        cout << "Enter item's number, enter 0 to exit: ";
        cin >> choose;
        if (choose == 0) { itemEntry(); }
        else {
            for (unsigned int i = 0; i < items->size(); ++i) {
                if (choose - 1 == i) {
                    cout << items->at(i).getName() << " item is being edited" << endl;
                    cout << "Enter item's new ID, enter 0 to exit: ";
                    cin >> itemId;
                    if (itemId == 0) { itemEntry(); }
                    else {
                        for (unsigned int j = 0; j < items->size(); ++j) {
                            if (items->at(j).getId() == itemId) {
                                cout << "Item with such ID already exists" << endl;
                                editItem();
                            }
                        }

                        cout << endl;
                        cout << "Enter item's new name, enter 0 to exit: ";
                        cin >> itemName;
                        if (itemName == null) { itemEntry(); }
                        else {
                            cout << endl;
                            cout << "Enter item's quantity, enter 0 to exit: ";
                            cin >> itemQuantity;
                            if (itemQuantity < 0) {
                                cout << "Wrong input" << endl;
                                editItem();
                            } else {
                                for (unsigned int j = 0; j < items->size(); ++j) {
                                    if (items->at(j).getName() == itemName) {
                                        cout << "Item with such name already exists" << endl;
                                        editItem();
                                    }
                                }

                                cout << endl;
                                cout << "Choose new supplier, enter 0 to exit: " << endl;
                                for (unsigned int j = 0; j < suppliers->size(); ++j) {
                                    cout << j + 1 << ". " << suppliers->at(j).getName();
                                    cout << endl;
                                }

                                cin >> supplier;
                                if (supplier == 0) { itemEntry(); }
                                else {
                                    for (unsigned int j = 0; j < suppliers->size(); ++j) {
                                        if (supplier - 1 == j) {
                                            items->at(i).setId(itemId);
                                            items->at(i).setName(itemName);
                                            string strSupplier = "ID" + to_string(suppliers->at(j).getId()) + ", " + suppliers->at(j).getName();
                                            items->at(i).setSupplier(strSupplier);
                                            cout << items->at(i).getName() << " item was successfully edited" << endl;
                                            cout << "New ID - " << items->at(i).getId() << endl
                                                 << "New name - " << items->at(i).getName() << endl
                                                 << "New supplier - " << items->at(i).getSupplier() << endl;
                                            itemEntry();
                                            break;
                                        } else itemEntry();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if (i == 2) {
        for (unsigned int i = 0; i < items->size(); ++i) {
            cout << i + 1 << ". ID - " << items->at(i).getId()
                 << ". Name - " << items->at(i).getName()
                 << ". Quantity - " << items->at(i).getQuantity()
                 << ". Supplier - " << items->at(i).getSupplier() << endl;
        }

        cout << endl;
        cout << "Enter item's number, enter 0 to exit: ";
        cin >> choose;
        if (choose == 0) { itemEntry(); }
        else {
            cout << endl;
            cout << "Enter item's quantity, enter 0 to exit: ";
            cin >> itemQuantity;
            if (itemQuantity < items->at(choose - 1).getQuantity()) {
                cout << "Wrong input" << endl;
                editItem();
            } else {
                items->at(choose - 1).setQuantity(items->at(choose - 1).getQuantity() + itemQuantity);
                cout << "Item - " << items->at(choose - 1).getName() << endl
                     << "New quantity - " << items->at(choose - 1).getQuantity() << endl;
            }
        }
    } else if (i == 0) {
        menu();
    } else editItem();
}

void SalesManager::supplierEntry() {
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

void SalesManager::addSupplier() {
    string null = "0";
    string name;
    int supplierId;

    cout << endl;

    cout << "Enter supplier ID, enter 0 to exit: ";
    cin >> supplierId;
    if (supplierId == 0) { supplierEntry(); }
    else {
        for (unsigned int i = 0; i < suppliers->size(); ++i) {
            if (suppliers->at(i).getId() == supplierId) {
                cout << endl << " Supplier with such Id already exists" << endl;
                supplierEntry();
                break;
            } else continue;
        }
        cout << endl;
        cout << "Enter supplier's name, enter 0 to exit: ";
        cin >> name;
        if (name == null) { supplierEntry(); }
        else {
            for (unsigned int i = 0; i < suppliers->size(); ++i) {
                if (suppliers->at(i).getName() == name) {
                    cout << " Supplier with such name already exists" << endl;
                    supplierEntry();
                    break;
                } else continue;
            }
            cout << endl;

            Supplier *supplier = new Supplier(supplierId, name);
            suppliers->push_back(*supplier);

            cout << endl << "New supplier was saved"
                 << endl << "ID: " << supplierId
                 << endl << "Name: " << name << endl;
            supplierEntry();
        }
    }
}

void SalesManager::deleteSupplier() {
    int choose;

    for (unsigned int i = 0; i < suppliers->size(); ++i) {
        cout << i + 1 << ". ID: " << suppliers->at(i).getId() << ". Name: "
             << suppliers->at(i).getName() << endl;
    }

    cout << endl;
    cout << "Enter supplier's number, enter 0 to exit: ";
    cin >> choose;
    cout << endl;
    if (choose == 0) { supplierEntry(); }
    else {
        for (unsigned int i = 0; i < suppliers->size(); ++i) {
            if (choose - 1 == i) {
                cout << suppliers->at(i).getName() << " supplier was deleted" << endl;
                suppliers->erase(suppliers->begin() + (choose-1));
                supplierEntry();
            } else supplierEntry();
        }
        supplierEntry();
    }
}

void SalesManager::editSupplier() {
    string null = "0";
    string name;
    int supplierId;
    int choose;

    cout << endl;

    for (unsigned int i = 0; i < suppliers->size(); ++i) {
        cout << i + 1 << ". ID: " << suppliers->at(i).getId() << ". Name: "
             << suppliers->at(i).getName() << endl;
    }

    cout << endl;
    cout << "Enter supplier's number, enter 0 to exit: ";
    cin >> choose;
    if (choose == 0) { supplierEntry(); }
    else {
        for (unsigned int i = 0; i < suppliers->size(); ++i) {
            if (choose - 1 == i) {
                cout << suppliers->at(i).getName() << " supplier is being edited" << endl;
                cout << "Enter new supplier's ID, enter 0 to exit: ";
                cin >> supplierId;
                if (supplierId == 0) { supplierEntry(); }
                else {
                    for (unsigned int j = 0; j < suppliers->size(); ++j) {
                        if (suppliers->at(j).getId() == supplierId) {
                            cout << "Supplier with such ID already exists" << endl;
                            editSupplier();
                        }
                    }

                    cout << endl;
                    cout << "Enter new supplier's name, enter 0 to exit: ";
                    cin >> name;
                    if (name == null) { supplierEntry(); }
                    else {
                        for (unsigned int j = 0; j < suppliers->size(); ++j) {
                            if (suppliers->at(j).getName() == name) {
                                cout << "Supplier with such name already exists" << endl;
                                editSupplier();
                            } else {
                                suppliers->at(i).setId(supplierId);
                                suppliers->at(i).setName(name);

                                cout << suppliers->at(i).getName() << " item was successfully edited" << endl;
                                cout << "New Id: " << suppliers->at(i).getId() << endl
                                     << "New name: " << suppliers->at(i).getName() << endl;
                                supplierEntry();
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void SalesManager::dailySalesEntry() {
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

void SalesManager::createPR() {
    int prID;
    int neededQuantity;
    int chooseItem;
    Item *item = new Item();

    cout << endl << "Enter Purchase Requisition's ID: ";
    cin >> prID;

    for (unsigned int i = 0; i < items->size(); ++i) {
        cout << i + 1 << ". ID - " << items->at(i).getId()
             << ". Name - " << items->at(i).getName()
             << ". Quantity - " << items->at(i).getQuantity()
             << ". Supplier - " << items->at(i).getSupplier() << endl;
    }
    cout << endl << "Choose the item needed: ";
    cin >> chooseItem;

    cout << endl << "Enter quantity needed: ";
    cin >> neededQuantity;

    string strItem = "ID" + to_string(item->getId()) + ", " + item->getName();
    string salesManager = "ID" + to_string(this->getId()) + ", " + this->getName();
    PurchaseRequisition *purchaseRequisition = new PurchaseRequisition(prID, strItem, salesManager, neededQuantity);
    purchaseRequisitions->push_back(*purchaseRequisition);

    cout << endl << "Purchase Requisition was created"
         << endl << "Purchase Requisition ID - " << purchaseRequisition->getId()
         << endl << "Item - ID" << purchaseRequisition->getItem()
         << endl << "Quantity asked - " << purchaseRequisition->getNeededQuantity()
         << endl << "Created by Sales Manager - ID" << this->getId() << ", " << this->getName();

    menu();
}

void SalesManager::displayPRs() {
    for (unsigned int i = 0; i < purchaseRequisitions->size(); ++i) {
        cout << endl
             << endl << "Purchase Requisition ID - " << purchaseRequisitions->at(i).getId()
             << endl << "Item - ID" << purchaseRequisitions->at(i).getItem()
             << endl << "Quantity asked - " << purchaseRequisitions->at(i).getNeededQuantity()
             << endl << "Created by Sales Manager - ID" << purchaseRequisitions->at(i).getSalesManager() << endl;
    }
    menu();
}

void SalesManager::displayPOs() {
    for (unsigned int i = 0; i < purchaseOrders->size(); ++i) {
        cout << endl
             << endl << "Purchase Order ID - " << purchaseOrders->at(i).getID()
             << endl << "Purchase Requisition ID - " << purchaseOrders->at(i).getPrID()
             << endl << "Approved by Purchase Manager - ID" << purchaseOrders->at(i).getPurchaseManager();
    }
    menu();
}

void SalesManager::logout() {

}

SalesManager::SalesManager(int id, const string &name, const string &password) : id(id), name(name),
                                                                                 password(password) {}

SalesManager::SalesManager(int id, const string &name) : id(id), name(name) {}

SalesManager::SalesManager() {}

int SalesManager::getId() const {
    return id;
}

void SalesManager::setId(int id) {
    SalesManager::id = id;
}

const string &SalesManager::getName() const {
    return name;
}

const string &SalesManager::getPassword() const {
    return password;
}

void SalesManager::setName(const string &name) {
    SalesManager::name = name;
}

void SalesManager::setPassword(const string &password) {
    SalesManager::password = password;
}

vector<Item> *SalesManager::getItems() const {
    return items;
}

void SalesManager::setItems(vector<Item> *items) {
    SalesManager::items = items;
}

vector<Supplier> *SalesManager::getSuppliers() const {
    return suppliers;
}

void SalesManager::setSuppliers(vector<Supplier> *suppliers) {
    SalesManager::suppliers = suppliers;
}

vector<PurchaseOrder> *SalesManager::getPurchaseOrders() const {
    return purchaseOrders;
}

void SalesManager::setPurchaseOrders(vector<PurchaseOrder> *purchaseOrders) {
    SalesManager::purchaseOrders = purchaseOrders;
}

vector<PurchaseRequisition> *SalesManager::getPurchaseRequisitions() const {
    return purchaseRequisitions;
}

void SalesManager::setPurchaseRequisitions(vector<PurchaseRequisition> *purchaseRequisitions) {
    SalesManager::purchaseRequisitions = purchaseRequisitions;
}

vector<DailyItemWise> *SalesManager::getDailyItemWises() const {
    return dailyItemWises;
}

void SalesManager::setDailyItemWises(vector<DailyItemWise> *dailyItemWises) {
    SalesManager::dailyItemWises = dailyItemWises;
}
