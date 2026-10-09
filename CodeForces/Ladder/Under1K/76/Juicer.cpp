#include <iostream>
using namespace std;

int main() {
    int n, b, d;
    cin >> n >> b >> d;
    int sum = 0;
    int ret = 0;
    while (n--) {
        int a;
        cin >> a;
        if (a > b) {
            continue;
        }
        sum += a;
        if (sum > d) {
            sum = 0;
            ret++;
        }
    }
    cout << ret << endl;
    return 0;
}