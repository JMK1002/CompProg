#include <iostream>
#include <set>
using namespace std;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    set<int> asdf;
    for (int i = 0; i < 125; i++) asdf.insert(binpow(i, 100, 125));
    cout << asdf.size() << endl;
    for (int i : asdf) cout << i << endl;
    cout << binpow(5, 100, 125) << endl;
    return 0;
}