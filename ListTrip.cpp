#include "ListTrip.h"
#include "Trip.cpp"
#include <vector>
#include <iomanip>

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
		int numTickets;
		int status;
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
                inLine >> status;
                inLine >> numTickets;
                std::string ticketLine;
                int idCard;
                int idBus;
                Trip trip(tripId, day, hour, province, carId);
                trip.setStatus(status);
                for (int i = 0 ; i < numTickets; i++) {
                    std::getline(fileListTrip, ticketLine);
                    std::istringstream inTicketLine(ticketLine);
                    inTicketLine >> idBus;
                    inTicketLine >> idCard;
                    Ticket ticket(idBus, idCard );
                    trip.addTicket(ticket);
                }
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
            std::vector<Ticket> listTicket = this->trips[i].getListTickets();
            int indexTicket = listTicket.size();
            fileListTrip << this->trips[i].getId() << " " << this->trips[i].getDate() << " " << this->trips[i].getHour() << " " <<
            this->trips[i].getProvince() << " " << this->trips[i].getCarId() << " " << this->trips[i].getStatus() << " " << indexTicket << endl;
            for (int i = 0; i < indexTicket;i++) {
                fileListTrip << listTicket.at(i).getIdTrip() << " " << listTicket.at(i).getIdCard() << endl;
            }
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

void ListTrip::printDetail(int idTrip, ListCustomer listCustomer) {
    int sizeTrip = this->trips.size();
    for (int i=0;i < sizeTrip; i++) {
        if (this->trips.at(i).getId() == idTrip) {
            Trip trip = this->trips.at(i);
            cout << "Danh sach khanh hang thuoc chuyen xe so " << trip.getCarId() << endl;
            cout << "Ngay khoi hanh " << trip.getDate() << " " << trip.getHour() << "     Den tinh " << trip.getProvince() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "STT" << std::setw(10) << "So ve" << std::setw(10) << "Ho ten" << std::setw(10) << "CMND" <<  std::setw(10) << "Phai" << endl;
            std::vector<Ticket> listTicket = trip.getListTickets();
            int index = listTicket.size();
            for (int i=0; i< index;i++) {
                int idCard = listTicket.at(i).getIdCard();
                Customer* customer = listCustomer.searchById(idCard);
                cout << i+1 << std::setw(10) << i+1 << std::setw(10) << customer->getFullName() << std::setw(10) << customer->getIdCard() <<  std::setw(10) <<  "Nu" << endl;
            }
        }
    }
};

void ListTrip::printDetailByDayAndProvince(string dateType, string province, ListCar listCar ) {
    int sizeTrip = this->trips.size();
    for (int i=0;i < sizeTrip; i++) {
        if (dateType.compare(this->trips.at(i).getDate()) == 0  && province.compare(this->trips.at(i).getProvince()) == 0) {
            Trip trip = this->trips.at(i);
            cout << "Ngay khoi hanh " << trip.getDate() << " " << trip.getHour() << "     Den tinh " << trip.getProvince() << endl;
            cout << "-----------------------------------------" << endl;
            Car* car = listCar.searchByCarNumber(trip.getCarId());
            cout << "So cho con trong .... " << car->getSeats() - trip.getNumberTickets() << endl;
        }
    }
};










