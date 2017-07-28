//
// Created by Alan on 11/08/2016.
//
#pragma once
#ifndef PCPP_ASSIGNMENT_DAILYITEMWISE_H
#define PCPP_ASSIGNMENT_DAILYITEMWISE_H
#include <string>

class DailyItemWise {
private:
    int id;
    int quantity;
public:
    DailyItemWise(int id, int quantity);

    int getId() const;

    void setId(int id);

    int getQuantity() const;

    void setQuantity(int quantity);
};


#endif //PCPP_ASSIGNMENT_DAILYITEMWISE_H
