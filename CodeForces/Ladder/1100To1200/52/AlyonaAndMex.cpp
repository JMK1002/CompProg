//
// Created by JMKov on 3/24/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> srt(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        srt[i] = a;
    }
    sort(srt.begin(), srt.end());
    srt[0] = 1;
    for (int i = 1; i < n; i++) {
        srt[i] = min(srt[i - 1] + 1, srt[i]);
    }
    cout << srt[n - 1] + 1 << endl;
    return 0;
}