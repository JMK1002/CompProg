#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 4; i++) {
        int prices[4];
        for (int j = 0; j < 4; j++) {
            cin >> prices[j];
        }
        for (int a = 0; a < 2; a++) {
            for (int b = 2; b < 4; b++) {
                if (prices[a] + prices[b] <= n) {
                    cout << i + 1 << " " << prices[a] << " " << n - prices[a] << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}