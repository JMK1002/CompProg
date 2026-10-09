    #include <bits/stdc++.h>
    #define ll long long
     
    using namespace std;
     
    void brute(ll l, ll r, vector<ll> & c, vector<ll> & lowerprimes, vector<ll> & upperprimes, ll o) {
        c[r - l]++;
     
        ll pl = lowerprimes[(l + r) / 2 - o] + o;
        if (pl > l)
            brute(pl, r, c, lowerprimes, upperprimes, o);
     
        ll pr = upperprimes[(l + r + 1) / 2 - o] + o;
        if (pr < r)
            brute(l, pr, c, lowerprimes, upperprimes, o);
    }
     
    int main() {
        int T;
        cin >> T;
     
        while (T--) {
            ll l, r;
            cin >> l >> r;
     
            l *= 2;
            r *= 2;
     
            vector<bool> prime(r - l + 1, true);
            for (ll i = 2; i * i <= r; i++)
            {
                for (ll j = (l + i - 1) / i * i; j <= r; j += i)
                {
                    if (j > i)
                        prime[j - l] = false;
                }
            }
            
            vector<ll> lowerprimes(r - l + 1), upperprimes(r - l + 1);
            lowerprimes[0] = 0;
            for (int i = 1; i <= r - l; i++)
                lowerprimes[i] = prime[i] ? i : lowerprimes[i - 1];
            upperprimes[r - l] = r - l;
            for (int i = r - l - 1; i >= 0; i--)
                upperprimes[i] = prime[i] ? i : upperprimes[i + 1];
            
            vector<ll> c(r - l + 1);
     
            brute(l, r, c, lowerprimes, upperprimes, l);
     
            for (ll i: c)
            {
                if (i) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }