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

int main()
{
    char choice;
    cout << "Enter employee type (first letter only) [laborer, secretary, manager, accountant, executive, researcher]: ";
    cin >> choice;

    etype employeeType;

    switch (choice)
    {
    case 'l':
        employeeType = laborer;
        break;
    case 's':
        employeeType = secretary;
        break;
    case 'm':
        employeeType = manager;
        break;
    case 'a':
        employeeType = accountant;
        break;
    case 'e':
        employeeType = executive;
        break;
    case 'r':
        employeeType = researcher;
        break;
    default:
        cout << "Invalid choice!" << endl;
        return 0;
    }

    switch (employeeType)
    {
    case laborer:
        cout << "Employee type is laborer." << endl;
        break;
    case secretary:
        cout << "Employee type is secretary." << endl;
        break;
    case manager:
        cout << "Employee type is manager." << endl;
        break;
    case accountant:
        cout << "Employee type is accountant." << endl;
        break;
    case executive:
        cout << "Employee type is executive." << endl;
        break;
    case researcher:
        cout << "Employee type is researcher." << endl;
        break;
    }

    return 0;
}

//       .............code Ends.............