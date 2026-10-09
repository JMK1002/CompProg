#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int arr[5002];
int p[5002];

int main() {
    int n, x;
    cin >> n >> x;
    iota(p, p + n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(p, p + n, [&] (int a, int b) {
        return arr[a] < arr[b];
    });
    sort(arr, arr + n);
    if (n < 3) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int p1 = i + 1;
        int p2 = n - 1;
        int s = arr[p1] + arr[p2] + arr[i];
        while (p1 < p2) {
            if (s == x) {
                cout << p[i] + 1 << " " << p[p1] + 1 << " " << p[p2] + 1 << endl;
                return 0;
            }
            if (s < x) {
                s -= arr[p1];
                p1++;
                s += arr[p1];
            }
            else if (s > x) {
                s -= arr[p2];
                p2--;
                s += arr[p2];
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}