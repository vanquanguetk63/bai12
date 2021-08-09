#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

class Customer
{
    friend class ListCustomer;
public:
	Customer();
	Customer(int idCard, std::string firstName, std::string lastName, bool sex);
	~Customer();

	int getIdCard() {
        return idCard;
	}

	std::string getFullName() {
        return this->firstName + " " + this->lastName;
	}

	int getSex() {
        return this->sex;
	}

	std::string getFirstName() {
	return this->firstName;}

	std::string getLastName() {
	return this->lastName;}

private:
    int idCard;
    std::string firstName;
    std::string lastName;
    bool sex;
    Customer* leftCustomer;
	Customer* rightCustomer;
};

#endif // CUSTOMER_H_INCLUDED
