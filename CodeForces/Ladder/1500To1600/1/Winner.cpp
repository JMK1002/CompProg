//
// Created by JMKov on 5/5/2023.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> scores;
    string names[n];
    int vals[n];
    for (int i = 0; i < n; i++) {
        cin >> names[i] >> vals[i];
        scores[names[i]] += vals[i];
    }
    vector<int> sortedScores;
    for (const auto& i : scores) {
        sortedScores.push_back(i.second);
    }
    sort(sortedScores.begin(), sortedScores.end());
    int mx = sortedScores[sortedScores.size() - 1];
    vector<string> possible;
    scores = *new map<string, int>;
    for (int i = 0; i < n; i++) {
        scores[names[i]] += vals[i];
        if (scores[names[i]] >= mx) {
            possible.push_back(names[i]);
        }
    }
    for (string i : possible) {
        if (scores[i] == mx) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}