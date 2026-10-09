#include <iostream>
#include <math.h>
using namespace std;

pair<string, string> move(pair<string, string> pos) {
    pair<string, string> ret = pos;
    int x1 = pos.first[0] - 'a';
    int x2 = pos.second[0] - 'a';
    if (x1 < x2) {
        cout << 'R';
        ret.first[0] = ret.first[0] + 1;
    }
    else if (x1 > x2) {
        cout << 'L';
        ret.first[0] = ret.first[0] - 1;
    }

    int y1 = pos.first[1];
    int y2 = pos.second[1];
    if (y1 < y2) {
        cout << 'U';
        ret.first[1] = ret.first[1] + 1;
    }
    else if (y1 > y2) {
        cout << 'D';
        ret.first[1] = ret.first[1] - 1;
    }
    cout << endl;
    return ret;
}

int main() {
    pair<string, string> pos;
    cin >> pos.first >> pos.second;
    cout << max(abs(pos.first[0] - pos.second[0]), abs(pos.first[1] - pos.second[1])) << endl;
    while (pos.first != pos.second) {
        pos = move(pos);
    }
    return 0;
}