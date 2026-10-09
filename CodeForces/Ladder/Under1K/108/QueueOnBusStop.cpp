#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        if (sum > m) {
            ret++;
            sum = a;
        }
    }
    cout << ret + 1 << endl;
    return 0;
}