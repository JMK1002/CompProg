#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool dropped[n] = { false };
    int onTop = -1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        dropped[n - a] = true;
        while (dropped[onTop + 1] && onTop < n - 1) {
            cout << n - onTop - 1 << " ";
            onTop++;
        }
        cout << endl;
    }
    return 0;
}