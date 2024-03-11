#include <iostream>

enum EType
{
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

struct DateType
{
    int month;
    int day;
    int year;
};

class Employee
{
private:
    int employeeNumber;
    float compensation;
    EType employeeType;
    DateType dateOfEmployment;

public:
    void getData()
    {
        std::cout << "Employee Number: ";
        std::cin >> employeeNumber;
        std::cout << "Compensation (in dollars): $";
        std::cin >> compensation;
        std::cout << "Employee Type [0=laborer, 1=secretary, 2=manager, 3=accountant, 4=executive, 5=researcher]: ";
        int typeChoice;
        std::cin >> typeChoice;
        employeeType = static_cast<EType>(typeChoice);
        std::cout << "Date of First Employment (MM/DD/YYYY): ";
        char delimiter;
        std::cin >> dateOfEmployment.month >> delimiter >> dateOfEmployment.day >> delimiter >> dateOfEmployment.year;
    }

    void displayData()
    {
        std::cout << "Employee Number: " << employeeNumber << std::endl;
        std::cout << "Compensation: $" << compensation << std::endl;
        std::cout << "Employee Type: ";
        switch (employeeType)
        {
        case laborer:
            std::cout << "laborer";
            break;
        case secretary:
            std::cout << "secretary";
            break;
        case manager:
            std::cout << "manager";
            break;
        case accountant:
            std::cout << "accountant";
            break;
        case executive:
            std::cout << "executive";
            break;
        case researcher:
            std::cout << "researcher";
            break;
        default:
            std::cout << "Invalid employee type.";
            break;
        }
        std::cout << std::endl;
        std::cout << "Date of First Employment: " << dateOfEmployment.month << "/"
                  << dateOfEmployment.day << "/" << dateOfEmployment.year << std::endl;
    }
};

int main()
{
    Employee employees[3];

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Enter details for Employee " << i + 1 << ":" << std::endl;
        employees[i].getData();
        std::cout << std::endl;
    }

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Employee " << i + 1 << std::endl;
        employees[i].displayData();
        std::cout << std::endl;
    }

    return 0;
}

//        .............code Ends...............