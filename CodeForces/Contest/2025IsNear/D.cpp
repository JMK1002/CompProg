#include <iostream>
#include <set>
using namespace std;

const long long mod = 998244353;

long long n, q;
long long a[200005];
long long b[200005];
multiset<pair<long long, long long>> vals;
multiset<pair<long long, long long>> rvals;
multiset<long long> msa;
multiset<long long> msb;

long long inv(long long a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void solve() {
    cin >> n >> q;
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < n; i++) cin >> b[i];
    for (long long i = 0; i < n; i++) {
        msa.insert(a[i]);
        msb.insert(b[i]);
    }
    auto p1 = msa.begin();
    auto p2 = msb.begin();
    for (long long i = 0; i < n; i++) {
        long long x = *p1;
        long long y = *p2;
        // ! Double check this works (I think it should)
        vals.insert({x, y});
        rvals.insert({y, x});
        p1++;
        p2++;
    }
    long long ans = 1;
    for (pair<long long, long long> p : vals) {
        ans *= min(p.first, p.second);
        ans %= mod;
    }
    cout << ans << " ";
    while (q--) {
        long long o, x;
        cin >> o >> x;
        x--;
        if (o == 1) {
            // * increase a_x by 1
            pair<long long, long long> curr = *(--vals.upper_bound({a[x], 1000000000000000000}));
            vals.erase(vals.find(curr));
            vals.insert({curr.first + 1, curr.second});
            rvals.erase(rvals.find({curr.second, curr.first}));
            rvals.insert({curr.second, curr.first + 1});
            a[x]++;

            long long prevMult = min(curr.first, curr.second);
            long long currMult = min(curr.first + 1, curr.second);
            if (prevMult != currMult) {
                ans *= inv(prevMult);
                ans %= mod;
                ans *= currMult;
                ans %= mod;
            }
        }
        else {
            // * increase b_x by 1
            pair<long long, long long> curr = *(--rvals.upper_bound({b[x], 1000000000000000000}));
            rvals.erase(rvals.find(curr));
            rvals.insert({curr.first + 1, curr.second});
            vals.erase(vals.find({curr.second, curr.first}));
            vals.insert({curr.second, curr.first + 1});
            b[x]++;

            long long prevMult = min(curr.first, curr.second);
            long long currMult = min(curr.first + 1, curr.second);
            if (prevMult != currMult) {
                ans *= inv(prevMult);
                ans %= mod;
                ans *= currMult;
                ans %= mod;
            }
        }
        cout << ans << " ";
    }
    cout << endl;

    vals.clear();
    rvals.clear();
    msa.clear();
    msb.clear();
    for (int i = 0; i <= n; i++) {
        a[i] = 0;
        b[i] = 0;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}