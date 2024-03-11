

#include <iostream>
using namespace std;

void getData(char &maritalStatus, int &numChildren, double &grossSalary, double &pensionFund);
double taxAmount(char maritalStatus, int numChildren, double grossSalary, double pensionFund);

int main()
{
    char maritalStatus;
    int numChildren;
    double grossSalary, pensionFund;

    getData(maritalStatus, numChildren, grossSalary, pensionFund);

    double tax = taxAmount(maritalStatus, numChildren, grossSalary, pensionFund);

    cout << "Federal tax owed: $" << tax << endl;

    return 0;
}

// -----------------------------------------------------------------------

void getData(char &maritalStatus, int &numChildren, double &grossSalary, double &pensionFund)
{
    cout << "Enter marital status (s for single, m for married): ";
    cin >> maritalStatus;

    if (maritalStatus == 'm')
    {
        cout << "Enter the number of children under the age of 14: ";
        cin >> numChildren;
    }

    cout << "Enter gross salary: $";
    cin >> grossSalary;

    cout << "Enter percentage of gross income contributed to a pension fund: ";
    cin >> pensionFund;
}

// ------------------------------------------------------------------------------

double taxAmount(char maritalStatus, int numChildren, double grossSalary, double pensionFund)
{
    double standardExemption = 0;
    if (maritalStatus == 's')
    {
        standardExemption = 4000;
    }
    else if (maritalStatus == 'm')
    {
        standardExemption = 7000 + (numChildren * 1000);
    }

    double taxableIncome = grossSalary - (grossSalary * (pensionFund / 100)) - standardExemption;

    double tax = 0;
    if (taxableIncome <= 15000)
    {
        tax = taxableIncome * 0.15;
    }
    else if (taxableIncome > 15000 && taxableIncome <= 40000)
    {
        tax = 2250 + (0.25 * (taxableIncome - 15000));
    }
    else if (taxableIncome > 40000)
    {
        tax = 8460 + (0.35 * (taxableIncome - 40000));
    }

    return tax;
}
//       .............code Ends.............