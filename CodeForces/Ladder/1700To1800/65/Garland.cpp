//
// Created by JMKov on 7/2/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int ans = 0;
    cin >> n;
    bool taken[n];
    vector<int> arr(n);
    for (int i = 0; i < n; i++) taken[i] = false;
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
        arr[i]--;
        if (arr[i] >= 0) taken[arr[i]] = true;
        if (i > 0 && arr[i - 1] <= -1 && arr[i] <= -1) {
            arr[i - 1] += arr[i];
            arr.erase(arr.begin() + i);
            i--;
        }
    }
    if (arr.size() == 1 && arr[0] < 0) {
        cout << 0 + (arr[0] < -1) << endl;
        return 0;
    }
    int even = 0;
    int odd = 0;
    for (int i = 0; i < n; i++) if (!taken[i]) {
        even += !(i & 1);
        odd += (i & 1);
    }
    for (int i = 1; i < arr.size(); i++) {
        ans += (arr[i] >= 0 && arr[i - 1] >= 0 && (arr[i - 1] & 1) != (arr[i] & 1));
    }
//    cout << ans << endl;
//    for (int i : arr) cout << i << " ";
//    cout << endl;
    vector<pair<int, int>> asdf;
    for (int i = 1; i < arr.size() - 1; i++) {
        if (arr[i] > -1) continue;
        int v = (arr[i - 1] & 1) + (arr[i + 1] & 1);
        if (v == 0) asdf.emplace_back(arr[i] * -1, 0);
        else if (v == 2) asdf.emplace_back(arr[i] * -1, 1);
        else ans++;
    }
    sort(asdf.begin(), asdf.end());
    for (pair<int, int> p : asdf) {
//        cout << p.first << " " << p.second << " " << even << " " << odd << endl;
        if (p.second == 0) {
            if (even >= p.first) {
                even -= p.first;
            }
            else {
                odd--;
                ans += 2;
            }
        }
        else {
            if (odd >= p.first) {
                odd -= p.first;
            }
            else {
                even--;
                ans += 2;
            }
        }
    }
    if (arr[0] < 0 && arr[arr.size() - 1] < 0 && arr[0] < arr[arr.size() - 1]) {
        if (arr[arr.size() - 1] < 0) {
            if (arr[arr.size() - 2] & 1) {
                if (odd >= arr[arr.size() - 1] * -1) {
                    odd -= arr[arr.size() - 1] * -1;
                }
                else {
                    ans++;
                    even--;
                }
            }
            else {
                if (even >= arr[arr.size() - 1] * -1) {
                    even -= arr[arr.size() - 1] * -1;
                }
                else {
                    ans++;
                    odd--;
                }
            }
        }
        if (arr[0] < 0) {
            if (arr[1] & 1) {
                if (odd >= arr[0] * -1) {
                    odd -= arr[0] * -1;
                }
                else {
                    ans++;
                    even--;
                }
            }
            else {
                if (even >= arr[0] * -1) {
                    even -= arr[0] * -1;
                }
                else {
                    ans++;
                    odd--;
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
    if (arr[0] < 0) {
        if (arr[1] & 1) {
            if (odd >= arr[0] * -1) {
                odd -= arr[0] * -1;
            }
            else {
                ans++;
                even--;
            }
        }
        else {
            if (even >= arr[0] * -1) {
                even -= arr[0] * -1;
            }
            else {
                ans++;
                odd--;
            }
        }
    }
    if (arr[arr.size() - 1] < 0) {
        if (arr[arr.size() - 2] & 1) {
            if (odd >= arr[arr.size() - 1] * -1) {
                odd -= arr[arr.size() - 1] * -1;
            }
            else {
                ans++;
                even--;
            }
        }
        else {
            if (even >= arr[arr.size() - 1] * -1) {
                even -= arr[arr.size() - 1] * -1;
            }
            else {
                ans++;
                odd--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// 2
// 0 1
// 1

// 17
// 2 0 0 4 0 6 0 1 0 8 9 11 13 15 0 0 17
// 2 10 12 4 14 6 3 1 5
// 3