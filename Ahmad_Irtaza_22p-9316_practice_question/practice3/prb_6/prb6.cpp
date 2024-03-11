#include <iostream>
#include <string>
using namespace std;

class bookType
{
private:
    string title;
    string authors[4];
    string publisher;
    string ISBN;
    double price;
    int numCopies;

public:
    bookType()
    {
        title = "";
        for (int i = 0; i < 4; i++)
            authors[i] = "";
        publisher = "";
        ISBN = "";
        price = 0.0;
        numCopies = 0;
    }

    bookType(const string &bookTitle, const string bookAuthors[], const string &bookPublisher,
             const string &bookISBN, double bookPrice, int bookCopies)
    {
        title = bookTitle;
        for (int i = 0; i < 4; i++)
            authors[i] = bookAuthors[i];
        publisher = bookPublisher;
        ISBN = bookISBN;
        price = bookPrice;
        numCopies = bookCopies;
    }

    string getTitle() const
    {
        return title;
    }

    void setTitle(const string &bookTitle)
    {
        title = bookTitle;
    }

    string getAuthor(int index) const
    {
        if (index >= 0 && index < 4)
            return authors[index];
        else
            return "";
    }

    void setAuthor(int index, const string &authorName)
    {
        if (index >= 0 && index < 4)
            authors[index] = authorName;
    }

    string getPublisher() const
    {
        return publisher;
    }

    void setPublisher(const string &bookPublisher)
    {
        publisher = bookPublisher;
    }

    string getISBN() const
    {
        return ISBN;
    }

    void setISBN(const string &bookISBN)
    {
        ISBN = bookISBN;
    }

    double getPrice() const
    {
        return price;
    }

    void setPrice(double bookPrice)
    {
        price = bookPrice;
    }

    int getNumCopies() const
    {
        return numCopies;
    }

    void setNumCopies(int bookCopies)
    {
        numCopies = bookCopies;
    }

    void updateNumCopies(int change)
    {
        numCopies += change;
    }

    void printBookInfo() const
    {
        cout << "Title: " << title << endl;
        cout << "Authors: ";
        for (int i = 0; i < 4; i++)
        {
            if (!authors[i].empty())
                cout << authors[i] << ", ";
        }
        cout << std::endl;
        cout << "Publisher: " << publisher << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Price: $" << price << endl;
        cout << "Number of Copies: " << numCopies << endl;
    }
};

int main()
{
    bookType books[100];

    books[0].setTitle("Introduction to Programming");
    books[0].setAuthor(0, "Sara Rehmat");
    books[0].setAuthor(1, "M Usman");
    books[0].setPublisher("ABC ");
    books[0].setISBN("0-987-654-321");
    books[0].setPrice(29.99);
    books[0].setNumCopies(10);

    books[1].setTitle("Data Structures and Algorithms");
    books[1].setAuthor(0, "Fazl-e-Basit");
    books[1].setAuthor(1, "Khurram Shahzad");
    books[1].setPublisher("XYZ");
    books[1].setISBN("123-456-789-0");
    books[1].setPrice(49.99);
    books[1].setNumCopies(5);

    string searchTitle = "Data Structures and Algorithms";
    for (int i = 0; i < 100; i++)
    {
        if (books[i].getTitle() == searchTitle)
        {
            cout << "Book found!" << endl;
            books[i].printBookInfo();
            break;
        }
    }

    string searchISBN = "0-987-654-321";
    for (int i = 0; i < 100; i++)
    {
        if (books[i].getISBN() == searchISBN)
        {
            cout << "Book found!" << endl;
            books[i].printBookInfo();
            break;
        }
    }

    string updateISBN = "123-456-789-0";
    int updatedCopies = 3;
    for (int i = 0; i < 100; i++)
    {
        if (books[i].getISBN() == updateISBN)
        {
            books[i].updateNumCopies(updatedCopies);
            cout << "Number of copies updated!" << endl;
            books[i].printBookInfo();
            break;
        }
    }

    return 0;
}

//        .............code Ends...............