//
// Created by Alan on 11/08/2016.
//
#include <stdio.h>
#include "Supplier.h"
#include "iostream"

using namespace std;

Supplier::Supplier(int id, std::string name) : id(id), name(name) {}

Supplier::Supplier() {}

int Supplier::getId() const {
    return id;
}

void Supplier::setId(int id) {
    Supplier::id = id;
}

const std::string &Supplier::getName() const {
    return name;
}

void Supplier::setName(const std::string &name) {
    Supplier::name = name;
}











