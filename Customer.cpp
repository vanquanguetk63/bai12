#include "Customer.h"

Customer::Customer() {
}

Customer::Customer(int idCard, std::string firstName, std::string lastName, bool sex) {
    this->idCard = idCard;
    this->firstName = firstName;
    this->lastName = lastName;
    this->sex = sex;
}

Customer::~Customer() {
}
