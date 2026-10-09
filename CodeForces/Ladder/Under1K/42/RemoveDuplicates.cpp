#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];
    vector<int> newArray; 
    bool intsOccupied[1001] = { false };
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (!intsOccupied[array[i]]) {
            intsOccupied[array[i]] = true;
            newArray.insert(newArray.begin(), array[i]);
        }
    }
    cout << newArray.size() << endl;
    for (int i : newArray) {
        cout << i << " ";
    }
    return 0;
}