#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }
    vector<int> sortedTimes = times;
    sort(sortedTimes.begin(), sortedTimes.end());
    int sum = 0;
    int index = n;
    for (int i = 0; i < n; i++) {
        sum += sortedTimes[i];
        if (sum > k) {
            index = i;
            break;
        }
    }
    cout << index << endl;
    for (int i = 0; i < index; i++) {
        for (int j = 0; j < n; j++) {
            if (sortedTimes[i] == times[j]) {
                cout << j + 1 << " ";
                times[j] = -1;
                break;
            }
        }
    }
    return 0;
}