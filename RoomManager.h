// quan ly phong
#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include <string>
#include <vector>
#include "Room.h"
#include <fstream> // Include for file operations
using namespace std;

struct Customer {
    std::string id;
    std::string roomType;
    std::string roomNumber;
    int daysBooked = 0; // Initialize to 0
    double totalCost = 0.0; // Initialize to 0.0
};

class RoomManager {
public:
    RoomManager();
    void displayMenu() const;
    void chooseRoomType();
    void showRoomStatus() const;
    void showAvailableRooms() const;
    void addGuest(const string& id, const string& roomType, const string& roomNumber, int days);
    void removeGuest(const string& id, const string& roomType, const string& roomNumber);
    const vector<int>& getPhong1() const;
    const vector<int>& getPhong2() const;
    const vector<int>& getPhong3() const;
    void saveCustomerInfo(const Customer& customer); // Save customer info to file
    void loadCustomerInfo(); // Load customer info from file

private:
    vector<int> phong1;
    vector<int> phong2;
    vector<int> phong3;
    vector<Room> roomsList; // Store Room objects
    vector<Customer> customers; // Store customer information
    void initRooms();
    void printRoomList(const vector<int>& rooms) const;
    void printAvailableRooms(const vector<int>& rooms) const; // New method to print available rooms
    void rentFrom(vector<int>& rooms, int roomType, int days, const string& id);
};

#endif // ROOMMANAGER_H
