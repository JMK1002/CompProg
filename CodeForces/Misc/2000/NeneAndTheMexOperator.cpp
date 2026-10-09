//
// Created by JMKov on 5/12/2024.
//
#include <iostream>
#include <vector>

using namespace std;

int arr[18];
int n;
pair<int, int> ans; // binstring, sum;
vector<pair<int, int>> seq;

void construct(int l, int r) {
    if (l < r) {
        construct(l, r - 1);
        seq.push_back({l, r - 1});
        for (int i = l + 1; i <= r - 1; i++) seq.push_back({i, i});
        construct(l + 1, r);
    }
}

int sum(int c) {
    int run = 1;
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (run & c) {
            cnt++;
        }
        else {
            sum += arr[i];
            sum += cnt * cnt;
            cnt = 0;
        }
        run <<= 1;
    }
    sum += cnt * cnt;
    return sum;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < (1 << n); i++) {
        int s = sum(i);
        if (ans.second < s) {
            ans.first = i;
            ans.second = s;
        }
    }

    int c = ans.first;
    int run = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (run & c) {
            cnt++;
        }
        else {
            if (cnt) {
                for (int j = i - cnt; j < i; j++) if (arr[j]) seq.push_back({j, j});
                construct(i - cnt, i - 1);
                seq.push_back({i - cnt, i - 1});
            }
            cnt = 0;
        }
        run <<= 1;
    }
    if (cnt) {
        for (int j = n - cnt; j < n; j++) if (arr[j]) seq.push_back({j, j});
        construct(n - cnt, n - 1);
        seq.push_back({n - cnt, n - 1});
    }

    cout << ans.second << " " << seq.size() << endl;

    for (pair<int, int> p : seq) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
    return 0;
}