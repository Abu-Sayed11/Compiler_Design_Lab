/*
Build a lexical analyzer implementing the following regular expressions:
Float variable = (a-hA-Ho-zO-Z)(a-zA-Z0-9)*
Float Number = 0.(0-9)(0-9)|(1-9)(0-9)*.(0-9)(0-9)
Double Number = 0.(0-9)(0-9)(0-9)+|(1-9)(0-9)*.(0-9)(0-9)(0-9)+
Invalid Input or Undefined = Otherwise
*/

#include <bits/stdc++.h>
using namespace std;

bool checkFloatVariable(string str) {

    bool isStartOk = false;

    if ((tolower(str[0]) >= 'a' && tolower(str[0]) <= 'h') || (tolower(str[0]) >= 'o' && tolower(str[0]) <= 'z')) {
        isStartOk = true;
    }

    bool isRestOk = true;

    for (int i = 1; i < str.length(); i++) {
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

bool checkFloatNumber(string str)
{
    int size = str.size();

    if (size < 4 || (str[0] == '0' && isdigit(str[1])) || (str[0] == '0' && str[1] == '0')) return false;

    int digitAfterPoint = 0;
    int gotPoint = 0;

    for (int i = 0; i < size; i++) {
        if (str[i] == '.'){
            gotPoint++;
        }else {
            if (gotPoint) digitAfterPoint++;
        }
    }

    if (digitAfterPoint != 2 || gotPoint == 0 || gotPoint > 1) return false;

    return true;
}

bool checkDoubleNumber(string str)
{
    int size = str.size();

    if (size <= 4 || (str[0] == '0' && isdigit(str[1])) || (str[0] == '0' && str[1] == '0')) return false;

    int digitAfterPoint = 0;
    int gotPoint = 0;

    for (int i = 0; i < size; i++) {
        if (str[i] == '.') {
            gotPoint++;
        }else {
            if (gotPoint) digitAfterPoint++;
        }
    }

    if (digitAfterPoint <= 2 || gotPoint == 0 || gotPoint > 1) return false;

    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int testcase;
    cin >> testcase;

    while (testcase--){

        string str;
        cin >> str;

        cout << "Scanned : " << str << endl;

        if (checkFloatVariable(str)) {
            cout << "Float Variable" << endl;
        }else if (checkFloatNumber(str)) {
            cout << "Float Number" << endl;
        }else if (checkDoubleNumber(str)) {
            cout << "Double Number" << endl;
        }else {
            cout << "Invalid Input" << endl;
        }

        cout << "\n";
    }

    return 0;
}