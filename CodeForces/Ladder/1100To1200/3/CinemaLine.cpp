#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int bills[3] = {0,0,0};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        switch(a) {
            case 25:
                bills[0]++;
                break;
            case 50:
                bills[1]++;
                if (bills[0] >= 1) {
                    bills[0]--;
                }
                else {
                    cout << "NO" << endl;
                    return 0;
                }
                break;
            case 100:
                bills[2]++;
                if (bills[1] >= 1 && bills[0] >= 1) {
                    bills[0]--;
                    bills[1]--;
                }
                else if (bills[0] >= 3) {
                    bills[0] -= 3;
                }
                else {
                    cout << "NO" << endl;
                    return 0;
                }
                break;
        }
        
    }
    cout << "YES" << endl;
    return 0;
}