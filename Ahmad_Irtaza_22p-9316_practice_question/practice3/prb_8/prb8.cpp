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

class bookstore
{
private:
    memberType members[500];
    int numMembers;
    std::string books[1000];
    int numBooks;
    int bookCounter;

public:
    bookstore()
    {
        numMembers = 0;
        numBooks = 0;
        bookCounter = 0;
    }

    void addMember(const memberType &member)
    {
        if (numMembers < 500)
        {
            members[numMembers] = member;
            numMembers++;
            std::cout << "Member added successfully." << std::endl;
        }
        else
        {
            std::cout << "Cannot add more members. Maximum limit reached." << std::endl;
        }
    }

    void addBook(const std::string &bookTitle)
    {
        if (numBooks < 1000)
        {
            books[numBooks] = bookTitle;
            numBooks++;
            std::cout << "Book added successfully." << std::endl;
        }
        else
        {
            std::cout << "Cannot add more books. Maximum limit reached." << std::endl;
        }
    }

    void purchaseBook(int memberID, const std::string &bookTitle)
    {
        memberType *member = findMember(memberID);
        if (member == nullptr)
        {
            std::cout << "Member not found." << std::endl;
            return;
        }

        for (int i = 0; i < numBooks; i++)
        {
            if (books[i] == bookTitle)
            {
                double bookPrice = 10.0; // Default price for books

                // Check if member is eligible for discount
                if (member->getNumBooksBought() % 11 == 0 && member->getNumBooksBought() != 0)
                {
                    double averageAmount = member->getAmountSpent() / 10.0;
                    bookPrice -= averageAmount;
                    member->setAmountSpent(0.0); // Reset the amount spent
                }

                bookPrice *= 0.95; // Apply 5% discount
                member->updateNumBooksBought(1);
                member->updateAmountSpent(bookPrice);
                std::cout << "Book purchased successfully." << std::endl;
                return;
            }
        }

        std::cout << "Book not found." << std::endl;
    }

    memberType *findMember(int memberID)
    {
        for (int i = 0; i < numMembers; i++)
        {
            if (members[i].getMemberID() == memberID)
            {
                return &members[i];
            }
        }
        return nullptr; // Member not found
    }

    void showAllMembers() const
    {
        std::cout << "Members:" << std::endl;
        for (int i = 0; i < numMembers; i++)
        {
            members[i].showMemberInfo();
            std::cout << "---------------" << std::endl;
        }
    }

    void showAllBooks() const
    {
        std::cout << "Books:" << std::endl;
        for (int i = 0; i < numBooks; i++)
        {
            std::cout << books[i] << std::endl;
        }
    }
};

int main()
{
    bookstore store;

    memberType member1("Ali", 1234, 5, 100.50);
    store.addMember(member1);

    memberType member2;
    member2.setName("Hassan");
    member2.setMemberID(5678);
    member2.setNumBooksBought(3);
    member2.setAmountSpent(75.20);
    store.addMember(member2);

    store.addBook("Introduction to Programming");
    store.addBook("Data Structures and Algorithms");

    store.purchaseBook(1234, "Data Structures and Algorithms");

    store.showAllMembers();
    store.showAllBooks();

    return 0;
}

//        .............code Ends...............