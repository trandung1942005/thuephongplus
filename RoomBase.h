//can phong
#ifndef ROOMBASE_H
#define ROOMBASE_H

#include <string>

class RoomBase {
protected:
    std::string roomNumber;
    double price;
    bool roomStatus; // true = occupied, false = available

public:
    RoomBase(std::string rn, double p);
    std::string getRoomNumber() const;
    double getPrice() const;
    bool getRoomStatus() const;
    void setRoomStatus(bool status);
};

#endif // ROOMBASE_H
