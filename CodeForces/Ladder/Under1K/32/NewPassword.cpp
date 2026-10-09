#include <string>
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string str = "";
    if (n == 1) {
        cout << "a" << endl;
        return 0;
    }

    for (int i = 0; i < n - k + 2; i++) {
        str += (i % 2 == 0) ? 'a' : 'b';
    }
    for (int i = n - k + 2; i < n; i++) {
        str += (char) (i - n + k + 97);
    }
    cout << str << endl;
    return 0;
}