#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int bidder = 0;
    int max1 = -1;
    int max2 = -2;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > max1) {
            max2 = max1;
            max1 = a;
            bidder = i;
        }
        else if (a > max2) {
            max2 = a;
        }
    }

    cout << (bidder + 1) << " " << max2 << endl;
}