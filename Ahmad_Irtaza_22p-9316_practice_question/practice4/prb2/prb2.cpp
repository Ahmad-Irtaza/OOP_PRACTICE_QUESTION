#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Card
{
private:
    int face;
    int suit;

    static string faces[];
    static string suits[];

public:
    Card(int cardFace = 0, int cardSuit = 0)
    {
        face = cardFace;
        suit = cardSuit;
    }

    string toString()
    {
        return faces[face] + " of " + suits[suit];
    }
};

string Card::faces[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
string Card::suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

class DeckOfCards
{
private:
    static const int totalCards = 52;
    Card deck[totalCards];
    int currentCard;

public:
    DeckOfCards()
    {
        currentCard = 0;
        for (int count = 0; count < totalCards; ++count)
        {
            deck[count] = Card(count % 13, count / 13);
        }
    }

    void shuffle()
    {
        srand(time(0));
        for (int first = 0; first < totalCards; ++first)
        {
            int second = rand() % totalCards;
            swap(deck[first], deck[second]);
        }
    }

    Card dealCard()
    {
        if (moreCards())
        {
            return deck[currentCard++];
        }
        else
        {
            return Card(-1, -1);
        }
    }

    bool moreCards()
    {
        return currentCard < totalCards;
    }
};

int main()
{
    DeckOfCards deck;
    deck.shuffle();

    while (deck.moreCards())
    {
        Card card = deck.dealCard();
        cout << card.toString() << endl;
    }

    return 0;
}

//        .............code Ends...............