#include <iostream>
#include <vector>
using namespace std;

long long n;
long long arr[200005];
vector<long long> ind[200005];
long long ans[200005];
vector<long long> curr;

int getCnt(int x) {
    long long pos = 0;
    long long cnt = 0;
    
    while (pos < curr.size()) {
        cnt++;
        long long low = pos;
        long long high = curr.size();
        while (high - low > 1) {
            long long mid = (low + high) / 2;
            if (mid == curr.size() || curr[mid] - curr[pos] > x) {
                high = mid;
            }
            else {
                low = mid;
            }
        }
        pos = high;
    }
    return cnt;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    // ! have ind[i] be a set with positions of all j such taht a_j = i
    // ! binary search

    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        // arr[i] = 1;
        ind[arr[i]].push_back(i);
    }
    for (long long i = 1; i <= n; i++) {
        curr = ind[i];
        if (curr.empty()) continue;

        long long x = 1;
        
        while (x < n + 1) {
            int comp = getCnt(x);
            long long low = x;
            long long high = n + 1;
            while (high - low > 1) {
                long long mid = (low + high) / 2;
                if (mid == n + 1 || getCnt(mid) < comp) {
                    high = mid;
                }
                else {
                    low = mid;
                }
            }
            for (int i = x; i < high; i++) ans[i] += comp;
            x = high;
        }

        // for (long long x = 1; x <= n; x++) {
        //     ans[x] += getCnt(curr, x);
        // }
    }
    for (long long i = 1; i <= n; i++) cout << ans[i] << endl;

    return 0;
}