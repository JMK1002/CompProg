//
// Created by JMKov on 4/30/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        map<int, int> exists;
        int count = 0;
        int change = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            exists[arr[i]]++;
        }
        for (int i = 0; i < n - 1; i++) {
            change += exists[arr[i]] > 1;
            while (exists[arr[i]] > 1) {
                exists[arr[i]]--;
                arr[i] = arr[i] - arr[i] % 10 + count;
                exists[arr[i]]++;
                count++;
            }
        }

        cout << change << endl;
        for (int i : arr) {
            string s = to_string(i);
            while (s.size() < 4) {
                s.insert(s.begin(),  '0');
            }
            cout << s << endl;
        }
    }
    return 0;
}