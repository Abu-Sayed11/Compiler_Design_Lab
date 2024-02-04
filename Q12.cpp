/*
Write a program to build a lexical analyzer implementing the following regular 
expressions. It takes a text as input from a file (e.g. input.txt) and display output in 
console mode: E -> EAE|(E)|ID 
              A -> + | - | * | /
              ID -> any valid identifier | any valid integer 
*/
//Sample input : a+b*c

#include <bits/stdc++.h>
using namespace std;

void replace(string str) {

    string newstr = "";

    for (int i = 0; str[i]; i++) {
        if (str[i] == '(' or str[i] == ')' or str[i] == '+' or str[i] == '-' or str[i] == '*' or str[i] == '/') {
            newstr.push_back(str[i]);
        }else {
            newstr.push_back('E');
            // if (newstr[newstr.size() - 1] != 'E') {
            //     newstr.push_back('E');
            // }
        }
    }

    str = newstr;
    cout << str << endl;
}

bool operatorCheck(string str) {

    int n = str.size() - 1;

    if (str[0] == '+' or str[0] == '-' or str[0] == '*' or str[0] == '/') return false;
    if (str[n] == '+' or str[n] == '-' or str[n] == '*' or str[n] == '/') return false;

    for (int i = 1; str[i]; i++) {
        if (str[i] == '+' or str[i] == '-' or str[i] == '*' or str[i] == '/') {
            if (str[i - 1] == '+' or str[i - 1] == '-' or str[i - 1] == '*' or str[i - 1] == '/' or str[i-1] == '(') {
                return false;
            }
        }
        if (str[i - 1] == '+' or str[i - 1] == '-' or str[i - 1] == '*' or str[i - 1] == '/') {
            if (str[i] == ')') {
                return false;
            }
        }
    }

    return true;
}

bool bracketCheck(string str) {

    stack<char> brackets;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') {
            brackets.push('(');
        }else if (str[i] == ')') {
            if (brackets.size()) {
                brackets.pop();
            }else {
                return false;
            }
        }
    }

    if (brackets.size() == 0) return true;
    else return false;
}

int main() {

    freopen("input.txt", "r", stdin);

    string input;
    cin >> input;

    replace(input);

    if (operatorCheck(input) && bracketCheck(input)) {
        cout << "Valid" << endl;
    }else {
        cout << "Invalid" << endl;
    }

    return 0;
}