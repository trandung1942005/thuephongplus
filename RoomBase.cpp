//can phong
#include "RoomBase.h"

RoomBase::RoomBase(std::string rn, double p) : roomNumber(rn), price(p), roomStatus(false) {}

std::string RoomBase::getRoomNumber() const {
    return roomNumber;
}

double RoomBase::getPrice() const {
    return price;
}

bool RoomBase::getRoomStatus() const {
    return roomStatus;
}

void RoomBase::setRoomStatus(bool status) {
    roomStatus = status;
}
