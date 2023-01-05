#include "menu.h"
using namespace std;

void createListCustomer(customerList &customerList) {
    customerList.first = nullptr;
}

adr_customer CreateElementCustomerData(adr_customer addressCustomer, string name, string customer_id, string status) {
    addressCustomer = new customer;
    addressCustomer->name = name;
    addressCustomer->customer_id = customer_id;
    addressCustomer->status = status;
    addressCustomer->vehicle = nullptr;
    addressCustomer->next = nullptr;

    return addressCustomer;
}

void insertLastCustomer(customerList &customerList, adr_customer addressCustomer) {
    if (customerList.first == nullptr) {
        customerList.first = addressCustomer;
        return;
    }
    adr_customer addressCustomer2 = customerList.first;
    while (addressCustomer2->next != nullptr) {
        addressCustomer2 = addressCustomer2->next;
    }
    addressCustomer2->next = addressCustomer;

}

adr_vehicle CreateElementVehicleData(adr_vehicle addressVehicle, string brand, string car_type, string model, string status,
                         int year) { //Creating element for Vehicle BOX aka The data to some customer
    addressVehicle = new vehicle;
    addressVehicle->brand = brand;
    addressVehicle->car_type = car_type;
    addressVehicle->model = model;
    addressVehicle->status = status;
    addressVehicle->year = year;
    addressVehicle->damage = nullptr;
    addressVehicle->next = nullptr;

    if (addressVehicle->status == DONE) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }

    return addressVehicle;
}

adr_customer findCustomerAddress(customerList customerList, string customer_id) {
    adr_customer addressCustomer = customerList.first;
    while (addressCustomer != nullptr) {
        if (addressCustomer->customer_id == customer_id) {
            return addressCustomer;
        }
        addressCustomer = addressCustomer->next;
    }
    cout << "There is no such customer with this ID" << endl;
    return nullptr;
}


void insertLastVehicle(customerList &customerList, vehicleList &vehicleList, string customer_id,
                       adr_vehicle addressVehicle) {
    adr_customer addressCustomer = findCustomerAddress(customerList, customer_id);
    if (addressCustomer == nullptr) {
        cout << "There is no such customer with this ID" << endl;
        return;
    }

    adr_vehicle addressVehicle2 = addressCustomer->vehicle;
    if (addressVehicle2 == nullptr) {
        addressCustomer->vehicle = addressVehicle;
        return;
    }

    while (addressVehicle2->next != nullptr) {
        addressVehicle2 = addressVehicle2->next;
    }
    addressVehicle2->next = addressVehicle;
}

/*
adr_damage CreateElementDamage(adr_damage AD,string title, string explanation, string status);
void insertLastDamage(customerList customerList, adr_damage AD);
*/

void printData(customerList customerList) {
    adr_customer addressCustomer = customerList.first;
    adr_vehicle addressVehicle;
    int customerCount = 1, vehicleCount;
    while (addressCustomer != nullptr) {
        cout << "====== CUSTOMER DATA " << customerCount << " ======" << endl;
        cout << "Customer Name    :   " << addressCustomer->name << endl;
        cout << "Customer ID      :   " << addressCustomer->customer_id << endl;
        cout << "Customer Status  :   " << addressCustomer->status << endl;

        addressVehicle = addressCustomer->vehicle;
        vehicleCount = 1; //resetting the counter after displaying all the vehicle on previous customer

        cout << "====== Vehicle List ======" << endl;
        if (addressVehicle == nullptr) {
            cout << "There is no vehicle assigned to this customer" << endl;
            return;
        }
        while (addressVehicle != nullptr) { // Printing the Vehicle inside the customer
            cout << "Vehicle      : " << vehicleCount << endl;
            cout << "Brand        : " << addressVehicle->brand << endl;
            cout << "Type         : " << addressVehicle->car_type << endl;
            cout << "Model        : " << addressVehicle->model << endl;
            cout << "Year         : " << addressVehicle->year << endl;
            cout << "Status       : " << addressVehicle->status << endl;

            cout << endl;
            addressVehicle = addressVehicle->next;
            vehicleCount++;
        }
        addressCustomer = addressCustomer->next;
        customerCount++;
    }
}



adr_vehicle findVehicleAddress(vehicleList vehicleList, string vehicle_id) {
    adr_vehicle addressVehicle = customerList.first;
    while (addressVehicle != nullptr) {
        if (addressVehicle->vehicle_id == vehicle_id) {
            return addressVehicle;
        }
        addressVehicle = addressVehicle->next;
    }
    cout << "There is no such customer with this ID" << endl;
    return nullptr;
}

bool checkAllVehicleStatus(adr_customer customer, string statusCheck) {
    if(customer->vehicle != nullptr) {
        adr_vehicle i = customer->vehicle;
        while(i != nullptr) {
            if(i->status != statusCheck) {
                return false;
            }
            i = i->next;
        }
        return true;
    }
    return true;
}

bool checkAllDamageStatus(adr_vehicle vehicle, string statusCheck) {
    if(vehicle->damage != nullptr) {
        adr_damage i = vehicle->damage;
        while(i != nullptr) {
            if(i->status != statusCheck) {
                return false;
            }
            i = i->next;
        }
        return true;
    }
    return true;
}

void updateVehicleStatus(adr_vehicle &vehicle) {
    if(checkAllDamageStatus(vehicle, DONE) {
        vehicle->status = DONE;
    }
}

void updateCustomerStatus(adr_customer &customer) {
    if(checkAllVehicleStatus(customer, DONE) {
        customer->status = DONE;
    }
}

void updateAll(customerList &list) {
    adr_customer i = list.first;
    while(i != nullptr) {
        updateCustomerStatus(i);
    }
}