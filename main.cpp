#include "menu.h"

int main() {
    customerList customerList{};
    adr_customer addressCustomer = nullptr;
    adr_vehicle addressVehicle = nullptr;
    adr_damage addressDamage = nullptr;
    int pilihan, vehicleyear;
    string recalled, customerName, customerID, vehicleBrand, vehicleID, vehicleType, vehicleModel, vehicleStatus, damageTitle, damageExp, damageStat, damageID, yesNo;
    createListCustomer(customerList);
    pilihan = selectMenu();
    while (pilihan != 0) {
        switch (pilihan) {
            case 1:
                cout << "Input Customer name     : ";
                cin >> customerName;
                cout << "Input Customer ID       : ";
                cin >> customerID;
                addressCustomer = CreateElementCustomerData(addressCustomer, customerName, customerID);
                insertLastCustomer(customerList, addressCustomer);
                break;
            case 2:
                cout << "Input Vehicle Brand : ";
                cin >> vehicleBrand;
                cout << "Input Vehicle ID    : ";
                cin >> vehicleID;
                cout << "Input Vehicle Type  : ";
                cin >> vehicleType;
                cout << "Input Vehicle Model : ";
                cin >> vehicleModel;
                cout << "Input Vehicle Year  : ";
                cin >> vehicleyear;
                cout << "Input Customer ID   : ";
                cin >> customerID;
                addressVehicle = CreateElementVehicleData(addressVehicle, vehicleBrand, vehicleID, vehicleType,
                                                          vehicleModel, vehicleyear);
                insertLastVehicle(customerList, customerID, addressVehicle);
                break;
            case 3:
                cout << "Input CustomerID   : ";
                cin >> customerID;
                cout << "Input VehicleID    : ";
                cin >> vehicleID;
                cout << "Input Damage Title : ";
                cin >> damageTitle;
                cout << "Input Damage Explanation  : ";
                cin >> damageExp;
                cout << "Input Damage ID    : ";
                cin >> damageID;
                damageStat = IN_PROGRESS;
                addressDamage = CreateElementDamageData(addressDamage, damageTitle, damageExp, damageStat, damageID);
                insertDamage(customerList, customerID, vehicleID, addressDamage);
                break;
            case 4:
                cout << "========== Printing Customer =========" << endl;
                printAllDataCustomer(customerList);
                addressCustomer = customerList.first;
                if (addressCustomer == nullptr) {
                    cout << "There are no customers yet. Add data please." << endl;
                }
                while (addressCustomer != nullptr) {
                    printDataCustomer(customerList, addressCustomer->customer_id);
                    addressVehicle = addressCustomer->vehicle;
                    while (addressVehicle != nullptr) {
                        printPerDataVehicle(addressVehicle);
                        printDataDamage(customerList, addressCustomer->customer_id, addressVehicle->vehicle_id);
                        addressVehicle = addressVehicle->next;
                    }
                    addressCustomer = addressCustomer->next;
                }
                break;
            case 5:
                printAllDataCustomer(customerList);
                break;
            case 6:
                cout << "Input CustomerID    :";
                cin >> customerID;
                printDataVehicle(customerList, customerID);
                break;
            case 7:
                cout << "Input CustomerID    :";
                cin >> customerID;
                cout << "Input VehicleID    :";
                cin >> vehicleID;
                printDataDamage(customerList, customerID, vehicleID);
                break;
            case 8:
                cout << "Input CustomerID    :";
                cin >> customerID;
                cout << "Input VehicleID     : ";
                cin >> vehicleID;
                cout << "Damage ID           : ";
                cin >> damageID;
                cout << "Status (DONE or IN_PROGRESS)    : ";
                cin >> damageStat;
                addressCustomer = findCustomerAddress(customerList, customerID);
                addressVehicle = findVehicleAddress(addressCustomer, vehicleID);
                addressDamage = findDamageAddress(addressVehicle, damageID);
                updateDamageStatus(addressDamage, damageStat);
                updateVehicleStatus(addressVehicle);
                updateAllCustomer(customerList);
                break;
            case 9:
                cout << "=== DELETE CUSTOMER ===" << endl;
                cout << "Input Customer ID    : ";
                cin >> customerID;
                addressCustomer = findCustomerAddress(customerList, customerID);
                deleteCustomer(customerList, customerID);
                updateAllCustomer(customerList);
                break;
            case 10:
                cout << "=== DELETE ALL VEHICLES ===" << endl;
                cout << "Search Customer ID    : ";
                cin >> customerID;
                addressVehicle = findVehicleAddress(addressCustomer, vehicleID);
                deleteAllVehicle(addressCustomer);
                updateAllCustomer(customerList);
                // Masih Perbaikan
                break;
            case 11:
                cout << "=== DELETE ALL DAMAGES ===" << endl;
                cout << "Input Customer ID    : ";
                cin >> customerID;
                deleteAllDamage(addressVehicle);
                updateAllCustomer(customerList);
                updateDamageStatus(addressDamage, damageStat);
                // DONE
                break;
            case 12:
                cout << "==== DELETE CERTAIN VEHICLE ====" << endl;
                cout << "Search for Vehicle ID: ";
                cin >> vehicleID;
                deleteVehicle(addressCustomer, vehicleID);
                updateAllCustomer(customerList);
                break;
            case 13:
                cout << "=== DELETE CERTAIN DAMAGES ===" << endl;
                cout << "Search for Damages ID: ";
                cin >> damageID;
                deleteDamage(addressVehicle, damageID);
                break;
            case 14:
                cout << "==== UPDATE DATA ====" << endl;
                break;
            case 15:
                cout << "======= THIS IS JUST A PROCEDURE AND FUNCTION TEST =======" << endl;
                cout << "Testing by input 2 customer data" << endl;
                cout << "==========" << endl;
                addressCustomer = CreateElementCustomerData(addressCustomer, "Fauzan", "FRM001");
                insertLastCustomer(customerList, addressCustomer);
                addressCustomer = CreateElementCustomerData(addressCustomer, "Alam", "ARP001");
                insertLastCustomer(customerList, addressCustomer);
                printAllDataCustomer(customerList);
                printDataVehicle(customerList, "FRM001");

                cout << endl;

                cout << "Testing by input 2 vehicle data and update customer status" << endl;
                cout << "==========" << endl;
                addressVehicle = CreateElementVehicleData(addressVehicle, "Toyota", "TS-98", "SUV", "Land Cruiser",
                                                          1998);
                insertLastVehicle(customerList, "FRM001", addressVehicle);
                addressVehicle = CreateElementVehicleData(addressVehicle, "Ford", "FT-80", "Truck", "F150", 1980);
                insertLastVehicle(customerList, "ARP001", addressVehicle);
                updateAllCustomer(customerList);
                printAllDataCustomer(customerList);
                cout << endl;
                printDataVehicle(customerList, "FRM001");
                printDataVehicle(customerList, "ARP001");
                cout << endl;

                cout << "Testing by input 2 vehicle data and update customer status and vehicle status" << endl;
                cout << "==========" << endl;
                addressDamage = CreateElementDamageData(addressDamage, "Mesin", "Salah masukin oli", IN_PROGRESS,
                                                        "ABC");
                insertDamage(customerList, "FRM001", "TS-98", addressDamage);
                addressDamage = CreateElementDamageData(addressDamage, "Body", "Lecet", IN_PROGRESS, "DEF");
                insertDamage(customerList, "ARP001", "FT-80", addressDamage);
                updateAllCustomer(customerList);
                printAllDataCustomer(customerList);
                cout << endl;
                printDataVehicle(customerList, "ARP001");
                cout << endl;
                printDataDamage(customerList, "ARP001", "FT-80");

                cout << endl;

                cout << "========= Damage Status on Vehicle Test in for ARP001 =========" << endl;
                cout << "Before Updating" << endl;
                printDataVehicle(customerList, "ARP001");
                cout << "After Updating" << endl;
                addressCustomer = findCustomerAddress(customerList, "ARP001");
                addressVehicle = findVehicleAddress(addressCustomer, "FT-80");
                addressDamage = findDamageAddress(addressVehicle, "DEF");
                updateDamageStatus(addressDamage, DONE);
                printDataDamage(customerList, "ARP001", "FT-80");
                updateVehicleStatus(addressVehicle);
                updateAllCustomer(customerList);
                printDataVehicle(customerList, "ARP001");

                addressDamage = findDamageAddress(addressVehicle, "DEF");
                cout << "Delete damage to customer side (Alam)" << endl;
                cout << "==========" << endl;
                cout << "Before Delete" << endl;
                printDataDamage(customerList, "ARP001", "FT-80");

                cout << "After Delete" << endl;
                addressCustomer = findCustomerAddress(customerList, "ARP001");
                addressVehicle = findVehicleAddress(addressCustomer, "FT-80");
                deleteDamage(addressVehicle, "DEF");
                printDataDamage(customerList, "ARP001", "FT-80");

                cout << endl;
                cout << "Delete vehicle to customer side (Fauzan Vehicle)" << endl;
                cout << "==========" << endl;

                cout << "Before Delete" << endl;
                printDataVehicle(customerList, "FRM001");

                cout << "After Delete" << endl;
                addressCustomer = findCustomerAddress(customerList, "FRM001");
                deleteVehicle(addressCustomer, "TS-98");
                printDataVehicle(customerList, "FRM001");

                cout << endl;
                cout << endl;

                cout << "Delete all vechicle" << endl;
                cout << "==========" << endl;

                cout << "Before Delete" << endl;
                printDataVehicle(customerList, "ARP001");

                cout << "After Delete" << endl;
                addressCustomer = findCustomerAddress(customerList, "ARP001");
                deleteAllVehicle(addressCustomer);
                printDataVehicle(customerList, "ARP001");
                cout << endl;
                cout << endl;
                cout << "Delete customer to customer side (Fauzan Vechile)" << endl;
                cout << "==========" << endl;

                cout << "Before Delete" << endl;
                printAllDataCustomer(customerList);

                cout << endl;
                cout << "After Delete" << endl;
                deleteCustomer(customerList, "FRM001");
                printAllDataCustomer(customerList);

                cout << endl;
                break;
        }
        cout << "Back to main menu? (Y/N) : ";
        cin >> recalled;
        if (recalled == "Y" || recalled == "y") {
            pilihan = selectMenu();
        } else {
            break;
        }
    }

    return 0;
}
