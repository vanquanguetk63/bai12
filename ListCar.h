#ifndef LISTCAR_H_INCLUDED
#define LISTCAR_H_INCLUDED

#include "Car.h"

class ListCar
{
public:
	ListCar();
	~ListCar();

	void insertNewCar(Car);
	void print();
	Car* search(Car);
    Car* searchByCarNumber(int carNumber);
	bool removeCar(int carNumber);
	void readFromFile();
	bool isExist(Car);
	bool isEmpty();
	void exportToFile();

private:
    Car *startPtr;
	Car *endPtr;

};

#endif // LISTCAR_H_INCLUDED
