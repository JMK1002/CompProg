#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> unsorted(0);
    vector<int> sorted(0);
    while (n--) {
        int a, b;
        cin >> a >> b;
        unsorted.insert(unsorted.end(), b);
        if (a != b) {
            cout << "rated" << endl;
            return 0;
        }
    }
    sorted = unsorted;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < unsorted.size(); i++) {
        if (sorted[i] != unsorted[sorted.size() - i - 1]) {
            cout << "unrated" << endl;
            return 0;
        }
    }
    cout << "maybe" << endl;
    return 0;
}