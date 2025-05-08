//quan ly nhan vien
#include "Employee.h"
#include <iostream>
#include <fstream>

Employee::Employee(std::string i, std::string p) : id(i), password(p) {}

std::string Employee::getId() const {
    return id;
}

std::string Employee::getPassword() const {
    return password;
}

void Employee::setPassword(std::string newPassword) {
    password = newPassword;
}

void Employee::savePassword() const {
    std::ofstream outfile("passwords.in", std::ios::app); // Open file in append mode
    if (outfile) {
        outfile << id << " " << password << std::endl;
        outfile.close();
        std::cout << "Password saved successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to open password file for writing." << std::endl;
    }
}

void Employee::saveEmployeeInfo() const {
    std::ofstream outfile("passwords.in", std::ios::app); // Open file in append mode
    if (outfile) {
        outfile << id << " " << password << std::endl;
        outfile.close();
        std::cout << "Employee information saved successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to open password file for writing." << std::endl;
    }
}
