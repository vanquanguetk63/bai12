#include "Customer.h"
#ifndef LISTCUSTOMER_H_INCLUDED
#define LISTCUSTOMER_H_INCLUDED

class ListCustomer
{
public:
	ListCustomer();
	~ListCustomer();
	void insertNewNode(Customer Customer);
	void preOrderPrint();
	void inOrderPrint();
	void postOrderPrint();
	Customer* search(Customer customer);
	Customer* searchById(int);

private:
	Customer *rootPtr;
	bool isEmpty();

	void insertNewNodeUtility(Customer**, Customer);
	void preOrderPrintUtility(Customer*, Customer);
	void inOrderPrintUtility(Customer*);
	void postOrderPrintUtility(Customer*);
	Customer* searchUtility(Customer*, Customer);
};

#endif // LISTCUSTOMER_H_INCLUDED
