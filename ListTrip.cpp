#include "ListTrip.h"
#include "Trip.cpp"
#include <vector>

ListTrip::ListTrip() {
}

ListTrip::~ListTrip() {
}

bool ListTrip::isEmpty()
{
	return this->trips.size() == 0;
}

bool ListTrip::isExist(Trip trip) {
    if (isEmpty()) {
        return false;
    }
    int sizeListTrip = this->trips.size();

    for(int i = 0; i <  sizeListTrip; i++) {
        if (this->trips[i].getId() == trip.getId()) {
            return true;
        }
    }
    return false;
}

void ListTrip::insertNewTrips(Trip trip) {
    this->trips.push_back(trip);
    exportToFile();
}


void ListTrip::print() {
    if(isEmpty())
	{
		cout << "The list is empty" << endl;

	}else
	{
        cout << "Ma Chuyen xe" << setw(20) << "Ngay gio" << setw(20) << "Tinh den" << setw(20) << "So xe" << setw(20) << "So ve" << setw(20) << "Trang thai" << endl;
        int sizeListTrip = this->trips.size();
        for(int i = 0; i <  sizeListTrip; i++) {
            cout << setw(5) <<  this->trips[i].getId() << setw(20) << this->trips[i].getDate() << " " << this->trips[i].getHour() << setw(20) << this->trips[i].getProvince() << setw(20) << this->trips[i].getCarId() << setw(20) <<
            this->trips[i].getNumberTickets() << setw(20) << this->trips[i].getStatus() << endl;
        }
		cout << endl;
	}
}

void ListTrip::readFromFile() {
    fstream fileListTrip;
    fileListTrip.open("ListTrip.txt", ios::in);
    if (fileListTrip.is_open()) {
		int i = 0;
		int tripId;
		std::string day;
		std::string hour;
		std::string province;
		int carId;
		if (isEmptyFile(fileListTrip))return;
		else {
			string line;
            while(std::getline(fileListTrip, line)){
                std::istringstream inLine(line);
                inLine >> tripId;
                inLine >> day;
                inLine >> hour;
                inLine >> province;
                inLine >> carId;
                Trip trip(tripId, day, hour, province, carId);
                this->insertNewTrips(trip);
            }
		}
	}
	else cout << "Can't Open File" << endl;
	fileListTrip.close();
};

void ListTrip::exportToFile() {
    fstream fileListTrip;
	fileListTrip.open("ListTrip.txt",ios::out);
	if (!this->isEmpty()) {
        int index = this->trips.size();
        for (int i = 0; i < index; i++) {
            fileListTrip << this->trips[i].getId() << " " << this->trips[i].getDate() << " " << this->trips[i].getHour() << " " <<
            this->trips[i].getProvince() << " " << this->trips[i].getCarId() << " 0" << endl;

        }

	}
	fileListTrip.close();
}

int ListTrip::searchById(int id) {
    if (isEmpty()) {
        return -1;
    }
    int sizeListTrip = this->trips.size();

    for(int i = 0; i <  sizeListTrip; i++) {
        if (this->trips[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

void ListTrip::editTrip(int idTrip,std::string dayTrip,std::string hourTrip,int status) {
    this->trips.at(idTrip - 1).setDate(dayTrip);
    this->trips.at(idTrip - 1).setHour(hourTrip);
    this->trips.at(idTrip - 1).setStatus(status);
    this->exportToFile();
}

Trip& ListTrip::getTripById(int i) {
    return this->trips.at(i);
}








