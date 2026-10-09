#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool goodCars[n] = { false };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cell;
            cin >> cell;
            switch (cell) {
                case 1:
                    goodCars[i] = true;
                    break;
                case 2:
                    goodCars[j] = true;
                    break;
                case 3:
                    goodCars[i] = true;
                    goodCars[j] = true;
                    break;
            }
        }
    }
    string s = "";
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!goodCars[i]) {
            s += to_string(i + 1) + " ";
            count++;
        }
    }
    cout << count << endl;
    cout << s << endl;
    return 0;
}