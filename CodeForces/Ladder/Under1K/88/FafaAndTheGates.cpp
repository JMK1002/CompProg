#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char cs[2];
    int ret = 0;
    pair<int, int> pos;
    pos.first = 0;
    pos.second = 0;
    bool g = false;
    for (int i = 0; i < n; i++) {
        cs[1] = cs[0];
        cin >> cs[0];

        if (cs[0] == 'U') {
            pos.second++;
        }
        else {
            pos.first++;
        }
        
        if (g && cs[0] == cs[1]) {
            ret++;
        }

        g = (pos.first == pos.second);
    }
    cout << ret << endl;
    return 0;
}