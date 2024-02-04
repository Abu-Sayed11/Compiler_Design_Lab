/*
Write a program to generate a syntax tree for the sentence a+b*c with the following 
grammar: E —> E+E|E-E|E*E|E/E|(E)|a|b|c 
*/
//Sample input : a+b*c

#include <bits/stdc++.h>
using namespace std;

vector<string> Tree(15,string(15,' '));

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void syntaxTree(string expression) {

    int row = 0, col = 2;

    for (int i = 0; expression[i]; i++) {
        if (isOperator(expression[i])) {
            Tree[row][col] = expression[i];
            Tree[row+1][col-1] = '/';
            Tree[row+1][col+1] = '\\';
            Tree[row+2][col-2] = expression[i-1];
            row += 2;
            col += 2;
        }
    }

    Tree[row][col] = expression.back();
}

int main() {

    freopen("input.txt", "r", stdin);

    string expression;
    cin >> expression;

    syntaxTree(expression);

    cout << "Syntax Tree:\n";

    for (string x : Tree) {
        cout << x << "\n";
    }
}
