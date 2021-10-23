cmake_minimum_required(VERSION 3.0)
project(simple_ATM_controller)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -Wextra -pedantic -pedantic-errors")

add_executable(simple_ATM_controller main.cpp CashBinDev.cpp CashBinDev.h BankSystemDev.cpp BankSystemDev.h ATMController.cpp ATMController.h BankUserDev.cpp BankUserDev.h ATMDisplayManagerDev.cpp ATMDisplayManagerDev.h)

