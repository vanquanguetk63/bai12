#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

class Customer
{
public:
	Customer();
	~Customer();

	int getIdCard() {
        return idCard
	}

private:
    int idCard;
    std::string firstName;
    std::string lastName;
    bool sex;
};

#endif // CUSTOMER_H_INCLUDED
