/*
Build a lexical analyzer implementing the following regular expressions:
Integer variable = (i-nI-N)(a-zA-Z0-9)*
ShortInt Number = (1-9)|(1-9)(0-9)|(1-9)(0-9)(0-9)|(1-9)(0-9)(0-9)(0-9)
LongInt Number = (1-9)(0-9)(0-9)(0-9)(0-9)+
Invalid Input or Undefined = Otherwise
*/
// Sample input: Iakd34

#include <bits/stdc++.h>
#define int long long int

using namespace std;

bool isVariable(string str){

    bool isStartOk = false;

    if ((tolower(str[0]) >= 'i') && (tolower(str[0]) <= 'n')) {
        isStartOk = true;
    }

    bool isRestOk = true;

    for (int i = 1; str[i]; i++) {
        if (!isalpha(str[i]) && !isdigit(str[i])) {
            isRestOk = false;
            break;
        }
    }

    if (isStartOk && isRestOk) {
        return true;
    }else {
        return false;
    }
    
}

bool isInt(string str){

    for (int i = 0; str[i]; i++){
        if (isdigit(str[i])) {
            continue;
        }else{
            return false;
        }
    }
    return true;
}

int32_t main()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string word;
    cin >> word;

    if (isVariable(word)) {
        cout << "Integer Variable " << endl;
    }else if (word.size() <= 4 && isInt(word)) {
        cout << "ShortInt Number " << endl;
    }else if (isInt(word)) {
        cout << "LongInt Number " << endl;
    }else {
        cout << "Invalid input or Undefined" << endl;
    }

    return 0;
}