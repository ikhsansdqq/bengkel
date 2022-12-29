#include "menu.h"

void createListCustomer(customerList &customerList){
    customerList.first = NULL;
}

adr_customer CreateElementCustomerData(adr_customer addressCustomer,string name,string customer_id,string status){
    addressCustomer = new customer;
    addressCustomer->name = name;
    addressCustomer->customer_id = customer_id;
    addressCustomer->status = status;
    addressCustomer->child = NULL;
    addressCustomer->next = NULL;
    return addressCustomer;
}


void insertLastCustomer(customerList &customerList, adr_customer addressCustomer){
    if (customerList.first == NULL){
        customerList.first = addressCustomer;
        return;
    }
    adr_customer addressCustomer2 = customerList.first;
    while (addressCustomer2->next != NULL){
        addressCustomer2 = addressCustomer2->next;
    }
    addressCustomer2->next = addressCustomer;

}
adr_vehicle CreateElementVehicleData(adr_vehicle addressVehicle,string brand,string car_type,string model,string status, int year) { //Creating element for Vehicle BOX aka The data to some customer
    addressVehicle = new vehicle;
    addressVehicle->brand = brand;
    addressVehicle->car_type = car_type;
    addressVehicle->model = model;
    addressVehicle->status = status;
    addressVehicle->year = year;
    addressVehicle->damage= NULL;
    addressVehicle->next = NULL;
    return addressVehicle;
}

adr_customer findCustomerAddress(customerList customerList,string customer_id){
    adr_customer addressCustomer = customerList.first;
    while (addressCustomer != NULL){
        if (addressCustomer->customer_id == customer_id){
            return addressCustomer;
        }
        addressCustomer = addressCustomer->next;
    }
    cout<<"There is no such customer with this ID"<<endl;
    return NULL;
}


void insertLastVehicle(customerList &customerList, vehicleList &vehicleList,string customer_id, adr_vehicle addressVehicle) {
    adr_customer addressCustomer = findCustomerAddress(customerList,customer_id);
    if(addressCustomer == NULL){
        cout<<"There is no such customer with this ID"<<endl;
        return;
    }

    adr_vehicle addressVehicle2 = addressCustomer->child;
    if (addressVehicle2== NULL){
        addressCustomer->child = addressVehicle;
        cout<<addressVehicle->brand<<endl;
        return;
    }

    while (addressVehicle2->next != NULL){
        addressVehicle2 = addressVehicle2->next;
    }
    addressVehicle2->next = addressVehicle;
}

/*
adr_damage CreateElementDamage(adr_damage AD,string title, string explanation, string status);
void insertLastDamage(customerList customerList, adr_damage AD);
*/

void printData(customerList customerList){
    adr_customer addressCustomer = customerList.first;
    adr_vehicle addressVehicle;
    int customerCount = 1, vehicleCount;
    while (addressCustomer != NULL){
        cout<<"====== CUSTOMER DATA "<<customerCount<<" ======"<<endl;
        cout << "Customer Name    :   "<< addressCustomer->name <<endl;
        cout << "Customer ID      :   "<< addressCustomer->customer_id <<endl;
        cout << "Customer Status  :   "<< addressCustomer->status <<endl; // e.g. Status = "Selesai" or Status = "Dalam pengerjaan"


        addressVehicle = addressCustomer->child;
        vehicleCount = 1; //resetting the counter after displaying all the vehicle on previous customer

        cout<<"====== Vehicle List ======"<<endl;
        if(addressVehicle == NULL){
            cout<<"There is no vehicle assigned to this customer"<<endl;
            return;
        }
        while(addressVehicle != NULL){ // Printing the Vehicle inside the customer
            cout<<"Vehicle      : "<<vehicleCount<<endl;
            cout<<"Brand        : "<<addressVehicle->brand<<endl;
            cout<<"Type         : "<<addressVehicle->car_type<<endl;
            cout<<"Model        : "<<addressVehicle->model<<endl;
            cout<<"Year         : "<<addressVehicle->year<<endl;
            cout<<"Status       : "<<addressVehicle->status<<endl;
            cout<<endl;
            addressVehicle = addressVehicle->next;
            vehicleCount++;
        }
        addressCustomer = addressCustomer->next;
        customerCount++;


    }
}
