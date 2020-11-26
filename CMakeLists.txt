cmake_minimum_required(VERSION 3.17)
project(SalesManagement)

set(CMAKE_CXX_STANDARD 17)

add_executable(SalesManagement main.cpp Product.cpp Product.h Detail.cpp Detail.h Bill.cpp Bill.h ServiceSales.cpp ServiceSales.h)