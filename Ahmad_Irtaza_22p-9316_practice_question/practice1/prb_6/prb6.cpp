
#include <iostream>
using namespace std;
void displayMenu();
int getInput();
void convertTo12Hour(int hour, int minute);
void convertTo24Hour(int hour, int minute, string period);

int main()
{
    int choice;
    int hour, minute;
    string period;

    do
    {
        displayMenu();
        choice = getInput();

        switch (choice)
        {
        case 1:
            cout << "Enter the time in 24-hour notation (HH:MM): ";
            cin >> hour >> minute;
            convertTo12Hour(hour, minute);
            break;
        case 2:
            cout << "Enter the time in 12-hour notation (HH:MM AM/PM): ";
            cin >> hour >> minute >> period;
            convertTo24Hour(hour, minute, period);
            break;
        case 3:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }

        cout << endl;
    } while (choice != 3);

    return 0;
}

//----------------------------------------------------------

void displayMenu()
{
    cout << "1. Convert time from 24-hour notation to 12-hour notation" << endl;
    cout << "2. Convert time from 12-hour notation to 24-hour notation" << endl;
    cout << "3. Exit" << endl;
}

//--------------------------------------------------------------------

int getInput()
{
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

//---------------------------------------------------------------

void convertTo12Hour(int hour, int minute)
{
    string period = "AM";
    if (hour >= 12)
    {
        period = "PM";
        if (hour > 12)
        {
            hour -= 12;
        }
    }
    cout << "Time in 12-hour notation: " << hour << ":" << minute << " " << period << endl;
}

//------------------------------------------------------------------

void convertTo24Hour(int hour, int minute, string period)
{
    if (period == "AM" || period == "am")
    {
        if (hour == 12)
        {
            hour = 0;
        }
    }
    else if (period == "PM" || period == "pm")
    {
        if (hour != 12)
        {
            hour += 12;
        }
    }
    cout << "Time in 24-hour notation: " << hour << ":" << minute << endl;
}

//       .............code Ends.............