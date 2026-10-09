//
// Created by JMKov on 5/5/2023.
//
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int aaaaaa = k;
    map<int, bool> a;
    int ans[n];
    int ptr = 0;
    if (n == 1 && k == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (n / 2 > k || n == 1) {
        cout << -1 << endl;
        return 0;
    }
    int pairs = n / 2;
    k -= pairs;
    k++;
    a[k] = true;
    a[k * 2] = true;
    ans[ptr] = k;
    ans[ptr + 1] = k * 2;
    ptr += 2;
    int prints = 0;
    for (int i = 1; prints < pairs - 1; i++) {
        if (!a[i] && !a[i + 1]) {
            ans[ptr] = i;
            ans[ptr + 1] = i + 1;
            a[i] = true;
            a[i + 1] = true;
            ptr += 2;
            prints++;
        }
    }
    if (n % 2 == 1) {
        ans[ptr] = 87654321;
    }
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}