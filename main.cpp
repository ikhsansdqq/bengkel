#include "menu.h"

int main() {
    customerList C;

    adr_customer p;
    string name = "John Doe";
    string id, status;
    int num;

    cout << "Please input how many customers: ";
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

    cout<<"====== DATA ====="<<endl;
    printData(C);
    
    // createListCustomer(C);
    // p = CreateElementCustomerData(p, "Fauzan", "FPS001", "BERES");
    // insertLastCustomer(C,p);
    // p = CreateElementCustomerData(p, "Alam", "AHH001", "BELUM BERES");
    // insertLastCustomer(C,p);

    return 0;
}