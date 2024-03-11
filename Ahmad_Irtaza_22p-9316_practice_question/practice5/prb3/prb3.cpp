#include <iostream>
#include <stdexcept>
using namespace std;

class dateType
{

    int dMonth;
    int dDay;
    int dYear;

public:
    dateType(int month = 1, int day = 1, int year = 1900);

    void setDate(int month, int day, int year);
    void setMonth(int month);
    void setDay(int day);
    void setYear(int year);

    int getMonth() const;
    int getDay() const;
    int getYear() const;

    bool isLeapYear() const;
    int daysInMonth() const;
    int daysPassed() const;
    int daysRemaining() const;

    void addDays(int numDays);
    void printDate() const;

    bool isLeap(int year) const;
    int daysInMonth(int month, int year) const;
    int daysPassed(int month, int day, int year) const;
};

dateType::dateType(int month, int day, int year)
{
    setDate(month, day, year);
}

void dateType::setDate(int month, int day, int year)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

void dateType::setMonth(int month)
{
    if (month >= 1 && month <= 12)
        dMonth = month;
    else
        throw invalid_argument("Invalid month.");
}

void dateType::setDay(int day)
{
    int maxDays = daysInMonth();

    if (day >= 1 && day <= maxDays)
        dDay = day;
    else
        throw invalid_argument("Invalid day.");
}

void dateType::setYear(int year)
{
    if (year >= 1900)
        dYear = year;
    else
        throw invalid_argument("Invalid year.");
}

int dateType::getMonth() const
{
    return dMonth;
}

int dateType::getDay() const
{
    return dDay;
}

int dateType::getYear() const
{
    return dYear;
}

bool dateType::isLeapYear() const
{
    return isLeap(dYear);
}

int dateType::daysInMonth() const
{
    return daysInMonth(dMonth, dYear);
}

int dateType::daysPassed() const
{
    return daysPassed(dMonth, dDay, dYear);
}

int dateType::daysRemaining() const
{
    int daysInYear = isLeapYear() ? 366 : 365;
    return daysInYear - daysPassed();
}

void dateType::addDays(int numDays)
{
    int daysInYear = isLeapYear() ? 366 : 365;

    int totalDays = daysPassed() + numDays;
    while (totalDays > daysInYear)
    {
        totalDays -= daysInYear;
        dYear++;
        daysInYear = isLeapYear() ? 366 : 365;
    }

    int month = 1;
    int day = 1;

    while (totalDays > daysInMonth(month, dYear))
    {
        totalDays -= daysInMonth(month, dYear);
        month++;
    }

    dMonth = month;
    dDay = totalDays;
}

void dateType::printDate() const
{
    cout << dMonth << "-" << dDay << "-" << dYear;
}

bool dateType::isLeap(int year) const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int dateType::daysInMonth(int month, int year) const
{
    static const int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeap(year))
        return 29;

    return daysPerMonth[month - 1];
}

int dateType::daysPassed(int month, int day, int year) const
{
    int days = 0;
    for (int i = 1; i < month; i++)
    {
        days += daysInMonth(i, year);
    }
    days += day;

    return days;
}

int main()
{
    dateType date(3, 18, 2013);

    cout << "Current Date: ";
    date.printDate();
    cout << endl;

    cout << "Month: " << date.getMonth() << endl;
    cout << "Day: " << date.getDay() << endl;
    cout << "Year: " << date.getYear() << endl;

    cout << "Is Leap Year: " << (date.isLeapYear() ? "Yes" : "No") << endl;
    cout << "Days in Month: " << date.daysInMonth() << endl;
    cout << "Days Passed: " << date.daysPassed() << endl;
    cout << "Days Remaining: " << date.daysRemaining() << endl;

    cout << "Adding 25 days..." << endl;
    date.addDays(25);
    cout << "New Date: ";
    date.printDate();
    cout << endl;

    return 0;
}

//        .............code Ends...............