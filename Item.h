//
// Created by Alan on 11/08/2016.
//
#pragma once
#ifndef PCPP_ASSIGNMENT_ITEM_H
#define PCPP_ASSIGNMENT_ITEM_H

#include <string>

class Item {
private:
    int id;
    int quantity;
    std::string name;
    std::string supplier;
public:

    Item(int id, std::string name);

    Item(int id, int quantity, const std::string &name);

    Item();

    Item(int id, int quantity, const std::string &name, const std::string &supplier);

    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getQuantity() const;

    void setQuantity(int quantity);

    const std::string &getSupplier() const;

    void setSupplier(const std::string &supplier);

};


#endif //PCPP_ASSIGNMENT_ITEM_H
