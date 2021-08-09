#ifndef CAR_INCLUDED
#define CAR_INCLUDED

#include "ListCar.h"

class Car
{
friend class ListCar;

public:
    Car();
	Car(int carId, std::string production, std::string model, int number);
	~Car();

    void setCarID(int carId) {
        this->carId = carId;
    }

    void setProduction(std::string production) {
        this->production = production;
    }

    void setModel(std::string model) {
        this->model = model;
    }

    void setSeats(int seats) {
        this->seats = seats;
    }

    int getSeats() {
        return this->seats;
    }

private:
	int carId;
	std::string production;
	std::string model;
	int seats;
	Car* nextCar;
};
#endif // Car_H
