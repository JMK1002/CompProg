#include <iostream>
using namespace std;

int main() {
    int n;
    int ret = 0;
    cin >> n;
    while (n--) {
        int l = 0;
        for (int i = 0; i < 3; i++) {
            int a = 0;
            cin >> a;
            l += a;
        }
        ret += (l >= 2);
    }
    cout << ret << endl;
}