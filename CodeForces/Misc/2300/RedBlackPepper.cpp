#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

long long n;
pair<long long, long long> arr[300005];
long long optimal[300005];


long long gcd(long long a, long long b, long long& x, long long& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long x1, y1;
	long long d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

bool find_any_solution(long long a, long long b, long long c, long long &x0, long long &y0, long long &g) {
	g = gcd(abs(a), abs(b), x0, y0);
	if (c % g) {
		return false;
	}
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return true;
}

long long get(pair<long long, long long> val) {
    if (val.first < 0 || val.second < 0 || val.first + val.second != n) return -1;
    else return optimal[val.first];
}

long long inv(long long a, long long m) {
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a, m) % m;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    long long s = 0;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        s += arr[i].second;
    }
    sort(arr, arr + n, [&] (pair<long long, long long> a, pair<long long, long long> b) {
        return a.first - a.second > b.first - b.second;
    });

    optimal[0] = s;
    for (long long i = 1; i <= n; i++) {
        optimal[i] = optimal[i - 1] + arr[i - 1].first - arr[i - 1].second;
    }
    long long crit = 0;
    for (long long i = 0; i < n; i++) if (arr[i].first >= arr[i].second) crit = i;

    long long q;
    cin >> q;
    while (q--) {
        long long a, b;
        cin >> a >> b;
        long long g = __gcd(a, b);
        long long l = a * b / g;
        
        pair<long long, long long> sol = {0, 0};
        bool worked = find_any_solution(a, b, n, sol.first, sol.second, g);
        if (!worked) {
            cout << -1 << endl;
            continue;
        }
        sol = {sol.first * a, sol.second * b};
        if (sol.first < 0) sol = {sol.first + 1000000000000 / l * l, sol.second - 1000000000000 / l * l};
        long long amnt = (sol.first / l);
        sol = {sol.first - amnt * l, sol.second + amnt * l};
        while (sol.first > 0) sol = {sol.first - l, sol.second + l}; // ! uh oh could TLE
        while (sol.first < 0) sol = {sol.first + l, sol.second - l}; // ! uh oh could TLE

        // ! sol x value should be >= 0 and lowest possible value

        amnt = crit / (l) + 2;
        sol = {sol.first + amnt * l, sol.second - amnt * l};
        long long ans = -1;
        for (long long i = 0;  i < 5; i++) {
            ans = max(ans, get(sol));
            sol = {sol.first - l, sol.second + l};
        }
        cout << ans << endl;
    }
    return 0;
}