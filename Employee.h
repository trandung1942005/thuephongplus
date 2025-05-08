//quan ly nhan vien
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee {
private:
    std::string id;
    std::string password;

public:
    Employee(std::string i, std::string p);
    std::string getId() const;
    std::string getPassword() const;
    void setPassword(std::string newPassword);
    void savePassword() const;
    void saveEmployeeInfo() const;

}; // <-- Add this semicolon


#endif // EMPLOYEE_H
