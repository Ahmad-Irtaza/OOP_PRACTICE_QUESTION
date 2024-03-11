
#include <iostream>
#include <string>

using namespace std;
bool isVowel(char c);
void removeVowels(const string &str);

int main()
{
    string input;
    cout << "Enter the string: ";
    getline(cin, input);
    removeVowels(input);
    return 0;
}
bool isVowel(char c)
{
    c = tolower(c); // Convert character to lowercase for case-insensitive comparison
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void removeVowels(const string &str)
{
    string output;
    for (char c : str)
    {
        if (!isVowel(c))
        {
            output += c;
        }
    }
    cout << "String without vowels: " << output << endl;
}
