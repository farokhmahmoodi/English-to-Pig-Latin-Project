/*Overview: This project is for testing the use of structures, arrays and string handling functions. In this assignment 
you will be prompting the user to enter an english sentence. The program will then convert it to the code Pig Latin . 
Your program will then output this Pig Latin to the screen.

Note: While there are many ways to do conversions to pig latin, I will require that you follow the procedures below, all 
of which will use the following structure:
struct Word { string english; string piglatin; }; 

Part 1. Write a function that takes in an English sentence as one string. 
This function should first calculate how many “words” are in the sentence (words being substrings separated by whitespace). 
It should then allocate a dynamic array of size equal to the number of words. The array contains Word structures 
(i.e. array of type Word). The function would then store each word of that sentence to the english field of the 
corresponding structure. The function should then return this array to the calling function using the return statement, 
along with the array size using a reference parameter.

This function should also remove all capitalization and special characters other than letters. Implement the function with 
the following prototype

Word * splitSentence(const string words, int &size); 

Part 2. Write a function that takes in an array of Word structures and the size of the array and converts each english 
field to the corresponding piglatin field.
void convertToPigLatin(Word [] wordArr, int size); 

To do this conversion, if a word starts with a consonant, the piglatin 
conversion of the word involves moving the first letter of the word to the end of the string and then adding “ay” to the 
end.

pig -> igpay

cat -> atcay

dog -> ogday

If the word starts with a vowel, simply add “way” to the end of the word

apple -> appleway

are -> areway

Part 3. Write a function that takes in an array of Word structures and outputs the pig latin part of it to the screen, 
with each word separated by a space.

void displayPigLatin(const Word [] wordArr, int size); Example:

Please enter a string to convert to PigLatin: Casino is nothing but a Goodfellas knockoff 
Output: oodfellasgay isway othingnay utbay away oodfellasgay nockoffkay 

Error conditions: Your program should get rid of all punctuation and special characters other than letters. 
Your program should be able to deal with there being two or more spaces between words.*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Word
{
    string english;
    string piglatin;
};

Word *splitSentence(const string, int&);
void convertToPigLatin(Word[], int);
void displayPigLatin(const Word[], int);

int main()
{
    int size;
    string input;
    Word* arr = nullptr;
    char choice;

    do
    {
        cout << "Please enter a string to convert to PigLatin:";
        getline(cin, input);
        arr = splitSentence(input, size);
        convertToPigLatin(arr, size);
        displayPigLatin(arr, size);       
        do {
            cout << "Would you like to enter another string to convert to Pig Latin? (Y for yes/N for no)";
            cin >> choice;
            if (toupper(choice) != 'Y' && toupper(choice) != 'N')
                cout << "Invalid input for choice." << endl;
        } while (toupper(choice) != 'Y' && toupper(choice) != 'N');
        cin.ignore();
    } while (toupper(choice) != 'N');
    
    return 0;
}

Word *splitSentence(const string words, int& size)
{
    Word* a = nullptr;
    int count = 0;
    istringstream istr(words), istr2;
    string word, actual;

    for(int i = 0; i < words.length();i++)
    {
        if (istr >> word)
        {
            for (int x = 0; x < word.length(); x++)
            {
                if (isalpha(word[x]))
                {
                    count++;
                    actual += word;
                    actual += " ";
                    break;
                }
            }
        }
    }
    size = count;
    a = new Word[size];
    istr2.str(actual);
    for (int i = 0; i < size; i++)
    {
        istr2 >> word;
        for(int x = 0; x < word.length(); x++)
        { 
            if (isalpha(word[x]))
            {
                if (isupper(word[x]))
                {
                    a[i].english += tolower(word[x]);
                }
                else
                {
                    a[i].english += word[x];
                }
            }
        }
    }

    return a;
}

void convertToPigLatin(Word wordArr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        wordArr[i].piglatin = wordArr[i].english;
        if (wordArr[i].english[0] == 'a' || wordArr[i].english[0] == 'e'
            || wordArr[i].english[0] == 'i' || wordArr[i].english[0] == 'o'
            || wordArr[i].english[0] == 'u')
        {
            wordArr[i].piglatin.append("way");
        }
        else
        {
            string temp;
            temp = wordArr[i].english[0];
            temp += "ay";
            wordArr[i].piglatin.erase(0, 1);
            wordArr[i].piglatin.append(temp);     
        }
    }
}

void displayPigLatin(const Word wordArr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << wordArr[i].piglatin << " ";
    }
    cout << endl;
}