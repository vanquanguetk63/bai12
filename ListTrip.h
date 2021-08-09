#include "Trip.h"
#include "ListCustomer.h"
#include <vector>
#ifndef LISTTRIP_H_INCLUDED
#define LISTTRIP_H_INCLUDED

class ListTrip
{
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
	Trip& getTripById(int);
	void printDetail(int idTrip, ListCustomer);
	void printDetailByDayAndProvince(std::string  dateType, std::string  province, ListCar);


private:
    std::vector<Trip> trips;
};

#endif // LISTTRIP_H_INCLUDED
