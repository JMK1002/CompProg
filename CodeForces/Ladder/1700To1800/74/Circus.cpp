//
// Created by JMKov on 7/6/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    string asdf, basdf;
    cin >> n >> asdf >> basdf;
    vector<int> bruh[2][2];
    for (int i = 0; i < n; i++) {
        bruh[asdf[i] - '0'][basdf[i] - '0'].push_back(i);
    }
    for (int d = 0; d <= bruh[1][1].size(); d++) {
        for (int b = 0; b <= bruh[0][1].size(); b++) {
            int c = (bruh[0][1].size() + bruh[1][1].size() - b - 2 * d);
            int a = n / 2 - b - c - d;
//            cout << a << b << c << d << endl;
            if (a <= bruh[0][0].size() && c <= bruh[1][0].size()) {
                for (int i = 0; i < a; i++) cout << bruh[0][0][i] + 1 << " ";
                for (int i = 0; i < b; i++) cout << bruh[0][1][i] + 1 << " ";
                for (int i = 0; i < c; i++) cout << bruh[1][0][i] + 1 << " ";
                for (int i = 0; i < d; i++) cout << bruh[1][1][i] + 1 << " ";
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}