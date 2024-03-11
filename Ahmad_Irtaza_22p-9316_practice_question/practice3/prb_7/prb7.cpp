#include <iostream>
#include <string>

class memberType
{
private:
    std::string name;
    int memberID;
    int numBooksBought;
    double amountSpent;

public:
    memberType()
    {
        name = "";
        memberID = 0;
        numBooksBought = 0;
        amountSpent = 0.0;
    }

    memberType(const std::string &memberName, int ID, int numBought, double spentAmount)
    {
        name = memberName;
        memberID = ID;
        numBooksBought = numBought;
        amountSpent = spentAmount;
    }

    std::string getName() const
    {
        return name;
    }

    void setName(const std::string &memberName)
    {
        name = memberName;
    }

    int getMemberID() const
    {
        return memberID;
    }

    void setMemberID(int ID)
    {
        memberID = ID;
    }

    int getNumBooksBought() const
    {
        return numBooksBought;
    }

    void setNumBooksBought(int numBought)
    {
        numBooksBought = numBought;
    }

    double getAmountSpent() const
    {
        return amountSpent;
    }

    void setAmountSpent(double spentAmount)
    {
        amountSpent = spentAmount;
    }

    void updateNumBooksBought(int numBought)
    {
        numBooksBought += numBought;
    }

    void updateAmountSpent(double spentAmount)
    {
        amountSpent += spentAmount;
    }

    void showMemberInfo() const
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Member ID: " << memberID << std::endl;
        std::cout << "Number of Books Bought: " << numBooksBought << std::endl;
        std::cout << "Amount Spent: $" << amountSpent << std::endl;
    }
};

int main()
{
    memberType member1("Ali", 1234, 5, 100.50);
    member1.showMemberInfo();

    memberType member2;
    member2.setName("Hassan");
    member2.setMemberID(5678);
    member2.setNumBooksBought(3);
    member2.setAmountSpent(75.20);
    member2.showMemberInfo();

    member1.updateNumBooksBought(2);
    member1.updateAmountSpent(50.75);
    member1.showMemberInfo();

    return 0;
}

//        .............code Ends...............