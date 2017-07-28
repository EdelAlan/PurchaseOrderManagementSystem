//
// Created by Alan on 11/08/2016.
//
#pragma once
#ifndef PCPP_ASSIGNMENT_SUPPLIER_H
#define PCPP_ASSIGNMENT_SUPPLIER_H

#include <string>

class Supplier {
private:
    int id;
    std::string name;
public:

    Supplier(int id, std::string name);

    Supplier();

    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);
};


#endif //PCPP_ASSIGNMENT_SUPPLIER_H
