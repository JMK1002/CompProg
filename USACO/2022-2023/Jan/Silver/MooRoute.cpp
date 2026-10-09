//
// Created by JMKov on 12/19/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string ans;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] /= 2;
    }
    int low = 0;
    int high = n - 1;
    vector<pair<int, int>> rightMoves;
    while (low <= high) {
        int end = high;
        for (int i = low; i <= high; i++) {
            if (i != low && arr[i] <= arr[i - 1] && arr[i] == 1) {
                end = i - 1;
                break;
            }
            arr[i]--;
        }
        rightMoves.emplace_back(low, end);
        while (low < n && arr[low] == 0) low++;
        while (high >= 0 && arr[high] == 0) high--;
    }
    for (int i = 0; i < rightMoves.size(); i++) {
        for (int j = rightMoves[i].first; j <= rightMoves[i].second; j++) {
            ans += 'R';
        }
        if (i == rightMoves.size() - 1) continue;
        for (int j = rightMoves[i].second; j >= rightMoves[i + 1].first; j--) {
            ans += 'L';
        }
    }
    for (int i = 0; i <= rightMoves[rightMoves.size() - 1].second; i++) ans += 'L';
    cout << ans << endl;
    return 0;
}
//10
//2 2 4 4 6 6 4 6 2 2