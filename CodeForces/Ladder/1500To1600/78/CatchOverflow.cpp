//
// Created by JMKov on 5/30/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long forCount = 1;
    long long v = 0;
    int sizeBeforeAboveLimit = 0;
    bool aboveLimit = false;
    vector<int> fors;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "add") {
            if (aboveLimit) {
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
            v += forCount;
        }
        else if (s == "for") {
            int a;
            cin >> a;
            fors.push_back(a);
            if (!aboveLimit) forCount *= a;
            if (!aboveLimit && (forCount >= ((long long) 1 << 32))) {
                aboveLimit = true;
                sizeBeforeAboveLimit = fors.size();
            }
        }
        else {
            if (aboveLimit && fors.size() - 1 < sizeBeforeAboveLimit) {
                aboveLimit = false;
            }
            if (!aboveLimit) forCount /= fors[fors.size() - 1];
            fors.erase(fors.begin() + (fors.size() - 1));
        }
        if (v >= ((long long) 1 << 32) || v < 0) {
            cout << "OVERFLOW!!!" << endl;
            return 0;
        }
    }
    cout << v << endl;
    return 0;
}