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
    string name,customer_id,status;
    adr_vehicle child;
    adr_customer next;
};


typedef struct customerList{
    adr_customer first;
};

typedef struct vehicleList{
    adr_vehicle first;
};

void createListCustomer(customerList &customerList);
adr_customer CreateElementCustomerData(adr_customer addressCustomer,string name,string customer_id,string status);
void insertLastCustomer(customerList &customerList, adr_customer addressCustomer);
adr_vehicle CreateElementVehicleData(adr_vehicle addressVehicle,string brand,string car_type,string model,string status, int year);
void insertLastVehicle(customerList &customerList, vehicleList &vehicleList,string customer_id,adr_vehicle addressVehicle);
adr_customer findCustomerAddress(customerList customerList,string customer_id);

/*adr_damage CreateElementDamage(adr_damage AD,string title, string explanation, string status);
void insertLastDamage(customerList &customerList, adr_damage AD);
*/

void printData(customerList customerList);


#endif MENU_H_INCLUDED
