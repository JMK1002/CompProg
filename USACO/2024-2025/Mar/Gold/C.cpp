#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long mod = 1e9+7;

long long n, d, a, b, l, r, k;
long long ans = 0;
long long arr[100005];

void updateBounds() {
	while (r < n - 1 && arr[r + 1] <= arr[l] + 1) r++;
	while (l > 0 && arr[l - 1] == arr[l]) l--;
}

bool doCycles(long long amnt) {
	long long repeats = (r - l + 1) / __gcd(r - l + 1, k - l);
	long long incAmnt = (k - l) / __gcd(r - l + 1, k - l);

	if (!((l == 0 || arr[l - 1] + amnt / repeats * repeats <= arr[l] + incAmnt * (amnt / repeats)) && (r == n - 1 || arr[r] + incAmnt * (amnt / repeats) <= arr[r + 1]))) {
		doCycles(amnt / 2);
		doCycles(amnt - amnt / 2);
		return false;
	}

	vector<long long> cpy;
	for (long long i = 0; i < n; i++) cpy.push_back(arr[i]);

	for (long long i = 0; i < l; i++) {
		arr[i] += (amnt / repeats * repeats);
	}

	for (long long i = l; i <= r; i++) {
		arr[i] += incAmnt * (amnt / repeats);
	} 

	for (long long i = 0; i < amnt % repeats; i++) {
		for (long long j = 0; j < k; j++) {
			arr[j]++;
		}
		sort(arr, arr + n);
	}
	updateBounds();
	return true;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> d >> a >> b;
	k = a - b;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	for (long long i = 0; i < n - a; i++) {
		ans += arr[i] * arr[i] % mod;
		ans %= mod;
	}
	reverse(arr, arr + n);
	n = a;
	sort(arr, arr + n);

	l = k - 1;
	r = k - 1;
	updateBounds();
	// cout << l << " " << r << endl;

	// while (d) {
	// 	for (long long i = 29, j = (1 << i); i >= 0; i--, j >>= 1) {
	// 		if (j > d) continue;
	// 		if (doCycles(j)) {
	// 			d -= j;
	// 			break;
	// 		}
	// 	}
	// }

	doCycles(d);

	for (long long i = 0; i < n; i++) {
		arr[i] %= mod;
		ans += arr[i] * arr[i] % mod;
		ans %= mod;
	}
	cout << ans % mod << endl;
	return 0;
}

// 8 0
// 4 0
// 1 2 1 2 1 0 0 1