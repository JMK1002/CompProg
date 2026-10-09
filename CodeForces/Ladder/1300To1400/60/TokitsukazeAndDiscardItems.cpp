//
// Created by JMKov on 4/21/2023.
//
#include <iostream>
using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    long long arr[m];
    long long ans = 0;
    long long amntRemoved = 0;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    while (amntRemoved < m) {
        int count = 1;
        while (amntRemoved + count < m && arr[amntRemoved + count] - arr[amntRemoved + count - 1] < k && max(((arr[amntRemoved + count - 1] - amntRemoved) % k == 0) * (long long) k, (arr[amntRemoved + count - 1] - amntRemoved) % k) < max(((arr[amntRemoved + count] - amntRemoved) % k == 0) * (long long) k, (arr[amntRemoved + count] - amntRemoved) % k)) { // prob a + 1 will result in err
            count++;
        }
        amntRemoved += count;
//        cout << amntRemoved << endl;
        ans++;
    }
    cout << ans << endl;
    return 0;
}