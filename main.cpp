#include "menu.h"

int main() {
    customerList customerList{};
    adr_customer addressCustomer = nullptr;
    adr_vehicle addressVehicle = nullptr;
    adr_damage addressDamage = nullptr;
    int pilihan, vehicleyear, howMany;
    string recalled, customerName, customerID, vehicleBrand, vehicleID, vehicleType, vehicleModel, vehicleStatus, damageTitle, damageExp, damageStat, damageID, yesNo;
    createListCustomer(customerList);
    pilihan = selectMenu();
    while (pilihan != 0) {
        switch (pilihan) {
            default:
                break;
            case 1:
                cout << "===== INPUT CUSTOMER =====" << endl;
                cout << "How many Customer : ";
                cin >> howMany;
                for (int i = 0; i < howMany; ++i) {
                    cout << "Input Customer name     : ";
                    cin.ignore();
                    getline(cin, customerName, '\n');
                    cout << "Input Customer ID       : ";
                    cin >> customerID;
                    addressCustomer = CreateElementCustomerData(addressCustomer, customerName, customerID);
                    insertLastCustomer(customerList, addressCustomer);
                }
                break;
            case 2:
                cout << "===== INPUT VEHICLE =====" << endl;
                cout << "How many Vehicle : ";
                cin >> howMany;
                for (int i = 0; i < howMany; ++i) {
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
                }
                break;
            case 3:
                cout << "===== INPUT DAMAGE =====" << endl;
                cout << "Input CustomerID   : ";
                cin >> customerID;
                cout << "Input VehicleID    : ";
                cin >> vehicleID;
                cout << "Input Damage Title : ";
                cin.ignore();
                getline(cin, damageTitle, '\n');
                cout << "Input Damage Explanation  : ";
                cin.ignore();
                getline(cin, damageExp, '\n');
                cout << "Input Damage ID    : ";
                cin >> damageID;
                damageStat = IN_PROGRESS;
                addressDamage = CreateElementDamageData(addressDamage, damageTitle, damageExp, damageStat, damageID);
                insertDamage(customerList, customerID, vehicleID, addressDamage);
                break;
            case 4:
                cout << "========== PRINT CUSTOMER =========" << endl;
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
                cout << "========== PRINT VEHICLE =========" << endl;
                cout << "Input CustomerID    :";
                cin >> customerID;
                printDataVehicle(customerList, customerID);
                break;
            case 7:
                cout << "========== PRINT DAMAGE =========" << endl;
                cout << "Input CustomerID    :";
                cin >> customerID;
                cout << "Input VehicleID    :";
                cin >> vehicleID;
                printDataDamage(customerList, customerID, vehicleID);
                break;
            case 8:
                cout << "========== UPDATE DAMAGE =========" << endl;
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
//                if (addressCustomer == nullptr) {
//                    break;
//                }
                if (addressCustomer != nullptr) {
                    deleteCustomer(customerList, customerID);
                    updateAllCustomer(customerList);
                } else {
                    cout << "Customer is not found" << endl;
                    break;
                }
//                deleteCustomer(customerList, customerID);
//                updateAllCustomer(customerList);
                break;
            case 10:
                cout << "=== DELETE ALL VEHICLES ===" << endl;
                cout << "Search Customer ID    : ";
                cin >> customerID;
                addressCustomer = findCustomerAddress(customerList, customerID);
                if (addressCustomer == nullptr) {
                    break;
                }
                deleteAllVehicle(addressCustomer);
                updateAllCustomer(customerList);
                break;
            case 11:
                cout << "=== DELETE ALL DAMAGES ===" << endl;
                cout << "Input Customer ID    : ";
                cin >> customerID;
                cout << "Search for Vehicle ID: ";
                cin >> vehicleID;
                addressCustomer = findCustomerAddress(customerList, customerID);
                if (addressCustomer == nullptr) {
                    break;
                }
                addressVehicle = findVehicleAddress(addressCustomer, vehicleID);
                if (addressVehicle == nullptr) {
                    break;
                }
                deleteAllDamage(addressVehicle);
                updateAllCustomer(customerList);
                updateDamageStatus(addressDamage, damageStat);
                // DONE
                break;
            case 12:
                cout << "==== DELETE CERTAIN VEHICLE ====" << endl;
                cout << "Search for Customer ID: ";
                cin >> customerID;
                cout << "Search for Vehicle ID: ";
                cin >> vehicleID;
                addressCustomer = findCustomerAddress(customerList, customerID);
//                if (addressCustomer == nullptr) {
//                    break;
//                }
                if (addressCustomer != nullptr) {
                    deleteVehicle(addressCustomer, vehicleID);
//                updateAllCustomer(customerList);
                } else {
                    break;
                }
//                deleteVehicle(addressCustomer, vehicleID);
//                updateAllCustomer(customerList);
                break;
            case 13:
                cout << "=== DELETE CERTAIN DAMAGES ===" << endl;
                cout << "Search for Customer ID: ";
                cin >> customerID;
                cout << "Search for Vehicle ID: ";
                cin >> vehicleID;
                cout << "Search for Damages ID: ";
                cin >> damageID;
                addressCustomer = findCustomerAddress(customerList, customerID);
                if (addressCustomer == nullptr) {
                    break;
                }
                addressVehicle = findVehicleAddress(addressCustomer, vehicleID);
                if (addressVehicle == nullptr) {
                    break;
                }
                deleteDamage(addressVehicle, damageID);
                updateAllCustomer(customerList);
                break;
            case 14:
                cout << "==== UPDATE DATA ====" << endl;
                if (customerList.first != nullptr) {
                    updateAllCustomer(customerList);
                    cout << "Update Data Success!" << endl;
                } else {
                    cout << "Data is empty" << endl;
                }
                cout << "==== DONE ====" << endl;
                break;
        }
        cout << "Back to main menu? (Y/N) : ";
        cin >> recalled;
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        if (recalled == "Y" || recalled == "y") {
            pilihan = selectMenu();
        } else {
            break;
        }
    }

    return 0;
}
