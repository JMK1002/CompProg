//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x, y, z) for(int x = (y); x <= (z); ++x)
#define per(x, y, z) for(int x = (y); x >= (z); --x)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do {freopen(s".in", "r", stdin); freopen(s".out", "w", stdout);} while(false)
#define endl '\n'
using namespace std;
typedef long long ll;

mt19937 rnd(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
int randint(int L, int R) {
    uniform_int_distribution<int> dist(L, R);
    return dist(rnd);
}

template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

template<int mod>
inline unsigned int down(unsigned int x) {
    return x >= mod ? x - mod : x;
}

template<int mod>
struct Modint {
    unsigned int x;
    Modint() = default;
    Modint(unsigned int x) : x(x) {}
    friend istream& operator>>(istream& in, Modint& a) {return in >> a.x;}
    friend ostream& operator<<(ostream& out, Modint a) {return out << a.x;}
    friend Modint operator+(Modint a, Modint b) {return down<mod>(a.x + b.x);}
    friend Modint operator-(Modint a, Modint b) {return down<mod>(a.x - b.x + mod);}
    friend Modint operator*(Modint a, Modint b) {return 1ULL * a.x * b.x % mod;}
    friend Modint operator/(Modint a, Modint b) {return a * ~b;}
    friend Modint operator^(Modint a, int b) {Modint ans = 1; for(; b; b >>= 1, a *= a) if(b & 1) ans *= a; return ans;}
    friend Modint operator~(Modint a) {return a ^ (mod - 2);}
    friend Modint operator-(Modint a) {return down<mod>(mod - a.x);}
    friend Modint& operator+=(Modint& a, Modint b) {return a = a + b;}
    friend Modint& operator-=(Modint& a, Modint b) {return a = a - b;}
    friend Modint& operator*=(Modint& a, Modint b) {return a = a * b;}
    friend Modint& operator/=(Modint& a, Modint b) {return a = a / b;}
    friend Modint& operator^=(Modint& a, int b) {return a = a ^ b;}
    friend Modint& operator++(Modint& a) {return a += 1;}
    friend Modint operator++(Modint& a, int) {Modint x = a; a += 1; return x;}
    friend Modint& operator--(Modint& a) {return a -= 1;}
    friend Modint operator--(Modint& a, int) {Modint x = a; a -= 1; return x;}
    friend bool operator==(Modint a, Modint b) {return a.x == b.x;}
    friend bool operator!=(Modint a, Modint b) {return !(a == b);}
};

const int N = 1e6 + 100, mod = 998244353;
typedef Modint<mod> mint;

int T, n, k;
mint a[N], inv[N];

inline int lowbit(int x) {return x & -x;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    inv[0] = inv[1] = 1;
    rep(i, 2, N - 1) inv[i] = (mod - mod / i) * inv[mod % i];
    for(cin >> T; T; --T) {
        cin >> n >> k;
        rep(i, 1, n) cin >> a[i];
        rep(i, 1, n) {
            mint mul = 1;
            for(int u = i + lowbit(i), d = 1; u <= n; u += lowbit(u), ++d) {
                mul *= (d + k - 1) * inv[d];
                a[u] -= mul * a[i];
            }
        }
        rep(i, 1, n) cout << a[i] << " \n"[i == n];
    }
    return 0;
}