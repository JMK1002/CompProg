#include <iostream>
using namespace std;

int main() {
    int n;
    int i1 = -1;
    int i2 = -1;
    int li = -1;
    long long min = 10000000001;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        if (a < min) {
            min = a;
            i1 = i;
            i2 = -1;
            li = i;
        }
        else if (a == min) {
            if (i1 - i2 >= i - li || i2 == -1) {            
                i2 = li;
                i1 = i;
            }
            li = i;
        }
    }
    cout << i1 - i2 << endl;
    return 0;
}