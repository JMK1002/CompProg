#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n, in, i1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            i1 = i;
        }
        else if (a == n) {
            in = i;
        }
    }

    cout << max(max(max((n - 1) - in, in), (n - 1) - i1), i1) << endl;
}