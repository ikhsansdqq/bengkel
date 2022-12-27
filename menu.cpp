#include "menu.h"

void createListCustomer(customerList &C){ //Create first list
    C.first = NULL;
}

adr_customer CreateElementCustomerData(adr_customer AC,string name,string id,string status){ //Creating element for Customer BOX aka the Data
    AC = new customer;
    AC->name = name;
    AC->id = id;
    AC->status = status;
    AC->child = NULL;
    AC->next = NULL;
    return AC;
}


void insertLastCustomer(customerList &C, adr_customer AC){ //Inserting last the customer
    if (C.first == NULL){
        C.first = AC;
        return;
    }
    adr_customer ACC = C.first;
    while (ACC->next != NULL){
        ACC = ACC->next;
    }
    ACC->next = AC;

}
adr_vehicle CreateElementVehicleData(adr_vehicle AV,string brand,string car_type,string model,string status, int year) { //Creating element for Vehicle BOX aka The data to some customer
    AV = new vehicle;
    AV->brand = brand;
    AV->car_type = car_type;
    AV->model = model;
    AV->status = status;
    AV->year = year;
    AV->damage= NULL;
    AV->next = NULL;
    return AV;
}
void insertLastVehicle(customerList &C, adr_vehicle AV, string customerId) { //Inserting last in the vehicle list
    adr_customer p = C.first;
    while(p != NULL && p->id != customerId) {
        p = p->next;
    }
    if(p != NULL) {
        if(p->child != NULL) {
            p->child = AV;
        }
        else {
            adr_vehicle q = p->child;
            while(q->next != NULL) {
                q = q->next;
            }
            q->next = AV;
        }
    }
}

/*
adr_damage CreateElementDamage(adr_damage AD,string title, string explanation, string status);
void insertLastDamage(customerList &C, adr_damage AD);
*/

void printData(customerList C){ //Print the data
    adr_customer AC = C.first;
    int customerCount = 1, vehicleCount;
    while (AC != NULL){ //Printing the Customer
        cout<<"Customer "<<customerCount<<endl;
        cout<<"Name : "<<AC->name<<endl;
        cout<<"ID : "<<AC->id<<endl;
        cout<<"Status : "<<AC->status<<endl;

        /*
        adr_vehicle AV = AC->child;
        vehicleCount = 1; //resetting the counter after displaying all the vehicle on previous customer

        cout<<"====== Vehicle List ======"<<endl;
        while(AV != NULL){ // Printing the Vehicle inside the customer
            cout<<"Vehicle "<<vehicleCount<<endl;
            cout<<"Brand: "<<AV->brand<<endl;
            cout<<"Type: "<<AV->car_type<<endl;
            cout<<"Model: "<<AV->model<<endl;
            cout<<"Year: "<<AV->year<<endl;
            cout<<"Status: "<<AV->status<<endl;
            AV = AV->next;
            vehicleCount++;
        }
        */
       //printing vehicle gonna be hold until insertLastVehicle is fixed
        AC = AC->next;
        customerCount++;
    }
}