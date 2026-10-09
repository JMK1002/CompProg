#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ret = 0;
    int lastH = -1;
    int lastM = -1;
    int cashesNeeded = 0;
    while (n--) {
        int h, m;
        cin >> h >> m;
        if (lastH == h && lastM == m) {
            cashesNeeded++;
            ret = max(ret, cashesNeeded);
        }
        else {
            cashesNeeded = 0;
            lastH = h;
            lastM = m;
        }
    }
    cout << ret + 1 << endl;
    return 0;
}