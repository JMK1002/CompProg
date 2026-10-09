#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n, n2, k;
    cin >> n >> k;
    n2 = k;
    int sum = 0;
    int given = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        sum += c;
        given += min(8, sum);
        sum -= min(8, sum);
        if (given >= k) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}