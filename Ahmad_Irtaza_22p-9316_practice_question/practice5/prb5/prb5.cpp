#include <iostream>
#include <string>
using namespace std;

class dayType
{
    string currentDay;
public:
    dayType(string day = "");

    void setDay(string day);
    void printDay() const;
    string getDay() const;
    string getNextDay() const;
    string getPreviousDay() const;
    string getDayAfter(int numDays) const;


};

dayType::dayType(string day)
{
    setDay(day);
}

void dayType::setDay(string day)
{
    currentDay = day;
}

void dayType::printDay() const
{
    cout << currentDay;
}

string dayType::getDay() const
{
    return currentDay;
}

string dayType::getNextDay() const
{
    static const string daysOfWeek[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int currentIndex = 0;

    for (int i = 0; i < 7; i++)
    {
        if (currentDay == daysOfWeek[i])
        {
            currentIndex = i;
            break;
        }
    }

    int nextIndex = (currentIndex + 1) % 7;

    return daysOfWeek[nextIndex];
}

string dayType::getPreviousDay() const
{
    static const string daysOfWeek[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int currentIndex = 0;

    for (int i = 0; i < 7; i++)
    {
        if (currentDay == daysOfWeek[i])
        {
            currentIndex = i;
            break;
        }
    }

    int prevIndex = (currentIndex + 6) % 7;

    return daysOfWeek[prevIndex];
}

string dayType::getDayAfter(int numDays) const
{
    static const string daysOfWeek[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int currentIndex = 0;

    for (int i = 0; i < 7; i++)
    {
        if (currentDay == daysOfWeek[i])
        {
            currentIndex = i;
            break;
        }
    }

    int newIndex = (currentIndex + numDays) % 7;

    return daysOfWeek[newIndex];
}

int main()
{
    dayType myDay("Mon");

    cout << "Current day: ";
    myDay.printDay();
    cout << endl;

    cout << "Next day: " << myDay.getNextDay() << endl;
    cout << "Previous day: " << myDay.getPreviousDay() << endl;
    cout << "Day after adding 4 days: " << myDay.getDayAfter(4) << endl;
    cout << "Day after adding 13 days: " << myDay.getDayAfter(13) << endl;

    return 0;
}

//        .............code Ends...............