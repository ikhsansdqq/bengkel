#include "menu.h"

int main() {
    customerList C;
    adr_customer p;
    adr_vehicle v;
    string name = "John Doe";
    string id, status;
    int num;

    createListCustomer(C);

    /*cout << "Please input how many customers: ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "Your full name: ";
        cin >> name;
        cout << "ID:";
        cin >> id;
        cout << "Status:";
        cin >> status;

        p = CreateElementCustomerData(p, name, id, status);
        insertLastCustomer(C, p);
    }
    */

    p = CreateElementCustomerData(p, "Fauzan", "FPS001", "BERES");
    insertLastCustomer(C,p);
    p = CreateElementCustomerData(p, "Alam", "AHH001", "BELUM BERES");
    insertLastCustomer(C,p);

    /*
    v = CreateElementVehicleData(v,"Toyota","SUV","Land Cruiser","Ded as hell",1998);
    insertLastVehicle(C,v,"FPS001");
    v = CreateElementVehicleData(v,"Ford","Truck","F150","Broken asf",1980);
    insertLastVehicle(C,v,"FPS001");
    */
    cout<<"====== DATA ====="<<endl;
    printData(C);
    
    
    

    return 0;
}