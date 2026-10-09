//
// Created by JMKov on 7/5/2024.
//
#include <iostream>
#include <set>
#include <queue>

using namespace std;

int n;
int arr[200005];
int available[200005];
bool erased[200005];
int dist[200005];
set<int> add[200005];
set<int> erase[200005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> curr; // endpos, ind

bool works(int val) {
    while (!curr.empty()) curr.pop();
    for (int i = 0; i < n; i++) {
        available[i] = arr[i];
        erased[i] = false;
    }
    for (int i = 0; i < n; i++) {
        for (int j : add[i]) {
            if (available[j] == 0) {
                erased[j] = true;
                continue;
            }
            curr.push({min(n - 1, j + dist[j]), j});
        }

        int x = 0;
        while (!curr.empty() && x < val) {
            pair<int, int> p = curr.top();
            int amnt = min(val - x, available[p.second]);
            x += amnt;
            available[p.second] -= amnt;
            if (available[p.second] == 0) {
                curr.pop();
                erased[p.second] = true;
            }
        }

        for (int j : erase[i]) {
            if (!erased[j]) return false;
        }
    }
    return true;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n;
    int sum = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        mx = max(arr[i], mx);
    }
    for (int i = 0; i < n; i++) {
        cin >> dist[i];
        add[max(0, i - dist[i])].insert(i);
        erase[min(n - 1, i + dist[i])].insert(i);
    }
//    for (int i = 0; i < n; i++) cout << works(i) << " ";
//    cout << endl;
    int low = max(0, sum / n - 2);
    int high = mx + 2;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (works(mid)) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    if (works(0)) cout << 0 << endl;
    else cout << low + 1 << endl;

    for (int i = 0; i <= n; i++) {
        add[i].clear();
        erase[i].clear();
    }
    return 0;
}