//
// Created by JMKov on 5/12/2024.
//
#include <iostream>
using namespace std;

const long long MAXN = 102;
const long long mod = 1000000007;

long long n, m;

struct matrix {
    long long mtrx[MAXN][MAXN] = {0};
    matrix operator * (matrix a) {
        matrix b;
        for (long long i = 0; i < m; i++) {
            for (long long j = 0; j < m; j++) {
                for (long long k = 0; k < m; k++) {
                    b.mtrx[i][j] += (mtrx[i][k] * a.mtrx[k][j]) % mod;
                    b.mtrx[i][j] %= mod;
                }
            }
        }
        return b;
    };

    void print() {
        for (long long i = 0; i < m; i++) {
            for (long long j = 0; j < m; j++) {
                cout << mtrx[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cin >> m >> n;
    pair<long long, long long> arr[m];
    for (long long i = 0; i < m; i++) cin >> arr[i].first;
    for (long long i = 0; i < m; i++) cin >> arr[i].second;
    matrix ans;
    matrix run;
    for (long long i = 0; i < m; i++) ans.mtrx[i][i] = 1;
    for (long long i = 0; i < m; i++) for (long long j = 0; j < m; j++) {
        run.mtrx[i][j] = (arr[i].first + arr[i].second) * (arr[j].first + arr[j].second) - arr[i].second * arr[j].second;
        run.mtrx[i][j] %= mod;
    }

    while (n != 0) {
        if (n & 1) {
            ans = ans * run;
        }
        run = run * run;
        n >>= 1;
    }

    long long ret = 0;
    for (long long j = 0; j < m; j++) ret += ans.mtrx[0][j];
    ret %= mod;
    cout << ret << endl;
    return 0;
}