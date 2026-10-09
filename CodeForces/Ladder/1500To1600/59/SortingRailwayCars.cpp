//
// Created by JMKov on 5/23/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int indices[n];
    int asdf[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
        indices[arr[i]] = i;
        asdf[i] = 1;
    }
    asdf[n - 1] = 1;
    int mx = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (indices[i + 1] > indices[i]) {
            asdf[i] = asdf[i + 1] + 1;
            mx = max(asdf[i], mx);
        }
    }
//    for (int i : asdf) cout << i << " ";
//    cout << endl;
    cout << n - mx << endl;
    return 0;
}