//
// Created by Alan on 11/08/2016.
//
#pragma once
#include <stdio.h>
#include "DailyItemWise.h"

DailyItemWise::DailyItemWise(int id, int quantity) : id(id), quantity(quantity) {}

int DailyItemWise::getId() const {
    return id;
}

void DailyItemWise::setId(int id) {
    DailyItemWise::id = id;
}

int DailyItemWise::getQuantity() const {
    return quantity;
}

void DailyItemWise::setQuantity(int quantity) {
    DailyItemWise::quantity = quantity;
}