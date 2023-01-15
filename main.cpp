#include "menu.h"

int main() {
    customerList customerList{};
    adr_customer addressCustomer = nullptr;
    adr_vehicle addressVehicle = nullptr;
    adr_damage addressDamage = nullptr;
    string customerName, customerID, vehicleBrand, vehicleID, vehicleType, vehicleModel, vehicleStatus;

    createListCustomer(customerList);

//    Conditional Checking if A List is empty.
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
    printDataVehicle(customerList, "FRM001");

    cout << endl;

    cout << "Testing by input 2 vehicle data and update customer status" << endl;
    cout << "==========" << endl;
    addressVehicle = CreateElementVehicleData(addressVehicle, "Toyota", "TS-98", "SUV", "Land Cruiser", 1998);
    insertLastVehicle(customerList, "FRM001", addressVehicle);
    addressVehicle = CreateElementVehicleData(addressVehicle, "Ford", "FT-80", "Truck", "F150", 1980);
    insertLastVehicle(customerList, "ARP001", addressVehicle);
    updateAllCustomer(customerList);
    printAllDataCustomer(customerList);
    cout << endl;
    printDataVehicle(customerList, "FRM001");
    printDataVehicle(customerList, "ARP001");
    cout << endl;

    cout << "Testing by input 2 vehicle data and update customer status and vehicle status" << endl;
    cout << "==========" << endl;
    addressDamage = CreateElementDamageData(addressDamage, "Mesin", "Salah masukin oli", IN_PROGRESS, "ABC");
    insertDamage(customerList, "FRM001", "TS-98",addressDamage);
    addressDamage = CreateElementDamageData(addressDamage, "Body", "Lecet", IN_PROGRESS , "DEF");
    insertDamage(customerList, "ARP001", "FT-80",addressDamage);
    updateAllCustomer(customerList);
    printAllDataCustomer(customerList);
    cout << endl;
    printDataVehicle(customerList, "ARP001");
    cout << endl;
    printDataDamage(customerList, "ARP001", "FT-80");

    cout << endl;

    cout << "========= Damage Status on Vehicle Test in for ARP001 =========" << endl;
    cout << "Before Updating" << endl;
    printDataVehicle(customerList, "ARP001");
    cout << "After Updating" << endl;
    addressCustomer = findCustomerAddress(customerList, "ARP001");
    addressVehicle = findVehicleAddress(addressCustomer,"FT-80");
    addressDamage = findDamageAddress(addressVehicle,"DEF");
    updateDamageStatus(addressDamage,DONE);
    printDataDamage(customerList, "ARP001", "FT-80");
    updateVehicleStatus(addressVehicle);
    updateAllCustomer(customerList);
    printDataVehicle(customerList,"ARP001");

    addressDamage = findDamageAddress(addressVehicle,"DEF");
    cout << "Delete damage to customer side (Alam)" << endl;
    cout << "==========" << endl;
    cout << "Before Delete" << endl;
    printDataDamage(customerList, "ARP001", "FT-80");

    cout << "After Delete" << endl;
    addressCustomer = findCustomerAddress(customerList,  "ARP001");
    addressVehicle = findVehicleAddress(addressCustomer,"FT-80");
    deleteDamage(addressVehicle, "DEF");
    printDataDamage(customerList, "ARP001", "FT-80");
    
    cout << endl;
    cout << "Delete vehicle to customer side (Fauzan Vehicle)" << endl;
    cout << "==========" << endl;

    cout << "Before Delete" << endl;
    printDataVehicle(customerList, "FRM001");

    cout << "After Delete" << endl;
    addressCustomer = findCustomerAddress(customerList,  "FRM001");
    deleteVehicle(addressCustomer, "TS-98");
    printDataVehicle(customerList, "FRM001");

    cout << endl;
    cout << endl;

    cout << "Delete all vechicle" << endl;
    cout << "==========" << endl;

    cout << "Before Delete" << endl;
    printDataVehicle(customerList, "ARP001");

    cout << "After Delete" << endl;
    addressCustomer = findCustomerAddress(customerList,  "ARP001");
    deleteAllVehicle(addressCustomer);
    printDataVehicle(customerList, "ARP001");
    cout << endl;
    cout << endl;
    cout << "Delete customer to customer side (Fauzan Vechile)" << endl;
    cout << "==========" << endl;

    cout << "Before Delete" << endl;
    printAllDataCustomer(customerList);

    cout << endl; 
    cout << "After Delete" << endl;
    deleteCustomer(customerList, "FRM001");
    printAllDataCustomer(customerList);

    cout << endl;
    return 0;
}
