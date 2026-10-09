#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> in(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    sort(in.begin(), in.end());
    if (in[n - 3] + in[n - 2] <= in[n - 1]) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = n - 1; i >= 1; i--) {
        if (in[0] + in[n - 2] <= in[n - 1]) {
            for (int j = 0; j < n - i; j++) {
                int a = in[i + j - 1];
                in[i + j - 1] = in[i + j];
                in[i + j] = a;
            }
        }
    }
    // bool go = in[0] + in[n - 2] <= in[n - 1];
    // while (go) {
    //     for (int i = 0; i < n - 3; i++) {
    //         if (in[i] + in[(i + 2) % n] > in[n - 1]) {
    //             int a = in[(i + 1) % n];
    //             in[(i + 1) % n] = in[n - 1];
    //             in[n - 1] = a;
    //             go = in[0] + in[n - 2] <= in[n - 1];
    //             break;
    //         }
    //     }
    //     if (in[n - 3] + in[n - 2] > in[n - 1]) {
    //         int a = in[n - 2];
    //         in[n - 2] = in[n - 1];
    //         in[n - 1] = a;
    //         go = in[0] + in[n - 2] <= in[n - 1];
    //     }
    // }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << in[i] << " ";
    }
    return 0;
}