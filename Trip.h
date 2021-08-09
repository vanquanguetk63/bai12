#include "vector"
#include "Ticket.h"
#ifndef TRIP_H_INCLUDED
#define TRIP_H_INCLUDED

class Trip
{
friend class ListTrip;
public:
    Trip();
	Trip(int id, std::string date, std::string hour, std::string province, int carId);
    ~Trip();
    void insetNewTrip(Trip trip);
    int getId() {
        return this->id;
    }
    std::string getDate() {
        return this->date;
    }
    std::string getHour() {
        return this->hour;
    }
    std::string getProvince() {
        return this->province;
    }
    int getCarId() {
        return this->carId;
    }
    int getNumberTickets() {
        return this->tickets.size();
    }
    int getStatus() {
        return this->status;
    }

    void setDate(std::string date) {
    this->date = date;}
    void setHour(std::string hour) {
    this->hour = hour;}
    void setStatus(int status){
    this->status = status;}
	void addTicket(Ticket);
	bool isHaveBookTicket(int idCard);
	std::vector<Ticket> getListTickets() {
	return this->tickets;}


private:
	int id;
	int status;
	std::string date;
	std::string hour;
	int carId;
    std::string province;
    std::vector<Ticket> tickets;
};

#endif // TRIP_H_INCLUDED
