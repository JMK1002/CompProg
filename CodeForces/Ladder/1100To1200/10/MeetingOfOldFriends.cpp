#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    vector<long long> times(4, 0);
    vector<long long> sorted;
    long long k;
    long long mx = -1;
    long long mn = 1000000000000000001;
    for (int i = 0; i < 4; i++) {
        cin >> times[i];
        mx = max(times[i], mx);
        mn = min(times[i], mn);
    }
    sorted = times;
    sort(sorted.begin(), sorted.end());
    cin >> k;
    long long a = 0;
    cout << max(times[1] - times[0] + times[3] - times[2] + 2 - sorted[3] + sorted[0] - 1 - (k >= sorted[1] && k <= sorted[2]), a) << endl;
    return 0;
}