#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> sizes(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        sizes[i] = s.size();
    }
    string ans;
    cin >> ans;
    sort(sizes.begin(), sizes.end());
    int asdf = -1;
    for (int i = 0; i < n; i++) {
        if (sizes[i] == ans.size() && asdf == -1) {
            asdf = i;
        }
        else if (asdf != -1 && sizes[i] != ans.size()) {
            n = i;
            i = n;
        }
    }
    cout << (asdf) / k * 5 + asdf + 1 << " " << (n - 1) / k * 5 + n << endl;
    return 0;
}