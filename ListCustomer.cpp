#include "ListCustomer.h"

ListCustomer::ListCustomer() {
}

ListCustomer::~ListCustomer() {
}

void ListCustomer::insertNewNode(Customer customer) {
    insertNewNodeUtility(&rootPtr, customer);

}

void ListCustomer::insertNewNodeUtility(Customer** temp, Customer customer) {
    if(*temp == 0)
		*temp = new Customer(customer.idCard, customer.firstName, customer.lastName, customer.sex);
	else
	{
		if(customer.idCard < (*temp)->idCard)
			insertNewNodeUtility(&((*temp)->leftPtr), customer);
		else
		{
			if(customer.idCard > (*temp)->idCard)
				insertNewNodeUtility(&((*temp)->rightPtr), customer);
			else
				cout << dataIn << " is a duplicate value " << endl; //duplicate values ignored
		}
	}
}

void ListCustomer::preOrderPrint() {
	preOrderPrintUtility(rootPtr);
}

void ListCustomer::preOrderPrintUtility(Customer* temp) {
    if(temp != 0)
	{
		cout << temp.idCard > << " ";
		preOrderPrintUtility(temp->leftPtr);
		preOrderPrintUtility(temp->rightPtr);
	}
}


