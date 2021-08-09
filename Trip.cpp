#include "Trip.h";
#include "Ticket.cpp"

Trip::Trip() {
}

Trip::Trip(int id, std::string date, std::string hour,std::string province, int carId)
{
    this->id = id;
    this->status = 1;
    this->date = date;
    this->hour = hour;
    this->province = province;
    this->carId = carId;
}

Trip::~Trip() {
}


