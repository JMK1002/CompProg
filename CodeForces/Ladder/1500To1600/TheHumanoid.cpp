//
// Created by JMKov on 6/17/2023.
//
#include <iostream>
#include <algorithm>
using namespace std;

int sim (int ans, int n, long long h, int blue, int green, const int arr[]) {
    while (ans < n) {
        if (h > arr[ans]) {
            h += arr[ans] / 2;
            ans++;
        }
        else {
            int v = ans;
            if (h * 2 > arr[ans] && green > 0) {
                v = max(v, sim(ans, n, h * 2, blue, green - 1, arr));
            }
            if (h * 3 > arr[ans] && blue > 0) {
//                cout << sim(ans, n, h * 3, blue - 1, green, arr) << "SDF" << endl;
                v = max(v, sim(ans, n, h * 3, blue - 1, green, arr));
            }
            if (h * 4 > arr[ans] && green > 1) {
                v = max(v, sim(ans, n, h * 4, blue, green - 2, arr));
            }
            if (h * 6 > arr[ans] && green > 0 && blue > 0) {
                v = max(v, sim(ans, n, h * 6, blue - 1, green - 1, arr));
            }
            if (h * 12 > arr[ans] && green > 1 && blue > 0) {
                v = max(v, sim(ans, n, h * 12, blue - 1, green - 2, arr));
            }
            ans = v;
            break;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long h;
        cin >> n >> h;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        int blue = 1;
        int green = 2;
        sort(arr, arr + n);
        cout << sim(0, n, h, 1, 2, arr) << endl;
    }
    return 0;
}
