// 7. Write a program to recognize C++
// 1. Keyword 2. Identifier 3. Operator 4. Constant
// sample input: "Abu Sayeed" int 43

#include <bits/stdc++.h>
using namespace std;

char singleQuote = '\'';
char doubleQuote = '\"';

vector<string> keywords = {"true", "false", "or", "and", "for", "if", "else", "do", "while", "break", "continue", "int", "float", "double", "bool", "long", "unsigned", "char", "string", "void", "auto", "new", "switch", "namespace", "class", "const", "sizeof", "typedef", "xor", "delete", "nullptr"};

vector<string> operators = {
    "+",
    "^",
    "-",
    "*",
    "/",
    "%",
    "++",
    "--",
    "+=",
    "-=",
    "%=",
    "*=",
    "/=",
    "==",
    "!=",
    ">",
    "<",
    ">>",
    "<<",
    ">=",
    "<=",
    "%=",
    "%",
    "||",
    "&&",
    "&",
    "="};

bool isConstant(string str) {

    bool isConstant = false;

    if (str[0] == doubleQuote && str[str.size() - 1] == doubleQuote) return true;
    else if (str[0] == singleQuote && str[str.size() - 1] == singleQuote && str.size() == 3) return true;
    else if (isdigit(str[0])) {

        isConstant = true;
        int pointCount = 0;

        // Check if rest of the characters are number (and 1 point)
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == '.') {
                pointCount++;
                continue;
            }
            if (!isdigit(str[i])) {
                isConstant = false;
                break;
            }
        }
        if (pointCount <= 1 && isConstant) return true;
        else return false;
    }
    return false;
}

bool isKeyword(string str) {
    if (binary_search(keywords.begin(), keywords.end(), str)) return true;
    else return false;
}

bool isOperator(string str) {
    if (binary_search(operators.begin(), operators.end(), str)) return true;
    else return false;
}

bool isIdentifier (string str) {
    bool check = false;
    if (isalpha(str[0]) || str[0] == '_') {
        check = true;
        for (int i = 1; i < str.size(); i++) {
            if (!isalpha(str[i]) && !isdigit(str[i]) && str[i] != '_') {
                check = false;
                break;
            }
        }
    }
    if (check) return true;
    else return false;
}

vector<string> seperateWords(string str) {
    vector<string> words;
    string temp = "";
    for (auto i : str) {
        if (i == ' ') {
            words.push_back(temp);
            temp = "";
        }else {
            temp += i;
        }
    }
    words.push_back(temp);
    return words;
}


int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    sort(keywords.begin(), keywords.end());
    sort(operators.begin(), operators.end());

    string input;
    getline(cin, input);

    vector<string> lexemes = seperateWords(input);

    for (auto i : lexemes) {
        cout << i << " " << endl;
        if (isConstant(i)) {
            cout << "Constant" << endl;
        }else if (isKeyword(i)) {
            cout << "Keyword" << endl;
        }else if (isOperator(i)) {
            cout << "Operator" << endl;
        }else if (isIdentifier(i)) {
            cout << "Identifier" << endl;
        }
    }

    return 0;
}