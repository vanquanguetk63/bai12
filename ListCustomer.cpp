#include "ListCustomer.h"
#include "Customer.cpp"

ListCustomer::ListCustomer() {
    this->rootPtr = NULL;
}

ListCustomer::~ListCustomer() {
}

void ListCustomer::importFromFile() {

}

void ListCustomer::insertNewNode(Customer customer) {
    cout << customer.firstName<< endl;
    insertNewNodeUtility(&rootPtr, customer);
}

void ListCustomer::insertNewNodeUtility(Customer** temp, Customer customer) {\
    if(*temp == NULL) {
        cout << "zo "<< endl;
		*temp = new Customer(customer.idCard, customer.firstName, customer.lastName, customer.sex);
}
	else
	{
		if(customer.idCard < (*temp)->idCard)
			insertNewNodeUtility(&((*temp)->leftCustomer), customer);
		else
		{
			if(customer.idCard > (*temp)->idCard)
				insertNewNodeUtility(&((*temp)->rightCustomer), customer);
			else
				cout <<  " is a duplicate value " << endl; //duplicate values ignored
		}
	}
}

void ListCustomer::preOrderPrintUtility(Customer* temp) {
    if(temp != 0)
	{
		cout << temp->idCard << " ";
		preOrderPrintUtility(temp->leftCustomer);
		preOrderPrintUtility(temp->rightCustomer);
	}
}

void ListCustomer::preOrderPrint() {
	preOrderPrintUtility(rootPtr);
}

Customer* ListCustomer::searchUtilityById(Customer* leaf, int key) {
    if(leaf != NULL)
	{
		if(key == leaf->idCard)
			return leaf;
		if(key < leaf->idCard)
			return searchUtilityById(leaf->leftCustomer, key);
		else
			return searchUtilityById(leaf->rightCustomer, key);
	}
	else
		return NULL;
}

Customer* ListCustomer::searchById(int key) {
    return searchUtilityById(rootPtr, key);
}



