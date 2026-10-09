//
// Created by JMKov on 12/10/2023.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int binSearch(vector<int> w, int element) {
    int low = 0;
    int high = w.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (w[mid] < (element - 0.5)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

void solve() {
    int n, m, k;
    cin >> m >> n >> k;
    int f[n];
    int cnt[m];
    for (int i = 0; i < m; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        f[i]--;
        cnt[f[i]]++;
    }

    vector<int> window;
    int ptr = 0;
    int folderPtr = 0;
    while (window.size() < k - ptr) {
        if (f[ptr] >= folderPtr + k) {
            window.insert(lower_bound(window.begin(), window.end(), f[ptr]), f[ptr]);
        }
        else {
            cnt[f[ptr]]--;
        }
        while (cnt[folderPtr] == 0) {
            folderPtr++;
            int ind = binSearch(window, folderPtr + k - 1);
            window.erase(window.begin() + ind, window.end());
        }
        ptr++;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}