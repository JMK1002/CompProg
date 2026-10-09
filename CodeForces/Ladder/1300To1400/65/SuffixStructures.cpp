//
// Created by JMKov on 4/23/2023.
//
#include <iostream>
#include <string>
using namespace std;

// array swaps, automaton erases / deletes
int main() {
    string s, t;
    cin >> s >> t;
    int ptr = 0;
    for (int i = 0; i < s.size() && ptr < t.size(); i++) {
        if (t[ptr] == s[i]) {
            ptr++;
        }
    }
    if (ptr == t.size()) {
        cout << "automaton" << endl;
        return 0;
    }
    int letterCount[26];
    for (int i = 0; i < 26; i++) {
        letterCount[i] = 0;
    }
    for (int i = 0; i < s.size(); i++) {
        letterCount[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++) {
        letterCount[t[i] - 'a']--;
    }
    bool array = true;
    for (int i = 0; i < 26; i++) {
        if (letterCount[i] != 0) {
            array = false;
        }
        if (letterCount[i] < 0) {
            cout << "need tree" << endl;
            return 0;
        }
    }
    if (array) {
        cout << "array" << endl;
    }
    else {
        cout << "both" << endl;
    }
    return 0;
}