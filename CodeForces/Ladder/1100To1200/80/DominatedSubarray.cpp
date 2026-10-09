//
// Created by JMKov on 4/1/2023.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int t = 0;
        cin >> n;
        int a[n];
        map<int, int> inVector;
        vector<int> position(0);
        vector<int> count(0);
        int ans = 1000000000;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (inVector[a[i]] == 0) {
                position.insert(position.end(), a[i]);
                count.insert(count.end(), t);
                inVector[a[i]] = position.size();
            }
            else {
                int val = count[inVector[a[i]] - 1];
                ans = min(ans, t - val);
                count[inVector[a[i]] - 1] = t;
            }
            t++;
        }
        if (ans == 1000000000) {
            ans = -2;
        }
        cout << ans + 1 << endl;
    }
    return 0;
}