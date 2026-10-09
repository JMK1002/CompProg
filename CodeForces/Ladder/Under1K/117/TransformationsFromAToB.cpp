#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> steps = {b};
    while (a < b) {
        if (b % 2 == 0) {
            b /= 2;
            steps.insert(steps.end(), b);
        }
        else if (b % 10 == 1) {
            b -= 1;
            b /= 10;
            steps.insert(steps.end(), b);
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (a != b) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << steps.size() << endl;
    for (int i = steps.size() - 1; i >= 0; i--) {
        cout << steps[i] << " ";
    }

    return 0;
}