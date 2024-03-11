#include <iostream>
#include <string>
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
    : dMonth(month), dDay(day), dYear(year)
{
}

void dateType::setDate(int month, int day, int year)
{
    dMonth = month;
    dDay = day;
    dYear = year;
}

void dateType::setMonth(int month)
{
    dMonth = month;
}

void dateType::setDay(int day)
{
    dDay = day;
}

void dateType::setYear(int year)
{
    dYear = year;
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
    int totalDays = isLeapYear() ? 366 : 365;
    return totalDays - daysPassed();
}

void dateType::addDays(int numDays)
{
    int totalDays = daysPassed() + numDays;

    int year = dYear;
    int month = dMonth;
    int day = dDay;

    while (totalDays > 0)
    {
        int daysInCurrentMonth = daysInMonth(month, year);

        if (totalDays >= daysInCurrentMonth)
        {
            totalDays -= daysInCurrentMonth;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
        else
        {
            day += totalDays;
            totalDays = 0;
        }
    }

    dMonth = month;
    dDay = day;
    dYear = year;
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
    {
        return 29;
    }

    return daysPerMonth[month - 1];
}

int dateType::daysPassed(int month, int day, int year) const
{
    int totalDays = 0;

    for (int i = 1; i < month; i++)
    {
        totalDays += daysInMonth(i, year);
    }

    totalDays += day;

    return totalDays;
}

class extDateType : public dateType
{
    string getMonthName(int month) const;

public:
    extDateType(int month = 1, int day = 1, int year = 1900);

    void printDate() const;
    void printMonthYear() const;
};

extDateType::extDateType(int month, int day, int year)
    : dateType(month, day, year)
{
}

void extDateType::printDate() const
{
    cout << getMonth() << "-" << getDay() << "-" << getYear();
}

void extDateType::printMonthYear() const
{
    cout << getMonthName(getMonth()) << " " << getYear();
}

string extDateType::getMonthName(int month) const
{
    static const string monthNames[] = {"January", "February", "March", "April",
                                        "May", "June", "July", "August", "September",
                                        "October", "November", "December"};

    return monthNames[month - 1];
}

int main()
{

    dateType myDate(3, 24, 2013);

    cout << "Date: ";
    myDate.printDate();
    cout << endl;

    cout << "Days passed in the year: " << myDate.daysPassed() << endl;
    cout << "Days remaining in the year: " << myDate.daysRemaining() << endl;

    myDate.addDays(25);

    cout << "New date after adding 25 days: ";
    myDate.printDate();
    cout << endl;

    cout << endl;

    extDateType myExtDate(3, 24, 2013);

    cout << "Extended Date: ";
    myExtDate.printDate();
    cout << endl;

    cout << "Month and Year: ";
    myExtDate.printMonthYear();
    cout << endl;

    return 0;
}

//        .............code Ends...............