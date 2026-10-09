//
// Created by JMKov on 5/24/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int input[n - 1][2];
    int colors[n];
    for (int i = 0; i < n - 1; i++) {
        cin >> input[i][0] >> input[i][1];
        input[i][0]--; input[i][1]--;
    }
    for (int i = 0; i < n; i++) cin >> colors[i];
    vector<int> asdf;
    bool started = false;
    for (int i = 0; i < n - 1; i++) {
        if (colors[input[i][0]] != colors[input[i][1]]) {
            if (asdf.empty() && !started) {
                started = true;
                asdf.push_back(input[i][0]);
                asdf.push_back(input[i][1]);
            }
            else if (started) {
                vector<int> placeholder;
                for (int j : input[i]) {
                    for (int q : asdf) {
                        if (j == q) {
                            placeholder.push_back(j);
                        }
                    }
                }
                asdf = placeholder;
                if (asdf.empty()) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    if (!started) {
        cout << "YES\n" << 1 << endl;
    }else
    cout << "YES\n" << asdf[0] + 1 << endl;
    return 0;
}