#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ret = 0;
    for (char c : s) {
        ret += 1;
        if (c == '0') {
            break;
        }
    }
    cout << ret << endl;
    return 0;
}