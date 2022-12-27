#include "menu.h"

int main() {
    customerList C;
    adr_customer p;
    adr_vehicle v;
    string name, id, status;
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

    cout<<"====== CUSTOMER DATA ======"<<endl;
    printData(C);

    return 0;
}