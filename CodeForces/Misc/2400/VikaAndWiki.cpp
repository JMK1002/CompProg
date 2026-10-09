#include <iostream>
using namespace std;

int n;
int arr[2000000];
int temp[2000000];
int kth[2000000];

void doKOperations(int k) {
	for (int i = 0; i < n; i++) {
		kth[i] = arr[i];
	}
	int run = 1;
	while (k) {
		if (k & 1) {
			for (int i = 0; i < n; i++) temp[i] = kth[i];
			for (int i = 0; i < n; i++) {
				kth[i] = temp[i] ^ temp[(i + run) % n];
			}
		}
		run <<= 1;
		k >>= 1;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int low = -1;
	int high = n + 1;
	while (high - low > 1) {
		int mid = (low + high) / 2;
		doKOperations(mid);
		bool worked = true;
		for (int i = 0; i < n; i++) worked &= (kth[i] == 0);
		if (worked) high = mid;
		else low = mid;
	}
	cout << low + 1 << endl;
	return 0;
}

// 0000 0
// 0001 0 1
// 0010 0 2
// 0011 0 1 2 3
// 0100 0 4
// 0101 0 1 4 5
// 0110 0 2 4 6
// 0111 0 1 2 3 4 5 6 7
// 1000 0 8