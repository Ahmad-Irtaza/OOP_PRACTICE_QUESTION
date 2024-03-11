#include <iostream>
#include <cmath>
using namespace std;

struct sterling
{
    int pounds;
    int shillings;
    int pence;
};
sterling convertToOldStyle(double decimalPounds);

int main()
{
    double decimalPounds;
    cout << "Enter the amount in decimal pounds: £";
    cin >> decimalPounds;

    sterling oldStyle = convertToOldStyle(decimalPounds);

    cout << "Amount in pounds-shillings-pence format: £"
         << oldStyle.pounds << "." << oldStyle.shillings << "." << oldStyle.pence << endl;

    return 0;
}
sterling convertToOldStyle(double decimalPounds)
{
    sterling result;

    result.pounds = decimalPounds;
    decimalPounds -= result.pounds;

    decimalPounds *= 20;
    result.shillings = decimalPounds;
    decimalPounds -= result.shillings;

    decimalPounds *= 12;
    result.pence = round(decimalPounds);

    return result;
}

//        .............code Ends...............