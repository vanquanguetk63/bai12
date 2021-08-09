#include "ListCar.h"
#include "Car.cpp"
#include "MyLibrary.h"
#include <sstream>
#include <iomanip>

using namespace std;

ListCar::ListCar() {
    startPtr = NULL;
	endPtr = NULL;
}

ListCar::~ListCar() {
}

bool ListCar::isEmpty()
{
	if(startPtr == NULL && endPtr == NULL) //if the start pointer and end pointer are NULL then the list is empty
		return 1;
	else
		return 0;
}

void ListCar::insertNewCar(Car car)
{
	if(isEmpty())
	{
		Car* newCar = new Car(car.carId, car.production, car.model, car.seats);
		startPtr = newCar;
		endPtr = newCar;
	}else
	{
		Car* newCar = new Car(car.carId, car.production, car.model, car.seats);
		endPtr->nextCar = newCar;
		endPtr = newCar;
	}
}

void ListCar::print() {
    if(isEmpty())
	{
		cout << "The list is empty" << endl;

	}else
	{
		Car * currentPtr = startPtr;
        int i = 1;
        cout << "Ma xe" << setw(20) << "Hang san xuat" << setw(20) << "Phan khuc" << setw(20) << "So cho ngoi" << endl;
		while(currentPtr != NULL)
		{
            cout << currentPtr->carId << setw(20) << currentPtr->production << setw(20) <<  currentPtr->model << setw(20) <<  currentPtr->seats << endl;
			currentPtr = currentPtr->nextCar;
			i++;
		}
		cout << endl;
	}
}

Car* ListCar::search(Car car)
{
	Car* nodeCar;
	bool found = false;

	nodeCar = startPtr;

	while((!found) && (nodeCar != NULL))
	{
		if(nodeCar->carId == car.carId)
			found = true;
		else
			nodeCar = nodeCar->nextCar;
	}
	return nodeCar;
}

bool ListCar::isExist(Car car) {
    Car* isExistCar = search(car);
    return isExistCar != NULL;
}

void ListCar::readFromFile() {
    fstream fileListCar;
    fileListCar.open("ListCar.txt", ios::in);
    if (fileListCar.is_open()) {
		int i = 0;
		std::string line;
		int carId;
		std::string production;
		std::string model;
		int seats;
		if (isEmptyFile(fileListCar))return;
		else {
			Car car;
            while(std::getline(fileListCar, line)){
                std::istringstream inLine(line);
                inLine >> carId;
                inLine >> production;
                inLine >> model;
                inLine >> seats;
                car.setCarID(carId);
                car.setProduction(production);
                car.setModel(model);
                car.setSeats(seats);
                this->insertNewCar(car);
            }
		}
	}
	else cout << "Can't Open File" << endl;
	fileListCar.close();
};

bool ListCar::removeCar(int carNumber) {
    if (startPtr->carId == carNumber) {
        startPtr = startPtr->nextCar;
        return true;
    }
    Car* nodeCar;
	nodeCar = this->startPtr;
	bool isRemoved = false;

	while(nodeCar != NULL)
	{
        if(nodeCar->carId == carNumber) {
            nodeCar = nodeCar->nextCar;
            isRemoved = true;
            break;
        }
        nodeCar = nodeCar->nextCar;
	}
	return isRemoved;
}

Car* ListCar::searchByCarNumber(int carNumber) {
    Car* nodeCar;
	nodeCar = startPtr;
	while(nodeCar != NULL)
	{
        if(nodeCar->carId == carNumber) {
            break;
        }
        nodeCar = nodeCar->nextCar;
	}
	return nodeCar;
}
void ListCar::exportToFile() {
    fstream fileListCar;
	fileListCar.open("ListCar.txt",ios::out);
	if (!this->isEmpty()) {
		Car* nodeCar;
        nodeCar = startPtr;
        while(nodeCar != NULL)
        {
            fileListCar << nodeCar->carId << " " << nodeCar->production << " " << nodeCar->model << " " << nodeCar->seats << endl;
            nodeCar = nodeCar->nextCar;
        }
	}
	fileListCar.close();
}




