#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct damage *adr_damage;
typedef struct vehicle *adr_vehicle;
typedef struct customer *adr_customer;

typedef struct damage{
    string title, explanation, status;
    adr_damage next;
};



typedef struct vehicle{
    string brand,car_type,model,status;
    int year;
    adr_damage damage;
    adr_vehicle next;
};



typedef struct customer{
    string name,id,status;
    adr_vehicle child;
    adr_customer next;
};


typedef struct customerList{
    adr_customer first;
};

void createListCustomer(customerList &C);
adr_customer CreateElementCustomerData(adr_customer AC,string name,string id,string status);
void insertLastCustomer(customerList &C, adr_customer AC);

adr_vehicle CreateElementVehicleData(adr_vehicle AV,string brand,string car_type,string model,string status, int year);
void insertLastVehicle(customerList &C, adr_vehicle AV);

/*adr_damage CreateElementDamage(adr_damage AD,string title, string explanation, string status);
void insertLastDamage(customerList &C, adr_damage AD);
*/
void printData(customerList C);


#endif MENU_H_INCLUDED