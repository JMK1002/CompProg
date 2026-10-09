#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int clock = 0;
    int ret = 0;
    int prevRet = ret;
    while (true) {
        ret += n - n % m;
        n = n % m + n / m;
        if (prevRet == ret) {
            ret += n;
            break;
        }
        prevRet = ret;
    }
    cout << ret << endl;
    return 0;
}