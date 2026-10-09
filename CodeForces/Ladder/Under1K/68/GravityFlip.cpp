#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> columns(n);
    for (int i = 0; i < n; i++) {
        cin >> columns[i];
    }

    sort(columns.begin(), columns.end());
    for (int i : columns) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}