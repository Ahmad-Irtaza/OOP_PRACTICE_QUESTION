#include <iostream>
using namespace std;

enum etype
{
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

struct dateType
{
    int month;
    int day;
    int year;
};

struct employeeType
{
    int employeeNumber;
    float compensation;
    etype employeeType;
    dateType dateOfEmployment;
};

int main()
{
    employeeType employee1, employee2, employee3;

    cout << "Enter details for Employee 1:" << endl;
    cout << "Employee Number: ";
    cin >> employee1.employeeNumber;
    cout << "Compensation (in dollars): $";
    cin >> employee1.compensation;
    cout << "Employee Type [0=laborer, 1=secretary, 2=manager, 3=accountant, 4=executive, 5=researcher]: ";
    char typeChoice;
    cin >> typeChoice;
    switch (typeChoice)
    {
    case '0':
        employee1.employeeType = laborer;
        break;
    case '1':
        employee1.employeeType = secretary;
        break;
    case '2':
        employee1.employeeType = manager;
        break;
    case '3':
        employee1.employeeType = accountant;
        break;
    case '4':
        employee1.employeeType = executive;
        break;
    case '5':
        employee1.employeeType = researcher;
        break;
    default:
        cout << "Invalid employee type. Defaulting to laborer." << endl;
        employee1.employeeType = laborer;
        break;
    }
    cout << "Date of First Employment (MM/DD/YYYY): ";
    char delimiter;
    cin >> employee1.dateOfEmployment.month >> delimiter >> employee1.dateOfEmployment.day >> delimiter >> employee1.dateOfEmployment.year;

    cout << endl;

    cout << "Enter details for Employee 2:" << endl;
    cout << "Employee Number: ";
    cin >> employee2.employeeNumber;
    cout << "Compensation (in dollars): $";
    cin >> employee2.compensation;
    cout << "Employee Type [0=laborer, 1=secretary, 2=manager, 3=accountant, 4=executive, 5=researcher]: ";
    cin >> typeChoice;
    switch (typeChoice)
    {
    case '0':
        employee2.employeeType = laborer;
        break;
    case '1':
        employee2.employeeType = secretary;
        break;
    case '2':
        employee2.employeeType = manager;
        break;
    case '3':
        employee2.employeeType = accountant;
        break;
    case '4':
        employee2.employeeType = executive;
        break;
    case '5':
        employee2.employeeType = researcher;
        break;
    default:
        cout << "Invalid employee type. Defaulting to laborer." << endl;
        employee2.employeeType = laborer;
        break;
    }
    cout << "Date of First Employment (MM/DD/YYYY): ";
    cin >> employee2.dateOfEmployment.month >> delimiter >> employee2.dateOfEmployment.day >> delimiter >> employee2.dateOfEmployment.year;

    cout << endl;

    cout << "Enter details for Employee 3:" << endl;
    cout << "Employee Number: ";
    cin >> employee3.employeeNumber;
    cout << "Compensation (in dollars): $";
    cin >> employee3.compensation;
    cout << "Employee Type [0=laborer, 1=secretary, 2=manager, 3=accountant, 4=executive, 5=researcher]: ";
    cin >> typeChoice;
    switch (typeChoice)
    {
    case '0':
        employee3.employeeType = laborer;
        break;
    case '1':
        employee3.employeeType = secretary;
        break;
    case '2':
        employee3.employeeType = manager;
        break;
    case '3':
        employee3.employeeType = accountant;
        break;
    case '4':
        employee3.employeeType = executive;
        break;
    case '5':
        employee3.employeeType = researcher;
        break;
    default:
        cout << "Invalid employee type. Defaulting to laborer." << endl;
        employee3.employeeType = laborer;
        break;
    }
    cout << "Date of First Employment (MM/DD/YYYY): ";
    cin >> employee3.dateOfEmployment.month >> delimiter >> employee3.dateOfEmployment.day >> delimiter >> employee3.dateOfEmployment.year;

    cout << endl;

    cout << "Employee 1" << endl;
    cout << "Employee Number: " << employee1.employeeNumber << endl;
    cout << "Compensation: $" << employee1.compensation << endl;
    cout << "Employee Type: ";
    switch (employee1.employeeType)
    {
    case laborer:
        cout << "laborer";
        break;
    case secretary:
        cout << "secretary";
        break;
    case manager:
        cout << "manager";
        break;
    case accountant:
        cout << "accountant";
        break;
    case executive:
        cout << "executive";
        break;
    case researcher:
        cout << "researcher";
        break;
    default:
        cout << "Invalid employee type.";
        break;
    }
    cout << endl;
    cout << "Date of First Employment: " << employee1.dateOfEmployment.month << "/" << employee1.dateOfEmployment.day << "/" << employee1.dateOfEmployment.year << endl;

    cout << endl;

    cout << "Employee 2" << endl;
    cout << "Employee Number: " << employee2.employeeNumber << endl;
    cout << "Compensation: $" << employee2.compensation << endl;
    cout << "Employee Type: ";
    switch (employee2.employeeType)
    {
    case laborer:
        cout << "laborer";
        break;
    case secretary:
        cout << "secretary";
        break;
    case manager:
        cout << "manager";
        break;
    case accountant:
        cout << "accountant";
        break;
    case executive:
        cout << "executive";
        break;
    case researcher:
        cout << "researcher";
        break;
    default:
        cout << "Invalid employee type.";
        break;
    }
    cout << endl;
    cout << "Date of First Employment: " << employee2.dateOfEmployment.month << "/" << employee2.dateOfEmployment.day << "/" << employee2.dateOfEmployment.year << endl;

    cout << endl;

    cout << "Employee 3" << endl;
    cout << "Employee Number: " << employee3.employeeNumber << endl;
    cout << "Compensation: $" << employee3.compensation << endl;
    cout << "Employee Type: ";
    switch (employee3.employeeType)
    {
    case laborer:
        cout << "laborer";
        break;
    case secretary:
        cout << "secretary";
        break;
    case manager:
        cout << "manager";
        break;
    case accountant:
        cout << "accountant";
        break;
    case executive:
        cout << "executive";
        break;
    case researcher:
        cout << "researcher";
        break;
    default:
        cout << "Invalid employee type.";
        break;
    }
    cout << endl;
    cout << "Date of First Employment: " << employee3.dateOfEmployment.month << "/" << employee3.dateOfEmployment.day << "/" << employee3.dateOfEmployment.year << endl;

    return 0;
}

//        .............code Ends...............