#include "Room.h"

Room::Room(std::string rn, double p) : RoomBase(rn, p), guestName(""), daysBooked(0), rentedBy("") {}

std::string Room::getGuestName() const {
    return guestName;
}

int Room::getDaysBooked() const {
    return daysBooked;
}

std::string Room::getRentedBy() const {
    return rentedBy;
}

void Room::setGuestName(std::string name) {
    guestName = name;
}

void Room::setDaysBooked(int days) {
    daysBooked = days;
}

void Room::setRentedBy(std::string id) {
    rentedBy = id;
}

double Room::calculateTotalCost() const {
    return daysBooked * price;
}
