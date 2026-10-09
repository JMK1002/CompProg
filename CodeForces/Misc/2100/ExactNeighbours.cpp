//
// Created by JMKov on 6/21/2024.
//
#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> arr[200004];
pair<int, int> ans[200004];
int ordAns[200004];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + n);
    reverse(arr, arr + n);
    cout << "YES" << endl;
    cout << "1 1" << endl;
    int y = 1;
    ordAns[arr[0].second] = 1;
    for (int i = 1; i < n - 1; i++) {
        ordAns[arr[i].second] = arr[i - 1].second + 1;
    }
    for (int i = 0; i < n - 1; i++) {
        ans[arr[i].second].first = i + 2;
        if (arr[i].first == 0) {
            ans[arr[i].second].second = i + 1;
            ans[arr[i].second].second = 1;
            ordAns[arr[i].second] = arr[i].second + 1;
        }
        else {
            ans[arr[i].second].second = y + ((i % 2 == 0) ? 1 : -1) * (arr[i].first - 1);
            y += ((i % 2 == 0) ? 1 : -1) * (arr[i].first - 1);
        }
    }
    for (int i = 1; i < n; i++) cout << ans[i].first << " " << ans[i].second << endl;
    cout << 1 << " ";
    for (int i = 1; i < n; i++) cout << ordAns[i] << " ";
    cout << endl;
    return 0;
}