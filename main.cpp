#include <iostream>
#include <stdlib.h>
#include <string>
#include "ListCar.cpp"
#include "ListTrip.cpp"
#include "ListCustomer.cpp"
using namespace std;

int main()
{
    int option;
    int inputNumber;
    std::string inputText = "";
    std::string currentMenu = "Menu";
    ListCar listCar;
    listCar.readFromFile();
    ListTrip listTrip;
    listTrip.readFromFile();
    ListCustomer listCustomer;
    listCustomer.importFromFile();

    while(true) {
        if (currentMenu == "Menu") {
            system ("cls");
            cout << "Menu" << endl;
            cout << "1. Cap nhat Xe" << endl;
            cout << "2. Cap nhat chuyen xe" << endl;
            cout << "3. Dat ve" << endl;
            cout << "4. Danh sach ve theo chuyen xe" << endl;
            cout << "5. Cac chuyen xe  trong ngay" << endl;
            cout << "------------------------------" << endl;
            cout << "Nhap lua chon cua ban: " << endl;
            cin >> option;
        } else if (currentMenu == "MenuCar") {
            option = 1;
        } else if (currentMenu == "MenuTrip") {
            option = 2;
        } else if (currentMenu == "MenuTicket") {
            option = 3;
        } else if (currentMenu == "MenuDetailTrip") {
            option = 4;
        } else if (currentMenu == "MenuDetailDay") {
            option = 5;
        }

        if (option == 1) {
            currentMenu = "MenuCar";
            bool inOption = true;
            while(inOption) {
                system ("cls");
                cout << "Cap nhat xe" << endl;
                cout << "0. Tro lai" << endl;
                cout << "1. Them xe" << endl;
                cout << "2. Xoa xe" << endl;
                cout << "3. Cap nhat xe" << endl;
                cout << "------------------------------" << endl;
                cout << "Nhap lua chon cua ban: " << endl;
                listTrip.print();
                cin >> option;
                if (option == 0) {
                    currentMenu = "Menu";
                    inOption = false;
                }
                else if (option == 1) {
                    system ("cls");
                    bool isPress = true;
                    Car newCar;
                    while (isPress) {
                        system ("cls");
                        listCar.print();
                        cout << "Them xe" << endl;
                        cout << "------------------------------" << endl;
                        cout << "Nhap vao thong tin xe: " << endl;
                        cout << "So xe: ";
                        cin >> inputNumber;
                        newCar.setCarID(inputNumber);
                        cout << "Hang san xuat: ";
                        fflush(stdin);
                        getline(cin, inputText);
                        newCar.setProduction(inputText);
                        cout << "Model: ";
                        fflush(stdin);
                        getline(cin, inputText);
                        newCar.setModel(inputText);
                        fflush(stdin);
                        cout << "So cho ngoi: ";
                        cin >> inputNumber;
                        newCar.setSeats(inputNumber);
                        cout << "Nhap Ok";
                        if (listCar.isExist(newCar)) {
                            system ("cls");
                            cout << "Xe da ton tai" << endl;
                            cout << "------------------------------" << endl;
                        } else {
                            system ("cls");
                            listCar.insertNewCar(newCar);
                            listCar.exportToFile();
                            cout << "Them xe thanh cong" << endl;
                            cout << "------------------------------" << endl;
                            }
                    cout << "1. Tiep tuc nhap" << endl;
                    cout << "0. Quay lai" << endl;
                    cout << "Nhap vao hanh dong tiep theo: ";
                    cin >> option;
                    if (option == 0) {
                        isPress = false;
                    }
                }
            } else if (option == 2) {
                bool isPress = true;
                while(isPress) {
                    system ("cls");
                    listCar.print();
                    cout << "Xoa xe" << endl;
                    cout << "------------------------------" << endl;
                    cout << "Nhap vao ID xe can xoa: " << endl;
                    cout << "Id xe: ";
                    int carNumber;
                    cin >> carNumber;
                    Car* car = listCar.searchByCarNumber(carNumber);
                    if(car != NULL) {
                        listCar.removeCar(carNumber);
                        cout << "xoa thanh cong" << endl;
                        if (listCar.isEmpty()) {
                            isPress = false;
                        }
                    }
                    cout << "1. Tiep tuc nhap" << endl;
                    cout << "0. Quay lai" << endl;
                    cout << "Nhap vao hanh dong tiep theo: ";
                    cin >> option;
                    if (option == 0) {
                        isPress = false;
                    }
                }
                } else if (option == 3) {
                    bool isPress = true;
                    while(isPress) {
                        system ("cls");
                        listCar.print();
                        cout << "Sua thong tin xe" << endl;
                        cout << "------------------------------" << endl;
                        cout << "Nhap vao ID xe can sua: " << endl;
                        cout << "Id xe: ";
                        int carNumber;
                        cin >> carNumber;
                        Car* car = listCar.searchByCarNumber(carNumber);
                        if(car != NULL) {
                            string production;
                            string model;
                            int seats;
                            cout << "Hang san xuat: ";
                            fflush(stdin);
                            getline(cin, production);
                            cout << "Model: ";
                            fflush(stdin);
                            getline(cin, model);
                            cout << "So cho ngoi: ";
                            cin >> seats;
                            car->setProduction(production);
                            car->setModel(model);
                            car->setSeats(seats);
                            cout << "Sua thong tin xe thanh cong" << endl;
                            cout << "------------------------------" << endl;
                        }
                        cout << "1. Tiep tuc nhap" << endl;
                        cout << "0. Quay lai" << endl;
                        cout << "Nhap vao hanh dong tiep theo: ";
                        cin >> option;
                        if (option == 0) {
                            isPress = false;
                        }
                    }
                }
            }
        }
        else if (option == 2) {
            currentMenu == "MenuTrip";
            bool inOption = true;
            while(inOption) {
                system ("cls");
                cout << "Cap nhat chuyen xe" << endl;
                cout << "0. Tro lai" << endl;
                cout << "1. Them chuyen xe" << endl;
                cout << "2. Cap nhat chuyen xe" << endl;
                cout << "------------------------------" << endl;
                cout << "Nhap lua chon cua ban: " << endl;
                cin >> option;
                if (option == 0) {
                    currentMenu = "Menu";
                    inOption = false;
                    continue;
                } else if (option == 1) {
                    system ("cls");
                    bool isPress = true;
                    while (isPress) {
                        system ("cls");
                        listTrip.print();
                        int idTrip;
                        string dayTrip;
                        string hourTrip;
                        string province;
                        int carId;

                        cout << "Them chuyen xe" << endl;
                        cout << "------------------------------" << endl;
                        cout << "Nhap vao thong tin chuyen xe: " << endl;
                        cout << "Ma chuyen: ";
                        cin >> idTrip;
                        cout << "Ngay khoi hanhg(dd/mm/yyy) : ";
                        fflush(stdin);
                        cin >> dayTrip;
                        cout << "Gio khoi hanh(hh:mm) : ";
                        fflush(stdin);
                        cin >> hourTrip;
                        cout << "Tinh den(Viet lien khong dau cach) : ";
                        fflush(stdin);
                        cin >> province;
                        cout << "Ma xe: ";
                        fflush(stdin);
                        cin >> carId;
                        Trip trip(idTrip, dayTrip, hourTrip, province, carId);
                        if (listTrip.isExist(trip)) {
                            system ("cls");
                            cout << "Chuyen xe da ton tai" << endl;
                            cout << "------------------------------" << endl;
                        } else {
                            system ("cls");
                            listTrip.insertNewTrips(trip);
                            listTrip.exportToFile();
                            cout << "Them chuyen xe thanh cong" << endl;
                            cout << "------------------------------" << endl;
                        }
                        cout << "1. Tiep tuc nhap" << endl;
                        cout << "0. Quay lai" << endl;
                        cout << "Nhap vao hanh dong tiep theo: ";
                        cin >> option;
                        if (option == 0) {
                            isPress = false;
                        }

                    }
                } else if (option == 2) {
                    system ("cls");
                    bool isPress = true;
                    while (isPress) {
                        system ("cls");
                        listTrip.print();
                        int idTrip;
                        string dayTrip;
                        string hourTrip;
                        int status;

                        cout << "Cap nhat chuyen xe" << endl;
                        cout << "------------------------------" << endl;
                        cout << "Nhap vao ma chuyen xe: " << endl;
                        cin >> idTrip;
                        if (listTrip.searchById(idTrip) == -1) {
                            system("cls");
                            cout << "Ma chuyen xe khong ton tai" << endl;
                            cout << "------------------------------" << endl;
                        } else {
                            system("cls");
                            cout << "Nhap thong tin xe" << endl;
                            cout << "------------------------------" << endl;
                            cout << "Ma chuyen: ";
                            cout << "Ngay khoi hanh(dd/mm/yyy) : ";
                            fflush(stdin);
                            cin >> dayTrip;
                            cout << "Gio khoi hanh(hh:mm) : ";
                            fflush(stdin);
                            cin >> hourTrip;
                            fflush(stdin);
                            cout << "Trang thai: ";
                            cin >> status;
                            listTrip.editTrip(idTrip, dayTrip, hourTrip, status);
                            cout << "Thanh cong" << endl;
                            cout << "------------------------------" << endl;

                        }
                        cout << "1. Tiep tuc nhap" << endl;
                        cout << "0. Quay lai" << endl;
                        cout << "Nhap vao hanh dong tiep theo: ";
                        cin >> option;
                        if (option == 0) {
                            isPress = false;
                        }
                    }
                }

            }
        }
        else if (option == 3) {
            currentMenu = "MenuCar";
            bool inOption = true;
            while (inOption) {
                system ("cls");
                listTrip.print();
                cout << "Dat xe" << endl;
                cout << "Nhap ma xe can dat" << endl;
                cout << "------------------------------" << endl;
                cout << "Nhap lua chon cua ban: " << endl;
                cin >> option;
                int indexTrip = listTrip.searchById(option);
                bool isHaveCar = indexTrip == -1;
                while(isHaveCar) {
                    cout << "Nhap lai " << endl;
                    fflush(stdin);
                    cin >> option;
                    indexTrip = listTrip.searchById(option);
                    isHaveCar = indexTrip == -1;
                }
                int idCard;
                string firstName;
                string lastName;
                int sex;
                cout << "------------------------------" << endl;
                cout << "Nhap CMND : " << endl;
                cin >> idCard;
                cout << "Nhap first name" << endl;
                fflush(stdin);
                cin >> firstName;
                fflush(stdin);
                cout << "Nhap last name" << endl;
                cin >> lastName;
                fflush(stdin);
                cout << "Nhap gioi tinh" << endl;
                cin >> sex;
                fflush(stdin);

                Customer* searchCustomer = listCustomer.searchById(idCard);
                if (searchCustomer == NULL) {
                    Customer newCus(idCard, firstName, lastName, sex);
                    listCustomer.insertNewNode(newCus);
                    listCustomer.exportToFile();
                }
                Trip& trip = listTrip.getTripById(indexTrip);
                bool isBookTicket = trip.isHaveBookTicket(idCard);
                if (isBookTicket) {
                    cout << "Ban da dat ve, nen ko the dat nua." << endl;
                } else {
                    Ticket newTicket(option, idCard);
                    trip.addTicket(newTicket);
                    listTrip.exportToFile();
                    cout << "Dat ve thanh cong" << endl;
                }

                cout << "------------------------------" << endl;
                cout << "1. Tiep tuc nhap" << endl;
                cout << "0. Quay lai" << endl;
                cout << "Nhap vao hanh dong tiep theo: ";
                cin >> option;
                if (option == 0) {
                    inOption = false;
                    currentMenu="Menu";
                    continue;
                }

            }
        }
        else if (option == 4) {
            currentMenu = "MenuDetailTrip";
            bool inOption = true;
            while(inOption) {
                system ("cls");
                listTrip.print();
                cout << "------------------------------" << endl;
                cout << "Chon ma  chuyen xe " << endl;
                cin >> option;
                int trip = listTrip.searchById(option);
                bool isWrong = trip == -1;
                while (isWrong) {
                    cout << "Nhap lai ";
                    fflush(stdin);
                    cin >> option;
                    trip = listTrip.searchById(option);
                    isWrong = trip == -1;
                }
                system ("cls");
                listTrip.printDetail(option, listCustomer);

                fflush(stdin);
                cout << "1. Tiep tuc nhap" << endl;
                cout << "0. Quay lai" << endl;
                cout << "Nhap vao hanh dong tiep theo: ";
                cin >> option;
                if (option == 0) {
                    currentMenu="Menu";
                    inOption = false;
                }
            }
        } else if (option == 5) {
            currentMenu = "MenuDetailDay";
            bool inOption = true;
            while(inOption) {
                system ("cls");
                listTrip.print();
                cout << "Chuyen xe trong ngay";
                cout << "------------------------------" << endl;
                cout << "Nhap vao ngay " << endl;
                string dateType;
                string province;

                fflush(stdin);

                cin >> dateType;
                fflush(stdin);
                cout << "Nhap vao tinh " << endl;
                fflush(stdin);
                cin >> province;

                system ("cls");

                fflush(stdin);
                listTrip.printDetailByDayAndProvince(dateType, province, listCar);
                cout << "1. Tiep tuc nhap" << endl;
                cout << "0. Quay lai" << endl;
                cout << "Nhap vao hanh dong tiep theo: ";
                cin >> option;
                if (option == 0) {
                    currentMenu="Menu";
                    inOption = false;
                }
            }
        }

    }


    return 0;
}
