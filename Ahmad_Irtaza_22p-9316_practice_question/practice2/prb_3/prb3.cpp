#include <iostream>
using namespace std;

struct dateType
{
    int month;
    int day;
    int year;
};

int main()
{
    dateType date;

    cout << "Enter a date in the format MM/DD/YYYY: ";
    char delimiter;
    cin >> date.month >> delimiter >> date.day >> delimiter >> date.year;

    cout << "Entered date: " << date.month << "/" << date.day << "/" << date.year << endl;

    return 0;
}

//       .............code Ends.............