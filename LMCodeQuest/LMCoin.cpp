#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n = 10;
        double dataVals[n] = { 0 };
        double timeStamps[n];
        long double hashes[n + 1];
        hashes[0] = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (char c : s) {
                dataVals[i] += c - 'a';
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> timeStamps[i];
        }
        for (int i = 1; i <= n; i++) {
            hashes[i] = (timeStamps[i - 1] + dataVals[i - 1] + i + hashes[i - 1]) / 147 * 50;
        }
        cout << (int) round(hashes[n]) << endl;
    }
    return 0;
}