//
// Created by JMKov on 8/19/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string n;
int k;
bool asdf[10];
int cnt[10];
vector<int> dig;

void calc() {
    for (int i = 0; i < 10; i++) {
        asdf[i] = false;
        cnt[i] = 0;
    }
    dig.clear();
    for (int i = 0; i < n.size() && dig.size() < k; i++) {
        if (asdf[n[i] - '0']) continue;
        dig.push_back(n[i] - '0');
        asdf[n[i] - '0'] = true;
    }
    for (char i : n) {
        cnt[i - '0']++;
    }
    sort(dig.begin(), dig.end());
}

void increment(int i) {
    if (i == -1) {
        for (int & j : cnt) j = 0;
        cnt[1] = 1;
        cnt[0] = n.size();
        string s = "1";
        for (int j = 0; j < n.size(); j++) s += '0';
        n = s;
        return;
    }
    if (n[i] == '9') {
        increment(i - 1);
        return;
    }
    cnt[n[i] - '0']--;
    n[i]++;
    cnt[n[i] - '0']++;
    for (int j = i + 1; j < n.size(); j++) {
        cnt[n[j] - '0']--;
        cnt[0]++;
        n[j] = '0';
    }
}
void set(int i, int v) {
    cnt[n[i] - '0']--;
    cnt[v]++;
    n[i] = (int) (v + '0');
    for (int j = i + 1; j < n.size(); j++) {
        cnt[n[j] - '0']--;
        cnt[0]++;
        n[j] = '0';
    }
}

void dfs(int i) {
    if (i == n.size()) return;
    calc();

    if (asdf[n[i] - '0']) dfs(i + 1);
    else if (distance(lower_bound(dig.begin(), dig.end(), (n[i] - '0')), dig.end()) == 0) {
        increment(i - 1);
        dfs(i - 1);
    }
    else {
        int basdf = distance(dig.begin(), lower_bound(dig.begin(), dig.end(), (n[i] - '0')));
        set(i, dig[basdf]);
    }
    dfs(i + 1);
}

int main() {
//    for (int x = 1; x < 10; x++) {
//        for (int y = 1; y < 10; y++) {
//
//        }
//    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        calc();
        sort(dig.begin(), dig.end());
        dfs(0);
        cout << n << endl;
    }
    return 0;
}