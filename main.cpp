#include "menu.h"

int main() {
    customerList customerList;
    adr_customer addressCustomer = nullptr;
    adr_vehicle addressVehicle = nullptr;
    string vehicleStatus,customerID,vehicleID;

    createListCustomer(customerList);

    addressCustomer = CreateElementCustomerData(addressCustomer, "Fauzan", "FRM001");
    insertLastCustomer(customerList,addressCustomer);
    addressCustomer = CreateElementCustomerData(addressCustomer, "Alam", "ARP001");
    insertLastCustomer(customerList,addressCustomer);

    addressVehicle = CreateElementVehicleData(addressVehicle,"Toyota","TS-98","SUV","Land Cruiser","In Progress",1998);
    insertLastVehicle(customerList,"FRM001",addressVehicle);
    addressVehicle = CreateElementVehicleData(addressVehicle,"Ford","FR-80","Truck","F150","DONE",1980);
    insertLastVehicle(customerList,"ARP001",addressVehicle);
    printData(customerList);
    
    cout<<"======= Updating vehicle status test ========"<<endl;
    cout<<"Which customer need to be updated ? (Type the ID) ";
    cin>>customerID;
    cout<<"Which vehicle status need to be updated (Type the ID) ";
    cin>>vehicleID;
    cout<<"What status ? (DONE or InProgress only) ";
    cin>>vehicleStatus;
    addressCustomer = findCustomerAddress(customerList, customerID);
    addressVehicle = findVehicleAddress(addressCustomer,vehicleID);
    updateVehicleStatusTemporary(addressVehicle,vehicleStatus);
    updateAllCustomer(customerList);
    printData(customerList);
    return 0;
}
