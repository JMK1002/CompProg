#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int k;
    cin >> k;
    vector<int> array(12, 0);
    int sum = 0;
    int ret = 12;
    for (int i = 0; i < 12; i++) {
        cin >> array[i];
        sum += array[i];
    }
    if (sum < k) {
        cout << -1 << endl;
        return 0;
    }

    sort(array.begin(), array.end());

    for (int i = 0; i < 12; i++) {
        sum -= array[i];
        if (sum >= k) {
            ret--;
        }
        else {
            break;
        }
    }
    cout << ret << endl;
    return 0;
}