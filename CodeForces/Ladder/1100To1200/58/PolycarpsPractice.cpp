//
// Created by JMKov on 3/25/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> difficulties(n);
    vector<int> sortedDifficulties(n);
    for (int i = 0; i < n; i++) {
        cin >> difficulties[i];
    }
    sortedDifficulties = difficulties;
    sort(sortedDifficulties.begin(), sortedDifficulties.end());
    int s = 0;
    for (int i = n - 1; i >= n - k; i--) {
        s += sortedDifficulties[i];
    }
    cout << s << endl;
    int count = 1;
    for (int i = 0; i < n; i++) {
        for (int j = sortedDifficulties.size() - 1; j >= sortedDifficulties.size() - k; j--) {
            if (difficulties[i] == sortedDifficulties[j]) {
                sortedDifficulties.erase(sortedDifficulties.begin() + j);
                k--;
                if (k == 0) {
                    break;
                }
                cout << count << " ";
                count = 0;
                break;
            }
        }
        count++;
    }
    cout << count - 1 << endl;
    return 0;
}