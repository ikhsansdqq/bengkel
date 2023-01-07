#include "menu.h"

int main() {
    customerList customerList{};
    adr_customer addressCustomer = nullptr;
    adr_vehicle addressVehicle = nullptr;
    string customerName, customerID, vehicleBrand, vehicleID, vehicleType, vehicleModel, vehicleStatus;
//    int picker, vehicleReleaseYear;

    createListCustomer(customerList);

    /*
    while (picker != 0) {
        cout << "==== WELCOME TO BENGKEL ====" << endl;
        cout << "1. Show All Data \n2. Show With Sample Data \n3. Add New Data \n4. Testing enviromet \n0. Exit Program"
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
                printDataCustomer(customerList);
            }
        } else if (picker == 2) {
            addressCustomer = CreateElementCustomerData(addressCustomer, "Fauzan", "FRM001");
            insertLastCustomer(customerList, addressCustomer);
            addressCustomer = CreateElementCustomerData(addressCustomer, "Alam", "ARP001");
            insertLastCustomer(customerList, addressCustomer);

            addressVehicle = CreateElementVehicleData(addressVehicle, "Toyota", "TS-98","SUV", "Land Cruiser", "Inspection", 1998);
            insertLastVehicle(customerList,"FRM001", addressVehicle);
            addressVehicle = CreateElementVehicleData(addressVehicle, "Ford", "FT-80", "Truck", "F150", "Done", 1980);
            insertLastVehicle(customerList,"ARP001", addressVehicle);
            printDataCustomer(customerList);
        } else if (picker == 3) {
            cout << "Customer Full Name         : ";
            cin >> customerName;
            cout << "Customer ID (ex: IA3001)   : ";
            cin >> customerID;
            cout << "Vehicle Brand              : ";
            cin >> vehicleBrand;
            cout << "Vehicle ID                 : ";
            cin >> vehicleID;
            cout << "Vehicle Type               : ";
            cin >> vehicleType;
            cout << "vehicle Model              : ";
            cin >> vehicleModel;
            cout << "Vehicle Status             : ";
            cin >> vehicleStatus;
            cout << "Vehicle Release Year       : ";
            cin >> vehicleReleaseYear;

            // Perulangan jumlah kendaraan + kepemilikan

            addressCustomer = CreateElementCustomerData(addressCustomer, customerName, customerID);
            insertLastCustomer(customerList, addressCustomer);
            addressVehicle = CreateElementVehicleData(addressVehicle, vehicleBrand, vehicleID,vehicleType, vehicleModel, vehicleStatus, vehicleReleaseYear);
            insertLastVehicle(customerList, customerID, addressVehicle);
            printDataCustomer(customerList);
        } else if (picker = 4){


        }else if (picker == 0) {
            break;
        }
    }
    */
    if (customerList.first == nullptr) {
        cout << "Customer List is still empty" << endl;
    } else {
        cout << customerList.first << endl;
    }

    cout << "======= THIS IS JUST A PROCEDURE AND FUNCTION TEST =======" << endl;
    cout << "Testing by input 2 customer data" << endl;
    cout << "==========" << endl;
    addressCustomer = CreateElementCustomerData(addressCustomer, "Fauzan", "FRM001");
    insertLastCustomer(customerList, addressCustomer);
    addressCustomer = CreateElementCustomerData(addressCustomer, "Alam", "ARP001");
    insertLastCustomer(customerList, addressCustomer);
    printAllDataCustomer(customerList);

    cout << endl;

    cout << "Testing by input 2 vehicle data and update customer status" << endl;
    cout << "==========" << endl;
    addressVehicle = CreateElementVehicleData(addressVehicle, "Toyota", "TS-98", "SUV", "Land Cruiser", "In Progress",
                                              1998);
    insertLastVehicle(customerList, "FRM001", addressVehicle);
    addressVehicle = CreateElementVehicleData(addressVehicle, "Ford", "FT-80", "Truck", "F150", "DONE", 1980);
    insertLastVehicle(customerList, "ARP001", addressVehicle);

    updateAllCustomer(customerList);
    printAllDataCustomer(customerList);
    cout << endl;
    printDataVehicle(customerList, "FRM001");
    printDataVehicle(customerList, "ARP001");
    cout << endl;

    cout
            << "Testing changing vehicle status from InProgress to DONE and see if its updated on the customer side (Fauzan Data will be used for testing)"
            << endl;
    cout << "==========" << endl;
    customerID = "FRM001";
    vehicleID = "TS-98";
    vehicleStatus = "DONE";
    cout << "Which customer need to be updated ? (Type the ID) " << customerID << endl;
    cout << "Which vehicle status need to be updated (Type the ID) " << vehicleID << endl;
    cout << "What status ? (DONE or InProgress only) " << vehicleStatus << endl;
    cout << endl;
    addressCustomer = findCustomerAddress(customerList, customerID);
    addressVehicle = findVehicleAddress(addressCustomer, vehicleID);
    updateVehicleStatusTemporary(addressVehicle, vehicleStatus);
    updateAllCustomer(customerList);
    printAllDataCustomer(customerList);
    printDataVehicle(customerList, "FRM001");
    return 0;
}
