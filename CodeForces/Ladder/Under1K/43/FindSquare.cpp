#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int x1 = -1, y1, x2, y2;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'B') {
                x2 = i;
                y2 = j;
                if (x1 == -1) {
                    x1 = i;
                    y1 = j;
                }
            }
        }
    }

    cout << (x1 + x2) / 2 + 1 << " " << (y1 + y2) / 2 + 1 << endl;  
    return 0;
}