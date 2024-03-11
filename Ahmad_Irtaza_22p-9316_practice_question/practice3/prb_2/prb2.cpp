#include <iostream>

class Date
{
private:
    int month;
    int day;
    int year;

public:
    void getDate()
    {
        std::cout << "Enter date (in MM/DD/YY format): ";
        char slash;
        std::cin >> month >> slash >> day >> slash >> year;
    }

    void showDate()
    {
        std::cout << "Date: " << month << '/' << day << '/' << year << std::endl;
    }
};

int main()
{
    Date date;

    date.getDate();
    date.showDate();

    return 0;
}

//        .............code Ends...............