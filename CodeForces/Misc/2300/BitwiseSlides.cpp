#include <iostream>
#include <map>
using namespace std;

const long long mod = 1e9+7;

long long n;
map<long long, long long> run;

int main() {
	long long t;
	cin >> t;
	while (t--) {
		cin >> n;
		run[0] = 1;
		long long zero = 0;
		for (long long i = 0; i < n; i++) {
			long long x;
			cin >> x;
			// map<long long, long long> temp;
			
			// for (pair<long long, long long> p : run) {
			// 	temp[x ^ p.first] += p.second * (p.first == 0 ? 3 : 1);
			// }
			// temp[x] += run[x] * 2;
			// run = temp;

			// zero ^= x;

			run[zero] = (run[x ^ zero] * 2 + run[zero] * 3) % mod;
			run[zero] %= mod;
			zero ^= x;

			// ! for every single thing, we just xor all p.first
			// ! if p.first == zero then xor it AND multiply it by 3
			// ? if p.first ^ zero == x then keep it the same and multiply by 2

			// ! for every single thing, we just keep all p.first same
			// ! if p.first == zero then multiply it by 3
			// ? if p.first ^ zero == x then xor it and multiply by 2

			// for (pair<long long, long long> p : run) cout << (p.first ^ zero) << " " << p.second << endl;
			// cout << zero << endl;
			// cout << endl;
		}
		long long ans = 0;
		for (pair<long long, long long> p : run) ans += p.second;
		cout << (ans%mod) << endl;
		run.clear();
	}
	return 0;
}
// 1 2 3 3 2
// 0 1
//
// 1 1
//
// 3 1
// 
// 0 1, 3 2
// 3 7, 0 3
// 