#include <string>
#include <map>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> a;
    int ret = 0;

    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        if (b) {
            a[b]++;
            if (a[b] == 2) {
                ret++;
            }
            else if (a[b] > 2) {
                ret = -1;
                break;
            }
        }
    }
    cout << ret << endl;
}