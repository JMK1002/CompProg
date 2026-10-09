//
// Created by JMKov on 4/19/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n];
    int lrd[m][3];
    long long pre[n + 1];
    long long multiPre[m + 1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pre[i] = 0;
    }
    pre[n] = 0;
    for (int i = 0; i < m; i++) {
        cin >> lrd[i][0] >> lrd[i][1] >> lrd[i][2];
    }
    for (int i = 0; i < m + 1; i++) {
        multiPre[i] = 0;
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        multiPre[x - 1]++;
        multiPre[y]--;
    }
    long long count = 0;
    for (int i = 0; i < m; i++) {
        count += multiPre[i];
        int l = lrd[i][0];
        int r = lrd[i][1];
        long long d = (long long) lrd[i][2] * count;
        pre[l - 1] += d;
        pre[r] -= d;
    }
    count = 0;
    for (int i = 0; i < n; i++) {
        count += pre[i];
        cout << arr[i] + count << " ";
    }


    return 0;
}
//1 1 1
//3
//1 1 2
//1 1