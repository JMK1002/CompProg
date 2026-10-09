#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAXN 300010
const ll MOD = 1e9+7;

ll min1[MAXN],max1[MAXN],min2[MAXN],max2[MAXN];
vector<int> adj[20000];
ll n,m,k;


void solve()
{
    cin >> n;
    string s;
    cin >> s;

    ll sum1 = 0;
    ll left1 = 0;
    for (int i = 0; i < n/2; i++) {
        if (s[i] == '?') {
            left1++;
        } else {
            sum1 += s[i] - '0';
        }
    }

    ll sum2 = 0;
    ll left2 = 0;
    for (int i = n/2; i < n; i++) {
        if (s[i] == '?') {
            left2++;
        } else {
            sum2 += s[i] - '0';
        }
    }

    //cout << left1 << " " << sum1 << " " << left2 << " " << sum2 << endl;

    for (ll i = 0; i <= left1; i++) {
        min1[i] = sum1 + (left1-i)*9;
        max1[i] = sum1 + i * 9;
    }
    for (ll i = 0; i <= left2; i++) {
        min2[i] = sum2 + (left2-i)*9;
        max2[i] = sum2 + i * 9;
    }

    bool works = false;

    if (left1 % 2 == 0) {
        ll take1 = left1/2;
        ll take2 = left2/2;
        if (min1[take1] < max2[take2] || min2[take2] < max1[take1]) {
            cout << "Monocarp" << endl;
        } else {
            cout << "Bicarp" << endl;
        }
    } else {
        ll take1 = left1/2;
        ll take2 = left2/2 + 1;
        if (min1[take1] < max2[take2] || min2[take2] < max1[take1]) {
            //cout << min1[take1] << " " << max2[take2] << " " << min2[take2] << " " << max1[take1] << endl;
            cout << "Monocarp" << endl;

            return;
        }
        take1 = left1/2 + 1;
        take2 = left2/2;
        if (min1[take1] < max2[take2] || min2[take2] < max1[take1]) {
            cout << "Monocarp" << endl;
        } else {
            cout << "Bicarp" << endl;
        }
    }








}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t = 1;
    while (t--) {
        solve();
    }
    return EXIT_SUCCESS;
}

