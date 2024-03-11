
#include <iostream>
#include <string>
using namespace std;

class bankAccount
{
   
    int accountNumber;
    double balance;
public:
    bankAccount(int accountNumber = 0, double balance = 0.0);
    void setAccountNumber(int accountNumber);
    int getAccountNumber() const;
    double getBalance() const;
    void deposit(double amount);
    virtual void withdraw(double amount);
    void printAccountInfo() const;


};

bankAccount::bankAccount(int accountNumber, double balance)
{
    this->accountNumber = accountNumber;
    this->balance = balance;
}

void bankAccount::setAccountNumber(int accountNumber)
{
    this->accountNumber = accountNumber;
}

int bankAccount::getAccountNumber() const
{
    return accountNumber;
}

double bankAccount::getBalance() const
{
    return balance;
}

void bankAccount::deposit(double amount)
{
    balance += amount;
}

void bankAccount::withdraw(double amount)
{
    if (amount <= balance)
        balance -= amount;
    else
        cout << "Insufficient balance." << endl;
}

void bankAccount::printAccountInfo() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: $" << balance << endl;
}

class checkingAccount : public bankAccount
{
    double interestRate;
    double minBalance;
    double serviceCharges;
public:
    checkingAccount(int accountNumber = 0, double balance = 0.0, double interestRate = 0.0, double minBalance = 0.0, double serviceCharges = 0.0);
    void setInterestRate(double interestRate);
    double getInterestRate() const;
    void setMinBalance(double minBalance);
    double getMinBalance() const;
    void setServiceCharges(double serviceCharges);
    double getServiceCharges() const;
    void postInterest();
    bool isBalanceBelowMin() const;
    void writeCheck(double amount);
    void withdraw(double amount) override;
    void printAccountInfo() const;


};

checkingAccount::checkingAccount(int accountNumber, double balance, double interestRate, double minBalance, double serviceCharges)
    : bankAccount(accountNumber, balance)
{
    this->interestRate = interestRate;
    this->minBalance = minBalance;
    this->serviceCharges = serviceCharges;
}

void checkingAccount::setInterestRate(double interestRate)
{
    this->interestRate = interestRate;
}

double checkingAccount::getInterestRate() const
{
    return interestRate;
}

void checkingAccount::setMinBalance(double minBalance)
{
    this->minBalance = minBalance;
}

double checkingAccount::getMinBalance() const
{
    return minBalance;
}

void checkingAccount::setServiceCharges(double serviceCharges)
{
    this->serviceCharges = serviceCharges;
}

double checkingAccount::getServiceCharges() const
{
    return serviceCharges;
}

void checkingAccount::postInterest()
{
    double interest = getBalance() * interestRate / 100;
    deposit(interest);
}

bool checkingAccount::isBalanceBelowMin() const
{
    return (getBalance() < minBalance);
}

void checkingAccount::writeCheck(double amount)
{
    withdraw(amount);
}

void checkingAccount::withdraw(double amount)
{
    if (isBalanceBelowMin())
    {
        cout << "Service charges applied due to balance below minimum." << endl;
        bankAccount::withdraw(amount + serviceCharges);
    }
    else
    {
        bankAccount::withdraw(amount);
    }
}

void checkingAccount::printAccountInfo() const
{
    bankAccount::printAccountInfo();
    cout << "Interest Rate: " << interestRate << "%" << endl;
    cout << "Minimum Balance: $" << minBalance << endl;
    cout << "Service Charges: $" << serviceCharges << endl;
}

class savingsAccount : public bankAccount
{
    double interestRate;
public:
    savingsAccount(int accountNumber = 0, double balance = 0.0, double interestRate = 0.0);
    void setInterestRate(double interestRate);
    double getInterestRate() const;
    void postInterest();
    void withdraw(double amount) override;
    void printAccountInfo() const;


};

savingsAccount::savingsAccount(int accountNumber, double balance, double interestRate)
    : bankAccount(accountNumber, balance)
{
    this->interestRate = interestRate;
}

void savingsAccount::setInterestRate(double interestRate)
{
    this->interestRate = interestRate;
}

double savingsAccount::getInterestRate() const
{
    return interestRate;
}

void savingsAccount::postInterest()
{
    double interest = getBalance() * interestRate / 100;
    deposit(interest);
}

void savingsAccount::withdraw(double amount)
{
    if (amount <= getBalance())
        bankAccount::withdraw(amount);
    else
        cout << "Insufficient balance." << endl;
}

void savingsAccount::printAccountInfo() const
{
    bankAccount::printAccountInfo();
    cout << "Interest Rate: " << interestRate << "%" << endl;
}

int main()
{
    checkingAccount checking(123456, 1000.0, 5.0, 500.0, 10.0);
    savingsAccount savings(654321, 2000.0, 3.0);

    checking.printAccountInfo();
    cout << endl;

    savings.printAccountInfo();
    cout << endl;

    checking.deposit(500.0);
    checking.printAccountInfo();
    cout << endl;

    checking.withdraw(1500.0);
    checking.printAccountInfo();
    cout << endl;

    savings.deposit(1000.0);
    savings.printAccountInfo();
    cout << endl;

    savings.withdraw(3000.0);
    savings.printAccountInfo();
    cout << endl;

    savings.withdraw(1500.0);
    savings.printAccountInfo();
    cout << endl;

    checking.writeCheck(200.0);
    checking.printAccountInfo();
    cout << endl;

    checking.postInterest();
    checking.printAccountInfo();
    cout << endl;

    savings.postInterest();
    savings.printAccountInfo();
    cout << endl;

    return 0;
}

//        .............code Ends...............