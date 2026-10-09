//
// Created by JMKov on 4/8/2023.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int count[n][28];
    int charsNeeded[n];
    vector<int> questionMarks;
    // checking if 0
    if (n < 26) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            questionMarks.insert(questionMarks.end(), i);
        }
    }
    // initializing
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 28; j++) {
            count[i][j] = 0;
        }
    }
    // initializing count[0]
    count[0][s[0] - '?']++;
    // initializing vals from 1 to 26
    for (int i = 1; i < 26; i++) {
        for (int j = 0; j < 28; j++) {
            count[i][j] = count[i - 1][j];
        }

        count[i][s[i] - '?']++;
    }

    // initializing vals from 26 to n
    for (int i = 26; i < n; i++) {
        for (int j = 0; j < 28; j++) {
            count[i][j] = count[i - 1][j];
        }
        count[i][s[i] - '?']++;
        count[i][s[i - 26] - '?']--;
    }

    // initializing and filling charsNeeded
    for (int i = 0; i < n; i++) {
        charsNeeded[i] = 0;
        for (int j = 2; j < 28; j++) {
            charsNeeded[i] += (count[i][j] == 0);
        }
//        cout << charsNeeded[i] << " " << count[i][0] << endl;
        if (charsNeeded[i] == count[i][0]) {
            if (questionMarks.empty()) {
                cout << s << endl;
                return 0;
            }
            for (int j = 0; questionMarks[0] < i - 26; j++) {
                questionMarks.erase(questionMarks.begin());
            }
//            cout << questionMarks.size() << endl;
            for (int j = 2; j < 28; j++) {
                if (count[i][j] == 0) {
                    s[questionMarks[0]] = (char) ('A' + j - 2);
                    questionMarks.erase(questionMarks.begin());
                }
            }
            for (int i = 0; i < n; i++) {
                if (s[i] == '?') {
                    s[i] = 'A';
                }
            }
            cout << s << endl;
            return 0;
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < 28; j++) {
//            cout << count[i][j] << " ";
//        }
//        cout << endl;
//    }
    cout << -1 << endl;
    return 0;
}