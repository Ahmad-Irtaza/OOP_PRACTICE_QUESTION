#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class dayType
{
public:
    dayType(string day = "");

    void setDay(string day);
    void printDay() const;
    string getDay() const;
    string getNextDay() const;
    string getPreviousDay() const;
    string getDayAfter(int numDays) const;

private:
    string currentDay;
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

class extDateType
{
public:
    extDateType(int month = 1, int day = 1, int year = 1900);

    void setDate(int month, int day, int year);
    void printDate() const;
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    bool isLeap(int year) const;
    int daysInMonth(int month, int year) const;
    int daysPassed(int month, int day, int year) const;

private:
    int dMonth;
    int dDay;
    int dYear;
};

extDateType::extDateType(int month, int day, int year)
{
    setDate(month, day, year);
}

void extDateType::setDate(int month, int day, int year)
{
    dMonth = month;
    dDay = day;
    dYear = year;
}

void extDateType::printDate() const
{
    cout << dMonth << "-" << dDay << "-" << dYear;
}

int extDateType::getMonth() const
{
    return dMonth;
}

int extDateType::getDay() const
{
    return dDay;
}

int extDateType::getYear() const
{
    return dYear;
}

bool extDateType::isLeap(int year) const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int extDateType::daysInMonth(int month, int year) const
{
    static const int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeap(year))
        return 29;

    return daysPerMonth[month - 1];
}

int extDateType::daysPassed(int month, int day, int year) const
{
    int days = day;

    for (int i = 1; i < month; i++)
    {
        days += daysInMonth(i, year);
    }

    return days;
}

class calendarType
{
public:
    calendarType(int month = 1, int year = 1900);

    void setMonth(int month);
    void setYear(int year);
    int getMonth() const;
    int getYear() const;
    void printCalendar() const;

private:
    dayType firstDayOfMonth;
    extDateType calendarDate;
};

calendarType::calendarType(int month, int year)
{
    setMonth(month);
    setYear(year);
}

void calendarType::setMonth(int month)
{
    calendarDate.setDate(month, 1, calendarDate.getYear());
    firstDayOfMonth.setDay(calendarDate.getDayAfter(-calendarDate.daysPassed(month, 1, calendarDate.getYear()) % 7));
}

void calendarType::setYear(int year)
{
    calendarDate.setDate(calendarDate.getMonth(), 1, year);
    firstDayOfMonth.setDay(calendarDate.getDayAfter(-calendarDate.daysPassed(calendarDate.getMonth(), 1, year) % 7));
}

int calendarType::getMonth() const
{
    return calendarDate.getMonth();
}

int calendarType::getYear() const
{
    return calendarDate.getYear();
}

void calendarType::printCalendar() const
{
    static const string months[] = {"January", "February", "March", "April", "May", "June",
                                    "July", "August", "September", "October", "November", "December"};

    cout << setw(24) << months[getMonth() - 1] << " " << getYear() << endl;
    cout << "-----------------------------------" << endl;
    cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;

    int firstDayIndex = 0;

    if (firstDayOfMonth.getDay() == "Mon")
        firstDayIndex = 1;
    else if (firstDayOfMonth.getDay() == "Tue")
        firstDayIndex = 2;
    else if (firstDayOfMonth.getDay() == "Wed")
        firstDayIndex = 3;
    else if (firstDayOfMonth.getDay() == "Thu")
        firstDayIndex = 4;
    else if (firstDayOfMonth.getDay() == "Fri")
        firstDayIndex = 5;
    else if (firstDayOfMonth.getDay() == "Sat")
        firstDayIndex = 6;

    int numDays = calendarDate.daysInMonth(getMonth(), getYear());

    int day = 1;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i == 0 && j < firstDayIndex)
            {
                cout << "    ";
            }
            else if (day <= numDays)
            {
                cout << setw(4) << day << " ";
                day++;
            }
        }
        cout << endl;

        if (day > numDays)
            break;
    }

    cout << "-----------------------------------" << endl;
}

int main()
{
    int month, year;
    char choice;

    cout << "Enter the month and year (MM YYYY): ";
    cin >> month >> year;

    calendarType calendar(month, year);

    cout << endl;
    cout << "Calendar for " << month << "/" << year << ":" << endl;
    calendar.printCalendar();

    cout << "Do you want to print the calendar for a specific year? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        cout << "Enter the year (YYYY): ";
        cin >> year;

        calendar.setYear(year);

        cout << endl;
        cout << "Calendar for the year " << year << ":" << endl;
        calendar.printCalendar();
    }

    return 0;
}

//        .............code Ends...............