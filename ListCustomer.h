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
	Customer* search(Customer customer);
	Customer* searchById(int);
	void importFromFile();
	void exportToFile();
	void preOrderToWrite(Customer* temp,fstream &file);

private:
	Customer *rootPtr;
	bool isEmpty();

	void insertNewNodeUtility(Customer**, Customer);
	void preOrderPrintUtility(Customer*);
	Customer* searchUtilityById(Customer*, int);
};

#endif // LISTCUSTOMER_H_INCLUDED
