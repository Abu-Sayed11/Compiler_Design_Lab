/*
Write a program that read the following string:
“Munmun is the student of Computer Science & Engineering”.
a) Count how many vowels and Consonants are there?
b) Find out which vowels and consonants are existed in the above string?
c) Divide the given string into two separate strings, where one string only contains 
 the words started with vowel, and another contains the words started with consonant.
*/

#include<bits/stdc++.h>
using namespace std; 

bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main ()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> input;
    string temp;

    while(cin >> temp) {
        input.push_back(temp);
    }

    vector<char>vowel, consonant;
    vector<string> vowelWord, consonantWord;

    for (int i = 0; i < input.size(); i++) {
        if (isVowel(input[i][0])) {
            vowelWord.push_back(input[i]);
        }else {
            consonantWord.push_back(input[i]);
        }
        for (int j = 0; input[i][j]; j++) {
            if (isVowel(input[i][j])) {
                vowel.push_back(input[i][j]);
            }else {
                consonant.push_back(input[i][j]);
            }
        }
    }
    
    cout << "Vowel: " << vowel.size() << endl;
    for (int i = 0; i < vowel.size(); i++) {
        cout << vowel[i] << " ";
    }
    cout << endl;

    cout << "Consonant: " << consonant.size() << endl;
    for (int i = 0; i < consonant.size(); i++) {
        cout << consonant[i] << " ";
    }
    cout << endl;

    cout << "String started with vowel are : ";
    for (int i = 0; i < vowelWord.size(); i++) {
        cout << vowelWord[i] << " ";
    }
    cout << endl;
    
    cout << "String started with consonant are : ";
    for (int i = 0; i < consonantWord.size(); i++) {
        cout << consonantWord[i] << " ";
    }

    return 0;
}