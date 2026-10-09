#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int groups;
    cin >> groups;
    int q[4] = {0, 0, 0, 0};
    int result = 0;
    for (int i = 0; i < groups; i++) {
        int childs;
        cin >> childs;
        childs--;
        q[childs]++;
    }
    int min3s = min(q[0], q[1]);
    q[0] -= min3s;
    q[2] -= min3s;
    result += min3s;
    result += q[1] / 2;
    q[1] -= (q[1] / 2) * 2;
    int min1s = min(q[0], q[1]);
    result += min1s;
    q[0] -= min1s;
    q[1] -= min1s;
    result += q[0] / 4;
    q[0] -= q[0] / 4 * 4;
    for (int i : q) {
        result += i;
    }

    cout << result << endl;
}