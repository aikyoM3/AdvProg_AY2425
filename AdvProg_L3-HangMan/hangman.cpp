#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "hangman.h"

using std::string;
using std::vector;
using std::ifstream;
using std::domain_error;
using std::cin;

int generateRandomNumber(const int min, const int max)
{
    std::srand(std::time(nullptr));
    return min + std::rand() % (max - min + 1);
}

bool isCharInWord(const char ch, const string& word)
{
    return word.find(ch) != string::npos;
}

string chooseWordFromList(const vector<string>& wordList, int index)
{
    if (index < 0 || index >= wordList.size()) {
        throw domain_error("Index out of range");
    }
    string answer = wordList[index];
    for (char& c : answer) {
        c = tolower(c);
    }
    return answer;
}

string generateHiddenCharacters(string answerWord)
{
    return string(answerWord.length(), '-');
}

void updateSecretWord(string& secretWord, const char ch, const string& word)
{
    for (size_t i = 0; i < word.length(); i++) {
        if (word[i] == ch) {
            secretWord[i] = ch;
        }
    }
}

void updateEnteredChars(const char ch, string& chars)
{
    chars += ch;
}

void updateIncorrectGuess(int& incorrectGuess)
{
    incorrectGuess++;
}

void processData(const char ch, const string& word, 
                string& secretWord, 
                string& correctChars, 
                int& incorrectGuess, string& incorrectChars)
{
    if (isCharInWord(ch, word)) {
        updateSecretWord(secretWord, ch, word);
        updateEnteredChars(ch, correctChars);
    } else {
        updateIncorrectGuess(incorrectGuess);
        updateEnteredChars(ch, incorrectChars);
    }
}
