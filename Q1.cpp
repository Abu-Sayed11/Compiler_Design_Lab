/*
Write a C program that read the following string:
“Md. Tareq Zaman, Part-3, 2011”
a) Count number of words, letters, digits and other characters.
b) Separates letters, digits and others characters.
*/

#include<bits/stdc++.h>
using namespace std;

bool otherCharCheck(char ch) {
    string others = ".-,/;':?";
    bool mark = false;
    for (int i = 0; i < others[i]; i++)
    {
        if (others[i] == ch)
        {
            mark = true;
            break;
        }
    }
    return mark;
}

int main ()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string input;
    getline(cin, input);

    int word = 0, letter = 0, digit = 0, other = 0;
    char space = ' ';
    vector<char> letters, digits, others;

    for (int i = 0; input[i]; i++) {
        if (input[i] == space) {
            word++;
        }else if (otherCharCheck(input[i])) {
            other++;
            others.push_back(input[i]);
        }else if (isdigit(input[i])) {
            digit++;
            digits.push_back(input[i]);
        }else {
            letter++;
            letters.push_back(input[i]);
        }
    }

    cout << "Words - " << ++word << endl;
    cout << "Letters - " << letter << endl;
    for (int i = 0; i < letters.size(); i++)
    {
        if (i == letters.size() - 1)
        {
            cout << letters[i] << endl;//For omitting comma in the last letter 
            continue;
        }
        cout << letters[i] << ", ";
    }
    cout << "Digits - " << digit << endl;
    for (int i = 0; i < digits.size(); i++)
    {
        if (i == digits.size() - 1)
        {
            cout << digits[i] << endl;
            continue;
        }
        cout << digits[i] << ", ";
    }
    cout << "Other chars - " << other << endl;
    for (int i = 0; i < others.size(); i++)
    {
        if (i == others.size() - 1)
        {
            cout << others[i] << endl; 
            continue;
        }
        cout << others[i] << " ";
    }

    return 0;
}