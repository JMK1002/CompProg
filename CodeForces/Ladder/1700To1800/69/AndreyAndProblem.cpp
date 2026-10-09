//
// Created by JMKov on 7/4/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double calcProb(vector<double> arr) {
    int n = arr.size();
    double mult = 1;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        mult *= (1 - arr[i]);
    }
    for (int i = 0; i < n; i++) {
        ans += mult / (1 - arr[i]) * arr[i];
    }
    return ans;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cout.precision(15);
    int n;
    cin >> n;
    double arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    if (arr[n - 1] == 1) {
        cout << 1 << endl;
        return 0;
    }
    double ans = 0;
    vector<double> asdf;
    for (int i = n - 1; i >= 0; i--) {
        asdf.push_back(arr[i]);
        ans = max(ans, calcProb(asdf));
    }
    cout << ans << endl;
}