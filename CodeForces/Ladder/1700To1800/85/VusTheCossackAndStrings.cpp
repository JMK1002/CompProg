//
// Created by JMKov on 7/10/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int bOnes = 0;
    int pre[a.size() + 1];
    pre[0] = 0;
    for (int i = 0; i < a.size(); i++) {
        pre[i + 1] = pre[i] + (a[i] - '0');
//        cout << pre[i] << " ";
    }
    for (int i = 0; i < b.size(); i++) {
        bOnes += (b[i] - '0');
    }
//    cout << pre[a.size()] << endl;
    int ans = 0;
    for (int i = 0; i < a.size() - b.size() + 1; i++) {
        if (((pre[b.size() + i] - pre[i]) & 1) == (bOnes & 1)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
    //asdf
}
//01100010
//00110
// ans: 3