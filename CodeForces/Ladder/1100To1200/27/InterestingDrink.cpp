#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binSearch(int target, vector<int> prices, int min, int max);

int main() {
    int n, q;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    cin >> q;
    sort(prices.begin(), prices.end());
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        int low = 0;
        int high = n - 1;
        int m = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (prices[mid] <= a) {
                m = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        cout << m + 1 << endl;
    }
    return 0;
}