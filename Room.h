#ifndef ROOM_H
#define ROOM_H

#include "RoomBase.h"
#include <string>

class Room : public RoomBase {
private:
    std::string guestName;
    int daysBooked;
    std::string rentedBy;

public:
    Room(std::string rn, double p);
    std::string getGuestName() const;
    int getDaysBooked() const;
    std::string getRentedBy() const;
    void setGuestName(std::string name);
    void setDaysBooked(int days);
    void setRentedBy(std::string id);
    double calculateTotalCost() const;
};

#endif // ROOM_H
