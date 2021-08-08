#include "Car.h";

Car::Car() {
    this->nextCar = NULL;
}

Car::Car(int carId, std::string production, std::string model, int number){
    this->carId = carId;
    this->production = production;
    this->model = model;
    this->seats = number;
    this->nextCar = NULL;
}

Car::~Car() {
}


