#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int zeroc = 0;
    int fivec = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 5) {
            fivec++;
        }
        else {
            zeroc++;
        }
    }
    if (zeroc == 0) {
        cout << -1 << endl;
        return 0;
    }
    if (fivec < 9) {
        cout << 0 << endl;
        return 0;
    }
    
    for (int i = 0; i < (fivec - fivec % 9); i++) {
        cout << 5;
    }
    for (int i = 0; i < zeroc; i++) {
        cout << 0;
    }
    cout << endl;
    return 0;
}