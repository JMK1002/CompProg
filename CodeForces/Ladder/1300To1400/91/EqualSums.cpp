//
// Created by JMKov on 5/2/2023.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, map<int, int>> sums;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int sum = 0;
        int arr[a];
        for (int j = 0; j < a; j++) {
            cin >> arr[j];
            sum += arr[j];
        }
        for (int j = 0; j < a; j++) {
            int index = sum - arr[j];
            sums[index][i] = j;
            if (sums[index].size() > 1) {
                cout << "YES" << endl;
                for (auto p : sums[index]) {
//                    cout << sum << " " << arr[j] << endl;
                    cout << p.first + 1 << " " << p.second + 1 << endl;
                }
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}