#include "menu.h"

int main() {
    customerList customerList{};
    vehicleList vehicleList{};
    adr_customer addressCustomer = nullptr;
    adr_vehicle addressVehicle = nullptr;
    int choiceNum;

    createListCustomer(customerList);

    /*cout << "Please input how many customers: ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "Your full name: ";
        cin >> name;
        cout << "ID:";
        cin >> id;
        cout << "Status:";
        cin >> status;

        addressCustomer = CreateElementCustomerData(addressCustomer, name, id, status);
        insertLastCustomer(customerList, addressCustomer);
    }
    */

    cout << "==== Welcome to Our Bengkel of The Year. ====" << endl;
    cout << "Please pick a menu: " << endl;
    cout << "1. Insert New Data \n2. See All Data" << endl;
    cout << "Choose number: ";
    cin >> choiceNum;

    if (choiceNum == 1) {
        addressCustomer = CreateElementCustomerData(addressCustomer, "Fauzan", "FRM001", "Done");
        insertLastCustomer(customerList, addressCustomer);
        addressCustomer = CreateElementCustomerData(addressCustomer, "Alam", "ARP001", "In Progress");
        insertLastCustomer(customerList, addressCustomer);

        addressVehicle = CreateElementVehicleData(addressVehicle, "Toyota", "SUV", "Land Cruiser", "Done", 1998);
        insertLastVehicle(customerList, vehicleList, "FRM001", addressVehicle);
        addressVehicle = CreateElementVehicleData(addressVehicle, "Ford", "Truck", "F150", "Done", 1980);
        insertLastVehicle(customerList, vehicleList, "ARP001", addressVehicle);

        printData(customerList);
    } else if (choiceNum == 2) {
        printData(customerList);
    } else {
        return 0;
    }
}