#include "RoomManager.h"
#include "Room.h"
#include "Employee.h"
#include "Revenue.h"
#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

list<Room> rooms;
list<Employee> employees;
RoomManager rm; // Create a single instance of RoomManager
Revenue revenue; // Create a single instance of Revenue

void loadEmployees() {
    ifstream infile("passwords.in");
    string id, password;
    while (infile >> id >> password) {
        employees.push_back(Employee(id, password));
    }
    infile.close();
}

bool login(string id, string password) {
    for (const auto& emp : employees) {
        if (emp.getId() == id && emp.getPassword() == password) {
            std::cout << "Access granted" << std::endl;
            return true;
        }
    }
    std::cout << "Login failed!" << std::endl;
    return false;
}

void changePassword(string id) {
    string oldPassword, newPassword;
    std::cout << "Enter current password: ";
    std::cin >> oldPassword;
    if (login(id, oldPassword)) {
        std::cout << "Enter new password: ";
        std::cin >> newPassword;
        for (auto& emp : employees) {
            if (emp.getId() == id) {
                emp.setPassword(newPassword);
                // Cập nhật mật khẩu trong file
                std::vector<Employee> updatedEmployees(employees.begin(), employees.end());
                std::ofstream outfile("passwords.in");
                if (outfile) {
                    for (const auto& e : updatedEmployees) {
                        outfile << e.getId() << " " << e.getPassword() << std::endl;
                    }
                    outfile.close();
                    std::cout << "Password changed and saved successfully!" << std::endl;
                }
                else {
                    std::cerr << "Failed to open password file for writing." << std::endl;
                }
                return;
            }
        }
    }
}

void addEmployee() {
    string id, password;
    std::cout << "Enter new employee ID: ";
    std::cin >> id;
    std::cout << "Enter new employee password: ";
    std::cin >> password;
    Employee newEmployee(id, password);
    employees.push_back(newEmployee);
    newEmployee.saveEmployeeInfo(); // Save new employee info to passwords.in
    std::cout << "Employee added successfully!" << std::endl;
}

void removeEmployee() {
    string id;
    std::cout << "Enter employee ID to remove: ";
    std::cin >> id;

    // Xóa nhân viên khỏi danh sách employees
    employees.remove_if([&id](const Employee& emp) { return emp.getId() == id; });

    // Đọc toàn bộ nội dung file passwords.in vào một vector tạm thời
    std::vector<Employee> updatedEmployees;
    std::ifstream infile("passwords.in");
    string empId, empPassword;
    while (infile >> empId >> empPassword) {
        if (empId != id) { // Chỉ thêm những nhân viên không bị xóa
            updatedEmployees.push_back(Employee(empId, empPassword));
        }
    }
    infile.close();

    // Ghi lại toàn bộ nội dung đã cập nhật vào file passwords.in
    std::ofstream outfile("passwords.in");
    if (outfile) {
        for (const auto& e : updatedEmployees) {
            outfile << e.getId() << " " << e.getPassword() << std::endl;
        }
        outfile.close();
        std::cout << "Employee removed successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to open password file for writing." << std::endl;
    }
}

void addGuest() {
    string id, roomType, roomNumber;
    int days;
    std::cout << "Enter your employee ID: ";
    std::cin >> id;
    std::cout << "Enter room type (1, 2, or 3): ";
    std::cin >> roomType;
    std::cout << "Enter room number: ";
    std::cin >> roomNumber;
    std::cout << "Enter number of days: ";
    std::cin >> days;
    rm.addGuest(id, roomType, roomNumber, days); // Use the single instance of RoomManager
}

void removeGuest() {
    string id, roomType, roomNumber;
    std::cout << "Enter your employee ID: ";
    std::cin >> id;
    std::cout << "Enter room type (1, 2, or 3): ";
    std::cin >> roomType;
    std::cout << "Enter room number: ";
    std::cin >> roomNumber;
    rm.removeGuest(id, roomType, roomNumber); // Use the single instance of RoomManager
}

void showRoomPrices() {
    for (auto& room : rooms) {
        std::cout << "Room " << room.getRoomNumber() << ": $" << room.getPrice() << std::endl;
    }
}

void addRevenue(double amount, int month) {
    revenue.addRevenue(amount, month);
}

void displayRevenue() {
    char order;
    std::cout << "Display revenue in (a) ascending or (d) descending order? ";
    std::cin >> order;
    bool ascending = (order == 'a');
    revenue.displayRevenue(ascending);
}

void menu() {
    char option;
    string id, password;
    std::cout << "Enter your employee ID: ";
    std::cin >> id;
    std::cout << "Enter your password: ";
    std::cin >> password;
    if (login(id, password)) {
        do {
            std::cout << "Menu:\n";
            std::cout << "(a) Add guest\n";
            std::cout << "(b) Remove guest\n";
            std::cout << "(c) Show room prices\n";
            std::cout << "(d) Change password\n";
            std::cout << "(e) Add employee\n";
            std::cout << "(f) Remove employee\n";
            std::cout << "(g) Show available rooms\n";
            std::cout << "(h) Display revenue\n";
            std::cout << "(i) Quit\n";
            std::cin >> option;
            switch (option) {
            case 'a': addGuest(); break;
            case 'b': removeGuest(); break;
            case 'c': showRoomPrices(); break;
            case 'd': changePassword(id); break;
            case 'e': addEmployee(); break;
            case 'f': removeEmployee(); break;
            case 'g': rm.showAvailableRooms(); break;
            case 'h': displayRevenue(); break;
            case 'i': std::cout << "Goodbye!" << std::endl; break;
            default: std::cout << "Invalid option!" << std::endl; break;
            }
        } while (option != 'i');
    }
}

int main() {
    // Load employees from file
    loadEmployees();
    // Sample data
    rooms.push_back(Room("101", 100.0));
    rooms.push_back(Room("102", 150.0));
    rooms.push_back(Room("103", 200.0));
    // Add sample revenue data
    addRevenue(1000.0, 1);
    addRevenue(1500.0, 2);
    addRevenue(2000.0, 3);
    menu();
    return 0;
}
