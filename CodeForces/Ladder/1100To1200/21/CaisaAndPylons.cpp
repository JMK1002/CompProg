#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int lowest = 1000000000;
    int energy = 0;
    int h = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        energy += h - a;
        h = a;
        if (energy < lowest) {
            lowest = energy;
        }
    }
    cout << min(0, lowest) * -1 << endl;
    return 0;
}