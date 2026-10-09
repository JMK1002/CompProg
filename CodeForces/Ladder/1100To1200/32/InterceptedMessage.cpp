#include <iostream>
using namespace std;

bool binSearch(int index, int p1[], int min, int max) {
    if (max >= min) {
        int mid = (min + max) / 2;
        if (p1[mid] == index) {
            return true;
        }
        else if (p1[mid] < index) {
            return binSearch(index, p1, mid + 1, max);
        }
        else {
            return binSearch(index, p1, min, mid - 1);
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    int b1[n];
    int b2[m];
    int p[n];
    int last = -1;
    int ans = 0;
    cin >> b1[0];
    p[0] = b1[0];
    for (int i = 1; i < n; i++) {
        cin >> b1[i];
        p[i] = p[i - 1] + b1[i];
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> b2[i];
        sum += b2[i];
        if (binSearch(sum, p, 0, n - 1)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}