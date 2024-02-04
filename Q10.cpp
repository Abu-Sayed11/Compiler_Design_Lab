/*
Write a program to implement a shift reducing parsing.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout << "Enter the number of production rule : ";
    cin >> n;

    cin.ignore();

    vector<string>lg(n), rg(n);

    for (int i = 0; i < n; i++) {

        string temp;
        cout << "Enter the production rule-" << i+1 << ": ";
        getline(cin, temp);

        bool left = true;
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == ' ') continue;
            else if (temp[j] == '=') {
                left = false;
            }else {
                if (left) {
                    lg[i].push_back(temp[j]);
                }else {
                    rg[i].push_back(temp[j]);
                }
            }
        }
    }

    cout << "\nGrammer: " << endl;
    for (int i = 0; i < n; i++) {
        cout << lg[i] << " -> " << rg[i] << endl;
    }

    string input;
    cout << "\nEnter a input string: ";
    cin >> input;

    string st = "$";
    input.push_back('$');

    while(input != "$") {

        st.push_back(input[0]);
        input.erase(input.begin());

        cout << "Stack: " << st << endl;
        cout << "Input Butter: " << input << endl;
        cout << "SHIFT" << endl << endl;

        for (int i = 0; i < n; i++) {

            bool reduce = false;

            if (st.find(rg[i]) < st.size()) {

                st.erase(st.find(rg[i]),st.length());
                st += lg[i];
                
                cout << "Stack: " << st << endl;
                cout << "Input Buffer: " << input << endl;
                cout << "Reduce: " << lg[i] << " -> " << rg[i] << endl << endl;

                reduce = true;
            }
            if (reduce) i = -1;
        }
    }

    input += lg[0];
    
    if (st == input) cout << "Accepted" << endl;
    else cout << "Rejected" << endl;

    return 0;
}