cmake_minimum_required(VERSION 3.6)
project(PCPP_assignment)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SalesManager.cpp SalesManager.h admin.cpp admin.h DailyItemWise.cpp DailyItemWise.h PurchaseManager.cpp PurchaseManager.h PurchaseOrder.cpp PurchaseOrder.h PurchaseRequisition.cpp PurchaseRequisition.h Supplier.cpp Supplier.h Item.cpp Item.h)
add_executable(PCPP_assignment ${SOURCE_FILES})