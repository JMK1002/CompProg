#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

long long n;
long long arr[300005];
long long cnt[300005];
long long s[300005];
long long largestPrimeDivisor[300005];
vector<long long> primes;

void sieve() {
    for (long long i = 2; i < 300002; i++) {
        if (largestPrimeDivisor[i] != 0) continue;
        primes.push_back(i);
        for (long long j = i; j < 300002; j += i) largestPrimeDivisor[j] = i;
    }
}

vector<long long> factors(long long v) {
    set<long long> ret;
    while (v != 1) {
        ret.insert(largestPrimeDivisor[v]);
        if (largestPrimeDivisor[v] == 0) break;
        v /= largestPrimeDivisor[v];
    }
    vector<long long> vec;
    for (long long i : ret) vec.push_back(i);
    return vec;
}

int main() {
    sieve();
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    long long ans = 0;
    set<long long> prevDivs;
    for (long long i = 0; i < n; i++) {
        vector<long long> f = factors(arr[i]);
        set<long long> divs;
        long long amnt = 0;
        long long sumOfInds = 0;
        for (long long j = 0; j < (1 << f.size()); j++) {
            long long prod = 1;
            long long run = 1;
            for (long long k = 0; k < f.size(); k++) {
                if (run & j) prod *= f[k];
                run <<= 1;
            }
            divs.insert(prod);
            if (__builtin_popcount(j) % 2 == 0) {
                amnt += cnt[prod];
                sumOfInds += s[prod];
            }
            else {
                amnt -= cnt[prod];
                sumOfInds -= s[prod];
            }
        }
        for (long long j : prevDivs) {
            cnt[j]++;
            s[j] += i;
        }
        prevDivs = divs;
        // cout << amnt << " " << sumOfInds << endl;
        ans += amnt * i - sumOfInds;
        // ! checking that it works (is O(n^2) tho to check)
        // long long asdf = 0;
        // for (long long j = 0; j < i; j++) {
        //     asdf += __gcd(arr[i], arr[j]) == 1;
        // }
        // cout << asdf << " " << amnt << endl;
    }
    cout << ans << endl;
    return 0;
}