//
// Created by JMKov on 5/11/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool moneySort(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = pair<int, int>(a, b);
    }
    sort(arr.begin(), arr.end(), moneySort);
//    for (auto a : arr) {
//        cout << a.first << " " << a.second << endl;
//    }
    long long friendshipPrefix[n];
    friendshipPrefix[0] = arr[0].second;
    long long mx = -1;
    for (int i = 1; i < n; i++) {
        friendshipPrefix[i] = friendshipPrefix[i - 1] + arr[i].second;
    }
    for (int i = 0; i < n; i++) {
        double target = arr[i].first + d - 0.5;
        int low = 0;
        int high = n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid].first < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
//            cout << low << " " << high << endl;
        }
        low -= (arr[low].first >= arr[i].first + d);
        if (i == 0) {
            mx = max(friendshipPrefix[low], mx);
//            cout << friendshipPrefix[low] << endl;
        }
        else {
            mx = max(mx, friendshipPrefix[low] - friendshipPrefix[i - 1]);
//            cout << friendshipPrefix[low] - friendshipPrefix[i - 1] << endl;
        }
    }
    cout << mx << endl;
    return 0;
}