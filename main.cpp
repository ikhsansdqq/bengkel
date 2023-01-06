#include "menu.h"

int main() {
    customerList customerList{};
    vehicleList vehicleList{};
    adr_customer addressCustomer = nullptr;
    adr_vehicle addressVehicle = nullptr;
    string customerName, customerID, customerStatus, vehicleBrand, vehicleType, vehicleModel, vehicleStatus;
    int picker, vehicleReleaseYear;

    createListCustomer(customerList);

    while (picker != 0) {
        cout << "==== WELCOME TO BENGKEL ====" << endl;
        cout << "1. Show All Data \n2. Show With Sample Data \n3. Add New Data \n0. Exit Program"
             << endl;
        cout << "Your choice: ";
        cin >> picker;
        cout << endl;
        if (picker == 1) {
//            printData(customerList);
            if (customerList.first == nullptr) {
                cout << "!--- The List is Empty! ---!" << endl;
                cout << endl;
            } else {
                printData(customerList);
            }
        } else if (picker == 2) {
            addressCustomer = CreateElementCustomerData(addressCustomer, "Fauzan", "FRM001", "Done");
            insertLastCustomer(customerList, addressCustomer);
            addressCustomer = CreateElementCustomerData(addressCustomer, "Alam", "ARP001", "In Progress");
            insertLastCustomer(customerList, addressCustomer);

            addressVehicle = CreateElementVehicleData(addressVehicle, "Toyota", "SUV", "Land Cruiser", "Inspection",
                                                      1998);
            insertLastVehicle(customerList, vehicleList, "FRM001", addressVehicle);
            addressVehicle = CreateElementVehicleData(addressVehicle, "Ford", "Truck", "F150", "Done", 1980);
            insertLastVehicle(customerList, vehicleList, "ARP001", addressVehicle);
            printData(customerList);
        } else if (picker == 3) {
            cout << "Customer Full Name: ";
            cin >> customerName;
            cout << "Customer ID (ex: IA3001): ";
            cin >> customerID;
            cout << "Customer Status: ";
            cin >> customerStatus;
            cout << "Vehicle Brand: ";
            cin >> vehicleBrand;
            cout << "Vehicle Type: ";
            cin >> vehicleType;
            cout << "vehicle Model: ";
            cin >> vehicleModel;
            cout << "Vehicle Status: ";
            cin >> vehicleStatus;
            cout << "Vehicle Release Year: ";
            cin >> vehicleReleaseYear;

            // Perulangan jumlah kendaraan + kepemilikan

            addressCustomer = CreateElementCustomerData(addressCustomer, customerName, customerID, customerStatus);
            insertLastCustomer(customerList, addressCustomer);
            addressVehicle = CreateElementVehicleData(addressVehicle, vehicleBrand, vehicleType, vehicleModel,
                                                      vehicleStatus, vehicleReleaseYear);
            insertLastVehicle(customerList, vehicleList, customerID, addressVehicle);
            printData(customerList);
        } else if (picker == 0) {
            return 0;
        }
    }
}