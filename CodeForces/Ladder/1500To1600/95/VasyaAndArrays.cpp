//
// Created by JMKov on 6/5/2023.
//
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    long long n, m;
    cin >> n;
    auto *a = new long long[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    auto *b = new long long[m];
    for (long long i = 0; i < m; i++) cin >> b[i];

    long long sa = 0;
    long long sb = 0;
    long long pa = 0;
    long long pb = 0;
    long long ans = 0;
    while (pa < n || pb < m)
    {
        if (pa >= n)
        {
            sb += b[pb];
            pb++;
        }
        else if (pb >= m)
        {
            sa += a[pa];
            pa++;
        }
        else if (sa >= sb)
        {
            sb += b[pb];
            pb++;
        }
        else {
            sa += a[pa];
            pa++;
        }
        if (sa == sb) {
            ans++;
        }
    }
    if (sa != sb) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}