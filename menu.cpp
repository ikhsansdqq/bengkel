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

void printDataCustomer(customerList customerList,string customerID) {
    adr_customer addressCustomer = findCustomerAddress(customerList,customerID);
    if(addressCustomer == nullptr) {
        return;
    }
    cout << "Customer Name    :   " << addressCustomer->name << endl;
    cout << "Customer ID      :   " << addressCustomer->customer_id << endl;
    cout << "Customer Status  :   " << addressCustomer->status << endl;
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

void deleteCustomer(customerList &customerList, string idToDelete) {
    if(customerList.first != nullptr) {
        adr_customer customerToDelete;
        if(customerList.first->customer_id != idToDelete) {
            adr_customer i = customerList.first;
            while(i->next->customer_id != idToDelete) {
                i = i->next;
            }
            customerToDelete = i->next;
            i->next = customerToDelete->next;
            customerToDelete->next = nullptr;
        }
        else {
            customerToDelete = customerList.first;
            customerList.first = customerToDelete->next;
            customerToDelete->next = nullptr;
        }
        deleteAllVehicle(customerToDelete);
        delete customerToDelete;
    }
}

adr_vehicle CreateElementVehicleData(adr_vehicle addressVehicle, string brand, string vehicle_id, string car_type, string model, int year) { //Creating element for Vehicle BOX aka The data to some customer
    addressVehicle = new vehicle;
    addressVehicle->brand = brand;
    addressVehicle->vehicle_id = vehicle_id;
    addressVehicle->car_type = car_type;
    addressVehicle->model = model;
    addressVehicle->status = NO_DAMAGE_ASSIGNED;
    addressVehicle->year = year;
    addressVehicle->damage = nullptr;
    addressVehicle->next = nullptr;
    return addressVehicle;
}

void insertLastVehicle(customerList &customerList, string customer_id, adr_vehicle addressVehicle) {
    adr_customer addressCustomer = findCustomerAddress(customerList, customer_id);
    if (addressCustomer == nullptr) {
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

void printDataVehicle(customerList customerList, string customer_id) {
    adr_customer addressCustomer = findCustomerAddress(customerList, customer_id);
    if(addressCustomer == nullptr) {
        return;
    }
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

void printPerDataVehicle(adr_vehicle addressVehicle) {
    cout << "====== Vehicle List ======" << endl;
    if (addressVehicle == nullptr) {
        cout << "There is no vehicle assigned to this customer" << endl;
        return;
    }
    cout << "Brand        : " << addressVehicle->brand << endl;
    cout << "ID           : " << addressVehicle->vehicle_id << endl;
    cout << "Type         : " << addressVehicle->car_type << endl;
    cout << "Model        : " << addressVehicle->model << endl;
    cout << "Year         : " << addressVehicle->year << endl;
    cout << "Status       : " << addressVehicle->status << endl;
    cout << endl;
}

void updateVehicleStatus(adr_vehicle &vehicle) {
    if(checkAllDamageStatus(vehicle)) {
        vehicle->status = DONE;
    }
}

adr_damage CreateElementDamageData(adr_damage addressDamage,string title,string explanation, string status,string damage_id){
    addressDamage = new damage;
    addressDamage->title = title;
    addressDamage->explanation = explanation;
    addressDamage->status = status;
    addressDamage->damage_id = damage_id;
    addressDamage->next = nullptr;

    return addressDamage;
}

void insertDamage(customerList &customerList,string customer_id,string vehicle_id, adr_damage addressDamage){
    adr_customer addressCustomer = findCustomerAddress(customerList, customer_id);
    if (addressCustomer == nullptr) {
        return;
    }

    adr_vehicle addressVehicle = findVehicleAddress(addressCustomer, vehicle_id);
    if(addressVehicle == nullptr) {
        return;
    }
    addressVehicle->status = IN_PROGRESS;
    adr_damage addressDamage2 = addressVehicle->damage;
    if (addressDamage2 == nullptr) {
        addressVehicle->damage = addressDamage;
        return;
    }

    while (addressDamage2->next != nullptr) {
        addressDamage2 = addressDamage2->next;
    }
    addressDamage2->next = addressDamage;
}

adr_damage findDamageAddress(adr_vehicle addressVehicle, string damage_id) {
    adr_damage addressDamage = addressVehicle->damage;
    while (addressDamage != nullptr) {
        if (addressDamage->damage_id == damage_id) {
            return addressDamage;
        }
        addressDamage = addressDamage->next;
    }
    cout << "There is no such Damage with this ID" << endl;
    return nullptr;
}

void deleteDamage(adr_vehicle &vehicle, string idToDelete) {
    if(vehicle->damage != nullptr) {
        adr_damage damageToDelete;
        if(vehicle->damage->damage_id != idToDelete) {
            adr_damage i = vehicle->damage;
            while(i->next->damage_id != idToDelete && i != nullptr) {
                i = i->next;
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
            while(i->next->vehicle_id != idToDelete) {
                i = i->next;
            }
            vehicleToDelete = i->next;
            i->next = vehicleToDelete->next;
            vehicleToDelete->next = nullptr;
        }
        else {
            vehicleToDelete = customer->vehicle;
            customer->vehicle = vehicleToDelete->next;
            vehicleToDelete->next = nullptr;
        }
        deleteAllDamage(vehicleToDelete);
        delete vehicleToDelete;
    }
}

void deleteAllVehicle(adr_customer &customer) {
    while(customer->vehicle != nullptr) {
        deleteVehicle(customer, customer->vehicle->vehicle_id);
    }
}

bool checkAllDamageStatus(adr_vehicle vehicle) {
    adr_damage addressDamage = vehicle->damage;
    if (addressDamage != nullptr) {
        while (addressDamage != nullptr) {
            if (addressDamage->status != DONE) {
                return false;
            }
            addressDamage = addressDamage->next;
        }
        return true;
    }
    return false;
}

void printDataDamage(customerList customerList, string customer_id, string vehicle_id){
    adr_customer addressCustomer = findCustomerAddress(customerList, customer_id);
    if(addressCustomer == nullptr) {
        return;
    }
    adr_vehicle addressVehicle = findVehicleAddress(addressCustomer, vehicle_id);
    if(addressVehicle == nullptr) {
        return;
    }
    adr_damage addressDamage = addressVehicle->damage;
    int DamageCount = 1;
    cout << "====== Damage List for " << addressCustomer->name << " with vehicle id number : "<< addressVehicle->vehicle_id <<" ======" << endl;
    if (addressDamage == nullptr) {
        cout << "This vehicle has no damages." << endl;
        return;
    }
    while (addressDamage != nullptr) { // Printing the Vehicle inside the customer
        cout << "Damage     : " << DamageCount << endl;
        cout << "Title      : " << addressDamage->title << endl;
        cout << "Explanation: " << addressDamage->explanation << endl;
        cout << "Status     : " << addressDamage->status << endl;
        cout << "Damage ID  : " << addressDamage->damage_id << endl;
        cout << endl;
        addressDamage = addressDamage->next;
        DamageCount++;
    }
}

void updateDamageStatus(adr_damage &damage, string damageStatus) {
    damage->status = damageStatus;
}

void printEasterEgg(){
    cout << NO_BITCHES << endl;
}

int selectMenu(){
    cout<<"====== MENU ======"<<endl;
    cout<<"1. Add Customer"<<endl;
    cout<<"2. Add Vehicle"<<endl;
    cout<<"3. Add Damage"<<endl;
    cout<<"4. Show All Data"<<endl;
    cout<<"5. Show All Customer"<<endl;
    cout<<"6. Show All Vehicle (1 Customer)"<<endl;
    cout<<"7. Show All Damage (1 Vehicle)"<<endl;
    cout<<"8. Update Damage (will update customer and vehicle too)"<<endl;
    cout<<"9. Delete Customer"<<endl;
    cout<<"10. Delete All Vehicle"<<endl;
    cout<<"11. Delete All Damage"<<endl;
    cout<<"12. Delete Certain Vehicle"<<endl;
    cout<<"13. Delete Certain Damage"<<endl;
    cout<<"14. Update Data (Just in Case something broken)"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Input menu: ";
    int input = 0;
    cin >>input;
    return input;

}
