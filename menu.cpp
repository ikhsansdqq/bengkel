#include "menu.h"

void createListCustomer(customerList &C){
    C.first = NULL;
}

adr_customer CreateElementCustomerData(adr_customer AC,string name,string id,string status){
    AC = new customer;
    AC->name = name;
    AC->id = id;
    AC->status = status;
    AC->child = NULL;
    AC->next = NULL;
    return AC;
}

void insertLastCustomer(customerList &C, adr_customer AC){
    if (C.first == NULL){
        C.first = AC;
    }
    adr_customer ACC = C.first;
    while (ACC->next != NULL){
        ACC = ACC->next;
    }
    ACC = AC;

}
adr_vehicle CreateElementVehicleData(adr_vehicle AV,string brand,string car_type,string model,string status, int year) {
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
void insertLastVehicle(customerList &C, adr_vehicle AV, string customerId) {
    adr_customer p = C;
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

void printData(customerList C){
    adr_customer AC = C.first;
    while (AC != NULL){
        cout<<"Name : "<<AC->name<<endl;
        cout<<"ID : "<<AC->id<<endl;
        cout<<"Status : "<<AC->status<<endl;
        adr_vehicle AV = AC->child;
        while(AV != NULL){
            cout<<
        }
        AC = AC->next;
    }
}