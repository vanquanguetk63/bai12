#include "ListCustomer.h"
#include "Customer.cpp"

ListCustomer::ListCustomer() {
    this->rootPtr = NULL;
}

ListCustomer::~ListCustomer() {
}

void ListCustomer::importFromFile() {
    fstream fileListCustomer;
    fileListCustomer.open("ListCustomer.txt", ios::in);
    if (fileListCustomer.is_open()) {
        int i = 0;
        int idCard;
        std::string firstName;
        std::string LastName;
        int sex;
        if (isEmptyFile(fileListCustomer))return;
        else {
            std::string line;
            while(std::getline(fileListCustomer, line)){
                std::istringstream inLine(line);
                inLine >> idCard;
                inLine >> firstName;
                inLine >> LastName;
                inLine >> sex;
                Customer customer(idCard, firstName, LastName, sex );
                this->insertNewNode(customer);
            }
        }
    }
    else cout << "Can't Open File" << endl;
    fileListCustomer.close();
}
void ListCustomer::preOrderToWrite(Customer* temp, fstream &file) {
    if(temp != 0)
	{
		preOrderToWrite(temp->leftCustomer, file);
        file << temp->getIdCard() << " " << temp->getFirstName() << " " << temp->getLastName() << " " << temp->getSex() << endl;
		preOrderToWrite(temp->rightCustomer, file);
	}
}

void ListCustomer::exportToFile() {
    fstream fileListCustomer;
	fileListCustomer.open("ListCustomer.txt",ios::out);
    preOrderToWrite(rootPtr, fileListCustomer );

	fileListCustomer.close();
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



