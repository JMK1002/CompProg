#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, min = INT32_MAX, max = -1;
    cin >> n;
    int ret = 0;
    while (n--) {
        int v;
        cin >> v;
        if (v > max && v < min) {
            ret--;
        }
        if (v < min) {
            min = v;
            ret++;
        }
        if (v > max) {
            max = v;
            ret++;
        }
    }
    ret--; // starting case
    cout << ret << endl;
}