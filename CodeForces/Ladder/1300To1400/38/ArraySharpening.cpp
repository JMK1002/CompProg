//
// Created by JMKov on 4/14/2023.
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        bool a = true;
        int inflection = -1000000000;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            int prevInflection = inflection;
            if (inflection == -1000000000) {
                if (arr[i] < i) {
                    inflection = arr[i - 1];
//                    cout << inflection << " " << arr[i] << endl;
                }
            }
            if (inflection != -1000000000) {
                inflection = min(inflection - 1, arr[i]);
//                cout << inflection << endl;
                if (prevInflection == inflection) {
                    a = false;
                }
            }
        }
        if (inflection < 0 && inflection != -1000000000) {
            a = false;
        }
        cout << (a ? "YES" : "NO") << endl;
    }
    return 0;
}