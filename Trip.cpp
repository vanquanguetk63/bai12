#include "Trip.h";

Trip::Trip(std::string id, int status, std::string date, std::string hour,std::string province, int carId)
{
    this->id = id;
    this->status = status;
    this->date = date;
    this->hour = hour;
    this->province = province;
    this->carId = carId;
    this->tickets = NULL;
}

Trip::~Trip() {
}


