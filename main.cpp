#include "menu.h"

int main() {
    customerList customerList;
    vehicleList vehicleList;
    adr_customer addressCustomer;
    adr_vehicle addressVehicle;
    string name, id, status;
    int num;

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

    addressCustomer = CreateElementCustomerData(addressCustomer, "Fauzan", "FPS001", "BERES");
    insertLastCustomer(customerList,addressCustomer);
    addressCustomer = CreateElementCustomerData(addressCustomer, "Alam", "AHH001", "BELUM BERES");
    insertLastCustomer(customerList,addressCustomer);
    addressVehicle = CreateElementVehicleData(addressVehicle,"Toyota","SUV","Land Cruiser","Ded as hell",1998);
    insertLastVehicle(customerList,vehicleList,"FPS001",addressVehicle);
    addressVehicle = CreateElementVehicleData(addressVehicle,"Ford","Truck","F150","Broken asf",1980);
    insertLastVehicle(customerList,vehicleList,"FPS001",addressVehicle);


    printData(customerList);

    return 0;
}
