#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    long long sum = 0;
    cin >> n;
    vector<long long> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
        sum += prices[i];
    }
    sort(prices.begin(), prices.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        cout << sum - prices[n - q] << endl;
    }
    return 0;
}