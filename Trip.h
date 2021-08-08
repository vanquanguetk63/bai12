#include "Ticket.h"
#ifndef TRIP_H_INCLUDED
#define TRIP_H_INCLUDED

class Trip
{
public:
	Trip(std::string id, int status, std::string date, std::string hour, std::string province, int carId);
    ~Trip();
    void insetNewTrip(Trip trip);

private:
	std::string id;
	int status;
	std::string date;
	std::string hour;
	int carId;
    std::string province;
    std::vector<Ticket> tickets;
};

#endif // TRIP_H_INCLUDED
