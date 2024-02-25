/*Write a program that reads a sentence as input and converts each word to “Pig Latin.” In one version,
to convert a word to Pig Latin you remove the first letter and place that letter at the end of the word.
Then you append the string “ay” to the word. Here is an example:

English: I SLEPT MOST OF THE NIGHT

Pig Latin: IAY LEPTSAY OSTMAY FOAY HETAY IGHTNAY*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void pigLatin(string);

int main()
{
    string input;

    cout << "Enter a sentence and the program will convert it to Pig Latin:";
    getline(cin, input);
    pigLatin(input);

    return 0;
}

void pigLatin(string in)
{
    string word, actual;
    int wordCount = 0, upperCount = 0;
    istringstream istr(in), istr2;
    ostringstream ostr;

    for (int i = 0; i < in.length(); i++) //seeing how many words are in the string
    {
        if (istr >> word)
        {
            for (int x = 0; x < word.length(); x++)
            {
                if (isalpha(word[x]))
                {
                    wordCount++;
                    actual += word;
                    actual += " ";
                    break;
                }
            }
        }
    }
    istr2.str(actual);
    for (int x = 0; x < wordCount; x++)
    {
        istr2 >> word;
        for (int y = 0; y < word.length(); y++) //testing to see if all letters in word are capitalized
        {
            if (isupper(word[y]))
                upperCount++;
        }
        string temp;
        temp = word[0];
        if (upperCount == word.length()) //if all letters are capitalized
            temp += "AY";
        else
            temp += "ay";;
        word.erase(0, 1);
        word.append(temp);
        for (int x = 0; x < word.length(); x++) //only outputting letters to screen
        {
            if (isalpha(word[x]))
            {
                ostr << word[x];
            }
        }
        ostr << " ";
        upperCount = 0;
    }
    cout << ostr.str() << endl;
}