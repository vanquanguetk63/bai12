#include <iostream>
#include <stdlib.h>
#include <string>
#include "ListCar.cpp"
#include "ListTrip.cpp"
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
    while(true) {
        if (currentMenu == "Menu") {
            system ("cls");
            cout << "Menu" << endl;
            cout << "1. Cap nhat Xe" << endl;
            cout << "2. Cap nhat chuyen xe" << endl;
            cout << "3. Dat ve" << endl;
            cout << "4. Danh sach ve theo chuyen xe" << endl;
            cout << "5. Cac chuyen xe trong ngay" << endl;
            cout << "6. Thong ke xe" << endl;
            cout << "------------------------------" << endl;
            cout << "Nhap lua chon cua ban: " << endl;
            cin >> option;
        } else if (currentMenu == "MenuCar") {
            option = 1;
        } else if (currentMenu == "MenuTrip") {
            option = 2;
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
    }


    return 0;
}
