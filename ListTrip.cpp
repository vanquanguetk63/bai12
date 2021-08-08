#include "ListTrip.h"
#include <vector>

ListTrip::ListTrip() {
}

ListTrip::~ListTrip() {
}

bool ListTrip::isEmpty()
{
	return this->trips == NULL || this->trips.size() === 0;
}

bool ListTrip::isExist(Trip trip) {
    if (this->trips == NULL) {
        return false;
    }
    int sizeListTrip = this->trips.size();

    for(int i = 0; i <  sizeListTrip; i++) {
        if (this->trips[i]->id == trip.id) {
            return true;
        }
    }
    return false;
}

void ListTrip::insertNewTrips(Trip trip) {
    this->trips.push_back(trip);
}


void ListTrip::print() {
    if(isEmpty())
	{
		cout << "The list is empty" << endl;

	}else
	{
        cout << "Ma Chuyen xe" << setw(20) << "Ngay gio" << setw(20) << "Tinh den" << setw(20) << "So xe" << setw(20) << "So ve" setw(20) << "Trang thai" endl;
        int sizeListTrip = this->trips.size();
        for(int i = 0; i <  sizeListTrip; i++) {
            cout << this->trips[i]->id << setw(20) << currentPtr->production << setw(20) <<  currentPtr->model << setw(20) <<  currentPtr->seats << endl;
            cout << this->trips[i]->id << setw(20) << this->trips[i]->date << "" << this->trips[i]->hour << setw(20) << this->trips[i]->province << setw(20) << this->trips[i]->carId << setw(20) <<
            this->trips[i]->numberTickets << setw(20) << this->trips[i]->status << endl;
        }
		cout << endl;
	}
}



