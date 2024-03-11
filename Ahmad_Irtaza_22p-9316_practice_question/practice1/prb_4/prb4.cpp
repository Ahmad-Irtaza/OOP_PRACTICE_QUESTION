
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void calculatePaycheck(double grossAmount, const string &employeeName);

int main()
{
    double grossAmount;
    string employeeName;

    cout << "Enter the employee name: ";
    getline(cin, employeeName);

    cout << "Enter the gross amount: $";
    cin >> grossAmount;

    calculatePaycheck(grossAmount, employeeName);

    return 0;
}
//-------------------------------------------------------------------------------------
void calculatePaycheck(double grossAmount, const string &employeeName)
{
    double federalTax = 0.15 * grossAmount;
    double stateTax = 0.035 * grossAmount;
    double socialSecurityTax = 0.0575 * grossAmount;
    double medicareTax = 0.0275 * grossAmount;
    double pensionPlan = 0.05 * grossAmount;
    double healthInsurance = 75.0;

    double netPay = grossAmount - federalTax - stateTax - socialSecurityTax - medicareTax - pensionPlan - healthInsurance;

    ofstream outputFile("paycheck.txt");
    if (outputFile.is_open())
    {
        outputFile << fixed << setprecision(2);
        outputFile << employeeName << endl;
        outputFile << "Gross Amount: ............ $" << setw(8) << grossAmount << endl;
        outputFile << "Federal Tax: .................. $" << setw(8) << federalTax << endl;
        outputFile << "State Tax: ...................... $" << setw(8) << stateTax << endl;
        outputFile << "Social Security Tax: ..... $" << setw(8) << socialSecurityTax << endl;
        outputFile << "Medicare/Medicaid Tax: $" << setw(8) << medicareTax << endl;
        outputFile << "Pension Plan: ................ $" << setw(8) << pensionPlan << endl;
        outputFile << "Health Insurance: ........... $" << setw(8) << healthInsurance << endl;
        outputFile << "Net Pay: .......................... $" << setw(8) << netPay << endl;

        outputFile.close();

        cout << "Paycheck details have been saved in the file 'paycheck.txt'." << endl;
    }
    else
    {
        cout << "Unable to create or open the file 'paycheck.txt'." << endl;
    }
}

//       .............code Ends.............