//
// Created by Alan on 11/08/2016.
//
#include <stdio.h>
#include "Item.h"

using namespace std;

Item::Item(int id, std::string name) : id(id), name(name) {}

Item::Item() {}

int Item::getId() const {
    return id;
}

void Item::setId(int id) {
    Item::id = id;
}

const std::string &Item::getName() const {
    return name;
}

void Item::setName(const std::string &name) {
    Item::name = name;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::setQuantity(int quantity) {
    Item::quantity = quantity;
}

Item::Item(int id, int quantity, const string &name) : id(id), quantity(quantity), name(name) {}

Item::Item(int id, int quantity, const string &name, const string &supplier) : id(id), quantity(quantity), name(name),
                                                                               supplier(supplier) {}

const string &Item::getSupplier() const {
    return supplier;
}

void Item::setSupplier(const string &supplier) {
    Item::supplier = supplier;
}
