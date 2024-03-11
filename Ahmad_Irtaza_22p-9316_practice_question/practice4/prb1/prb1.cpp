#include <iostream>

using namespace std;

class SavingsAccount
{
private:
    double savingsBalance;
    static double annualInterestRate;

public:
    SavingsAccount(double balance)
    {
        savingsBalance = balance;
    }

    void calculateMonthlyInterest()
    {
        double monthlyInterest = savingsBalance * (annualInterestRate / 12);
        savingsBalance += monthlyInterest;
    }

    static void modifyInterestRate(double newRate)
    {
        annualInterestRate = newRate;
    }

    double getBalance()
    {
        return savingsBalance;
    }
};

double SavingsAccount::annualInterestRate = 0.0; // iski samj ni aa e error aa rha tha stackoverflow sy pta laga is trha likho error thk ho ja a ga

int main()
{
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    SavingsAccount::modifyInterestRate(0.03);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    cout << "Saver 1 balance after 1 month: $" << saver1.getBalance() << endl;
    cout << "Saver 2 balance after 1 month: $" << saver2.getBalance() << endl;

    SavingsAccount::modifyInterestRate(0.04);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    cout << "Saver 1 balance after 2 months: $" << saver1.getBalance() << endl;
    cout << "Saver 2 balance after 2 months: $" << saver2.getBalance() << endl;

    return 0;
}

//        .............code Ends...............