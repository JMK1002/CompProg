#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> sortedList(n);
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        sortedList[i] = a - 'a';
    }
    sort(sortedList.begin(), sortedList.end());
    int a = 0;
    for (int i = 1; i < n - a; i++) {
        if (sortedList[i - 1] >= sortedList[i] - 1) {
            sortedList.erase(sortedList.begin() + i);
            a++;
            i--;
        }
    }
    if (sortedList.size() < k) {
        cout << -1 << endl;
    }
    else {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += sortedList[i] + 1;
        }
        cout << sum << endl;
    }
    return 0;
}