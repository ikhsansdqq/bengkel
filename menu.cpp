#include "menu.h"

using namespace std;

void createListCustomer(customerList &customerList) {
    customerList.first = nullptr;
}

adr_customer CreateElementCustomerData(adr_customer addressCustomer, string name, string customer_id) {
    addressCustomer = new customer;
    addressCustomer->name = name;
    addressCustomer->customer_id = customer_id;
    addressCustomer->status = NO_VEHICLE_ASSIGNED; // Default condition.
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

adr_vehicle CreateElementVehicleData(adr_vehicle addressVehicle, string brand, string vehicle_id, string car_type, string model, string status, int year) { //Creating element for Vehicle BOX aka The data to some customer
    addressVehicle = new vehicle;
    addressVehicle->brand = brand;
    addressVehicle->vehicle_id = vehicle_id;
    addressVehicle->car_type = car_type;
    addressVehicle->model = model;
    addressVehicle->status = status;
    addressVehicle->year = year;
    "No Vehicle Assigned yet"; //initial start for status will be updated later
    addressVehicle->damage = nullptr;
    addressVehicle->next = nullptr;

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


void insertLastVehicle(customerList &customerList, string customer_id, adr_vehicle addressVehicle) {
    adr_customer addressCustomer = findCustomerAddress(customerList, customer_id);
    if (addressCustomer == nullptr) {
        cout << "There is no such customer with this ID" << endl;
        return;
    }
    addressCustomer->status = IN_PROGRESS;
    
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

void printAllDataCustomer(customerList customerList) {
    adr_customer addressCustomer = customerList.first;
    int customerCount = 1;
    while (addressCustomer != nullptr) {
        cout << "====== CUSTOMER DATA " << customerCount << " ======" << endl;
        cout << "Customer Name    :   " << addressCustomer->name << endl;
        cout << "Customer ID      :   " << addressCustomer->customer_id << endl;
        cout << "Customer Status  :   " << addressCustomer->status << endl;
        addressCustomer = addressCustomer->next;
        customerCount++;
    }
}

void printDataVehicle(customerList customerList, string customer_id) {
    adr_customer addressCustomer = findCustomerAddress(customerList, customer_id);
    adr_vehicle addressVehicle = addressCustomer->vehicle;
    int vehicleCount = 1;
    cout << "====== Vehicle List " << addressCustomer->name << " ======" << endl;
    if (addressVehicle == nullptr) {
        cout << "There is no vehicle assigned to this customer" << endl;
        return;
    }
    while (addressVehicle != nullptr) { // Printing the Vehicle inside the customer
        cout << "Vehicle      : " << vehicleCount << endl;
        cout << "Brand        : " << addressVehicle->brand << endl;
        cout << "ID           : " << addressVehicle->vehicle_id << endl;
        cout << "Type         : " << addressVehicle->car_type << endl;
        cout << "Model        : " << addressVehicle->model << endl;
        cout << "Year         : " << addressVehicle->year << endl;
        cout << "Status       : " << addressVehicle->status << endl;
        cout << endl;
        addressVehicle = addressVehicle->next;
        vehicleCount++;
    }
}

adr_vehicle findVehicleAddress(adr_customer addressCustomer, string vehicle_id) {
    adr_vehicle addressVehicle = addressCustomer->vehicle;
    while (addressVehicle != nullptr) {
        if (addressVehicle->vehicle_id == vehicle_id) {
            return addressVehicle;
        }
        addressVehicle = addressVehicle->next;
    }
    cout << "There is no such vehicle with this ID" << endl;
    return nullptr;
}

bool checkAllVehicleStatus(adr_customer customer) {
    adr_vehicle addressVehicle = customer->vehicle;
    if (addressVehicle != nullptr) {
        while (addressVehicle != nullptr) {
            if (addressVehicle->status != DONE) {
                return false;
            }
            addressVehicle = addressVehicle->next;
        }
        return true;
    }
    return false;
}

void updateCustomerStatus(adr_customer &customer) {
    if (checkAllVehicleStatus(customer)) {
        customer->status = DONE;
    } else {
        customer->status = IN_PROGRESS;
    }
}

void updateAllCustomer(customerList &customerList) {
    adr_customer addressCustomer = customerList.first;
    while (addressCustomer != nullptr) {
        updateCustomerStatus(addressCustomer);
        addressCustomer = addressCustomer->next;
    }
}

void updateVehicleStatusTemporary(adr_vehicle &vehicle, string vehicleStatus) { //this is just temporary please to not use this in future use ! .. instead use the one below or fix it
    vehicle->status = vehicleStatus;
}

/*
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
    if(checkAllDamageStatus(vehicle, DONE)) {
        vehicle->status = DONE;
    }
}

adr_damage CreateElementDamage(adr_damage AD,string title, string explanation, string status, string damage_id);
void insertLastDamage(customerList customerList, adr_damage AD);
*/

void deleteDamage(adr_vehicle &vehicle, string idToDelete) {
    if(vehicle->damage != nullptr) {
        adr_damage damageToDelete;
        if(vehicle->damage->damage_id != idToDelete) {
            adr_damage i = vehicle->damage;
            while(i->next->damage_id != idToDelete && i != nullptr) {
                i = i->next;
            }
            if(i == nullptr) {
                cout << "There is no such damage with this ID" << endl;
                return;
            }
            damageToDelete = i->next;
            i->next = damageToDelete->next;
            damageToDelete->next = nullptr;
        }
        else {
            damageToDelete = vehicle->damage;
            vehicle->damage = damageToDelete->next;
            damageToDelete->next = nullptr;
        }
        delete damageToDelete;
    }
}

void deleteAllDamage(adr_vehicle &vehicle) {
    while(vehicle->damage != nullptr) {
        deleteDamage(vehicle, vehicle->damage->damage_id);
    }
}

void deleteVehicle(adr_customer &customer, string idToDelete) {
    if(customer->vehicle != nullptr) {
        adr_vehicle vehicleToDelete;
        if(customer->vehicle->vehicle_id != idToDelete) {
            adr_vehicle i = customer->vehicle;
            while(i->next->vehicle_id != idToDelete && i != nullptr) {
                i = i->next;
            }
            if(i == nullptr) {
                cout << "There is no such vehicle with this ID" << endl;
                return;
            }
            vehicleToDelete = i->next;
            i->next = vehicleToDelete->next;
            vehicleToDelete->next = nullptr;
        }
        else {
            vehicleToDelete = vehicle->damage;
            vehicle->damage = vehicleToDelete->next;
            vehicleToDelete->next = nullptr;
        }
        deleteAllDamage(vehicleToDelete);
        delete vehicleToDelete;
    }
}

void deleteAllVehicle(adr_customer &customer) {
    while(customer->vehicle != nullptr) {
        deleteDamage(customer, customer->vehicle->vehicle_id);
    }
}

void deleteCustomer(customerList &customerList, string idToDelete) {
    if(customerList.first != nullptr) {
        adr_customer customerToDelete;
        if(customerList.first->customer_id != idToDelete) {
            adr_customer i = customerList.first;
            while(i->next->customer_id != idToDelete && i != nullptr) {
                i = i->next;
            }
            if(i == nullptr) {
                cout << "There is no such customer with this ID" << endl;
                return;
            }
            customerToDelete = i->next;
            i->next = customerToDelete->next;
            customerToDelete->next = nullptr;
        }
        else {
            customerToDelete = vehicle->damage;
            vehicle->damage = customerToDelete->next;
            customerToDelete->next = nullptr;
        }
        deleteAllVehicle(customerToDelete);
        delete customerToDelete;
    }
}