#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    int negCount = 0;
    vector<int> stuf(0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 0) {
            negCount++;
        }
        if (negCount == 3) {
            negCount = 1;
            stuf.insert(stuf.end(), count);
            count = 0;
        }
        count++;
    }
    cout << stuf.size() + (bool) (count) << endl;
    for (int i : stuf) {
        cout << i << " ";
    }
    if (count != 0) {
        cout << count << endl;
    }

    // int group = max(1, (negatives + 1) / 2);
    // cout << group << endl;
    // cout << n - (3 * (group - 1)) << endl;
    // negatives -= 2;
    // while (negatives > 0) {
    //     cout << ((negatives == 1) ? 1 : 3) << endl;
    //     negatives -= 2;
    // }
}