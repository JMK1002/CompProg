//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    istream::sync_with_stdio(0);
    cout.tie();
    int n;
    cin >> n;
    n--;
    vector<pair<int, int>> ans{{1, 3}};
    while (n--) {
        vector<pair<int, int>> nAns(ans.size() * 2 + 1);
        int cnt = 0;
        for (pair<int, int> p : ans) {
            pair<int, int> np = p;
            if (np.first == 2) np.first = 3;
            else if (np.first == 3) np.first = 2;
            if (np.second == 2) np.second = 3;
            else if (np.second == 3) np.second = 2;
            nAns[cnt] = np;
            cnt++;
        }
        nAns[cnt] = {1, 3};
        cnt++;
        for (pair<int, int> p : ans) {
            pair<int, int> np = p;
            if (np.first == 1) np.first = 2;
            else if (np.first == 2) np.first = 1;
            if (np.second == 1) np.second = 2;
            else if (np.second == 2) np.second = 1;
            nAns[cnt] = np;
            cnt++;
        }
        ans = nAns;
    }
    cout << ans.size() << endl;
    for (pair<int, int> p : ans) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}