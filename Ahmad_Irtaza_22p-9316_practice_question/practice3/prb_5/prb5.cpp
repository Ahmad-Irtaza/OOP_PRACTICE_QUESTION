#include <iostream>
using namespace std;

class romanType
{
private:
    string romanNumeral;
    int decimalValue;

public:
    romanType()
    {
        romanNumeral = "";
        decimalValue = 0;
    }

    void setRomanNumeral(const std::string &roman)
    {
        romanNumeral = roman;
        convertToDecimal();
    }

    void convertToDecimal()
    {
        decimalValue = 0;
        int prevValue = 0;

        for (int i = romanNumeral.length() - 1; i >= 0; i--)
        {
            int currValue = getDecimalValue(romanNumeral[i]);

            if (currValue >= prevValue)
                decimalValue += currValue;
            else
                decimalValue -= currValue;

            prevValue = currValue;
        }
    }

    int getDecimalValue(char romanChar)
    {
        switch (romanChar)
        {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        default:
            return 0;
        }
    }

    void printNumeral() const
    {
        cout << "Roman Numeral: " << romanNumeral << std::endl;
    }

    void printDecimal() const
    {
        cout << "Decimal Value: " << decimalValue << std::endl;
    }
};

int main()
{

    romanType romanNum;

    romanNum.setRomanNumeral("MCXIV");
    romanNum.printNumeral();
    romanNum.printDecimal();
    cout << endl;

    romanNum.setRomanNumeral("CCCLIX");
    romanNum.printNumeral();
    romanNum.printDecimal();
    cout << endl;

    romanNum.setRomanNumeral("MDCLXVI");
    romanNum.printNumeral();
    romanNum.printDecimal();
    cout << endl;

    return 0;
}

//        .............code Ends...............