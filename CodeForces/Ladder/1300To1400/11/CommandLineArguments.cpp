//
// Created by JMKov on 4/5/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    char a[1000000];
    cin.getline(a, 1000000);
    string s = a;
//    cout << s << endl;
    bool inQuote = false;
    string current;
    s = " " + s + " ";
    for (char c : s) {
        if (c == '\"') {
            if (inQuote) {
                cout << "<" << current.substr(1) << ">" << endl;
            }
            current = "";
            inQuote = !inQuote;
        }
        else if (c == ' ' && !inQuote) {
            if (current != "\"" && current != " " && !current.empty()) {
                cout << "<" << current.substr(1) << ">" << endl;
            }
            current = "";
        }
//        cout << current << endl;
        current += c;
    }
    return 0;
}