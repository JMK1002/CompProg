//
// Created by JMKov on 3/30/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool taken[n + 1];
        for (int i = 0; i <= n; i++) {
            taken[i] = false;
        }
        vector<int> marriages(n);
        for (int i = 0; i < n; i++) {
            marriages[i] = -1;
            int q;
            cin >> q;
            vector<int> kingdoms(q);
            for (int j = 0 ; j < q; j++) {
                cin >> kingdoms[j];
            }
            sort(kingdoms.begin(), kingdoms.end());
            for (int j = 0; j < q; j++) {
                if (!taken[kingdoms[j]]) {
                    taken[kingdoms[j]] = true;
                    marriages[i] = kingdoms[j];
                    break;
                }
            }
        }
        int princess = -1;
        int kingdom = -1;
        bool perfect = true;
        for (int i = 0; i < n; i++) {
            if (marriages[i] == -1) {
                perfect = false;
                princess = i;
                break;
            }
        }
        if (perfect) {
            cout << "OPTIMAL" << endl;
            continue;
        }
        for (int i = 1; i <= n + 1; i++) {
            if (!taken[i]) {
                kingdom = i;
                break;
            }
        }
        cout << "IMPROVE" << endl;
        cout << princess + 1 << " " << kingdom << endl;
    }
    return 0;
}