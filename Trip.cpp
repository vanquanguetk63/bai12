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

void Trip::addTicket(Ticket ticket) {
    this->tickets.push_back(ticket);
}

bool Trip::isHaveBookTicket(int idCard) {
    if (this->tickets.size() == 0) {
        return false;
    }
    int index = this->tickets.size();
    for (int i = 0; i < index; i++) {
        if (this->tickets.at(i).getIdCard() == idCard) {
            return true;
        }
    }
    return false;
}



