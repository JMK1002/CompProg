//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
#include <numeric>

using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n * (n + 1) / 2 % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    long long tar = n * (n + 1) / 4;
    long long amnt = 0;
    for (long long i = 1; i <= n; i++) {
        if (i * (i + 1) / 2 + (i + 1) >= tar) {
            amnt = i;
            break;
        }
    }
    long long wig = n - amnt;
    long long sum = amnt * (amnt + 1) / 2;
    long long cnt = (tar - sum) / wig;
    long long m = (tar - sum) % wig;
    bool explored[n];
    for (long long i = 0; i < n; i++) explored[i] = false;

    cout << amnt << endl;
    for (long long i = 0; i < cnt; i++) {
        cout << n - i << " ";
        explored[n - i - 1] = true;
    }
    if (amnt - cnt + m != 0) {
        cout << amnt - cnt + m << " ";
        explored[amnt - cnt + m - 1] = true;
    }
    for (long long i = 0; i < amnt - cnt - 1; i++) {
        cout << i + 1 << " ";
        explored[i] = true;
    }
    cout << endl;
    cout << n - amnt << endl;
    for (long long i = 0; i < n; i++) {
        if (explored[i]) continue;
        cout << i + 1 << " ";
    }

    return 0;
}