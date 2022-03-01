#include <iostream>
using namespace std;
// a recursive program to test whether a given string can be segmented into space seperated words in dictionary

// a utility function to check whether a word is present in a dictionary or not.
// an array of strings is used for dictionary . Using array of strings for a dictionary is definitely not a good idea . We have used for simplicity of program

int dictionary_contains(string word)
{
    string dictionary[] = {"mobie", "samsumg", "sam", "sung",
                           "man", "mango", "icecream", "and",
                           "go", "i", "like", "ice", "cream"};

    int size = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}

// returns true if string can be segmented into space seperated words , otherwise returns false

bool word_break(string str)
{
    int size = str.size();

    // Base case
    if (size == 0)
        return true;

    // Try all prefixes of length from 1 to size
    for (int i = 1; i <= size; i++)
    {
        /*
        The parameter for dictionary_contains is
        str.substr(0,i) which is prefix (of input string)
        of length 'i' . We first check whether
        current prefix is in dictionary . Then we recursively
        check for remaining string str.substr(i,size-i) which is suffix of length size-i
        */

        if (dictionary_contains(str.substr(0, i)) && word_break(str.substr(i, size - i)))
            return true;
    }

    // if we have tried all prefixes and none of them worked return false
    return false;
}

int main()
{
    word_break("ilikesamsung") ? cout << "Yes" << endl : cout << "No" << endl;
    word_break("iiiiiiii") ? cout << "Yes" << endl : cout << "No" << endl;
    word_break("") ? cout << "Yes" << endl : cout << "No" << endl;
    word_break("ilikelikeimangoiii") ? cout << "Yes" << endl : cout << "No" << endl;
    word_break("samsungandmango") ? cout << "Yes" << endl : cout << "No" << endl;
    word_break("samsungandmangok") ? cout << "Yes" << endl : cout << "No" << endl;
    return 0;
}
