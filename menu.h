#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
using namespace std;

const string DONE = "DONE";
const string IN_PROGRESS = "IN PROGRESS";
const string NO_VEHICLE_ASSIGNED = "NO VEHICLE ASSIGNED";

typedef struct damage *adr_damage;
typedef struct vehicle *adr_vehicle;
typedef struct customer *adr_customer;

struct damage{
    string title, explanation, status, damage_id;
    adr_damage next;
};

struct vehicle{
    string brand,car_type,model, status,vehicle_id;
    int year;
    adr_damage damage;
    adr_vehicle next;
};

struct customer{
    string name,customer_id,status;
    adr_vehicle vehicle;
    adr_customer next;
};

struct customerList{
    adr_customer first;
};

void createListCustomer(customerList &customerList);
adr_customer CreateElementCustomerData(adr_customer addressCustomer,string name,string customer_id);
void insertLastCustomer(customerList &customerList, adr_customer addressCustomer);
adr_vehicle CreateElementVehicleData(adr_vehicle addressVehicle,string brand,string vehicle_id, string car_type,string model,string status, int year);
void insertLastVehicle(customerList &customerList,string customer_id,adr_vehicle addressVehicle);
adr_customer findCustomerAddress(customerList customerList,string customer_id);
void printAllDataCustomer(customerList customerList);
void printDataVehicle(customerList customerList, string customer_id);
adr_vehicle findVehicleAddress(adr_customer addressCustomer, string vehicle_id);
bool checkAllVehicleStatus(adr_customer customer);
void updateCustomerStatus(adr_customer &customer);
void updateAllCustomer(customerList &customerList);
void updateVehicleStatusTemporary(adr_vehicle &vehicle,string vehicleStatus);

void deleteDamage(adr_vehicle &vehicle, string idToDelete);
void deleteAllDamage(adr_vehicle &vehicle);
void deleteVehicle(adr_customer &customer, string idToDelete);
void deleteAllVehicle(adr_customer &customer);
void deleteCustomer(customerList &customerList, string idToDelete);

adr_damage CreateElementDamageData(adr_damage addressDamage,string title,string explanation, string status,string damage_id);
void insertDamage(customerList &customerList,string customer_id,string vehicle_id, adr_damage addressDamage);
void printDataDamage(customerList customerList, string customer_id, string vehicle_id);

#endif //MENU_H_INCLUDED
