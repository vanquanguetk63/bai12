#include "Trip.h"
#include <vector>
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
	void readFromFile();
	void exportToFile();
	int searchById(int id);
	void editTrip(int idTrip,std::string dayTrip,std::string hourTrip,int status);

private:
    std::vector<Trip> trips;
};

#endif // LISTTRIP_H_INCLUDED
