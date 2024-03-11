#include <iostream>
using namespace std;

struct employeeType
{
    int employeeNumber;
    float compensation;
};

int main()
{
    employeeType employee1, employee2, employee3;

    cout << "Enter details for Employee 1:" << endl;
    cout << "Employee Number: ";
    cin >> employee1.employeeNumber;
    cout << "Compensation (in dollars): $";
    cin >> employee1.compensation;

    cout << endl;

    cout << "Enter details for Employee 2:" << endl;
    cout << "Employee Number: ";
    cin >> employee2.employeeNumber;
    cout << "Compensation (in dollars): $";
    cin >> employee2.compensation;

    cout << endl;

    cout << "Enter details for Employee 3:" << endl;
    cout << "Employee Number: ";
    cin >> employee3.employeeNumber;
    cout << "Compensation (in dollars): $";
    cin >> employee3.compensation;

    cout << endl;

    cout << "Employee Information:" << endl;
    cout << "Employee 1" << endl;
    cout << "Employee Number: " << employee1.employeeNumber << endl;
    cout << "Compensation: $" << employee1.compensation << endl;

    cout << endl;

    cout << "Employee 2" << endl;
    cout << "Employee Number: " << employee2.employeeNumber << endl;
    cout << "Compensation: $" << employee2.compensation << endl;

    cout << endl;

    cout << "Employee 3" << endl;
    cout << "Employee Number: " << employee3.employeeNumber << endl;
    cout << "Compensation: $" << employee3.compensation << endl;

    return 0;
}

//       .............code Ends.............