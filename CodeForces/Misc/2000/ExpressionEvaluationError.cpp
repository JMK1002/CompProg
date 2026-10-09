//
// Created by JMKov on 6/17/2024.
//
#include <iostream>
#include <cmath>

using namespace std;

long long cnt[12];

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long s, n;
        cin >> s >> n;
        long long cs = s;
        long long ind = 0;
        long long dgSum = 0;
        while (cs) {
            cnt[ind] = cs % 10;
            dgSum += cs % 10;
            cs /= 10;
            ind++;
        }
        if (dgSum < n) {
            while (dgSum < n) {
                long long pos = 1;
                while (cnt[pos] == 0) {
                    pos++;
                }
                cnt[pos]--;
                cnt[pos - 1] += 10;
                dgSum += 9;
            }
        }

        long long inc = 0;
        long long asdf = 0;
        for (long long i = 0; i < 12 && inc < n - 1; i++) {
            for (long long j = 0; j < cnt[i] && inc < n - 1; j++) {
                asdf += (long long) pow(10, i);
                cout << (long long) pow(10, i) << " ";
                inc++;
            }
        }
        cout << s - asdf << endl;
        for (long long i = 0; i < 12; i++) cnt[i] = 0;
    }

    return 0;
}