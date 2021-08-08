#include "Trip.h"
#ifndef LISTTRIP_H_INCLUDED
#define LISTTRIP_H_INCLUDED

class ListTrip
{
friend class Trip;

public:
	ListTrip();
	~ListTrip();
	bool isExist(Trip trip);
	void insertNewTrips(Trip trip);
	void print();
	bool isEmpty();

private:
    std::vector<Trip> trips;
};

#endif // LISTTRIP_H_INCLUDED
