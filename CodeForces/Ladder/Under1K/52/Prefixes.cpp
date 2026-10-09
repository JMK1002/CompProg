#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    int hn = n / 2;
    int counts[2] = {0, 0};
    int ret = 0;
    for (int i = 0; i < n; i += 2) {
        if (str[i] == 'a') {
            if (str[i + 1] == 'a') {
                ret++;
                str.replace(str.begin() + i + 1, str.begin() + i + 2, "b");
            }
        }
        else {
            if (str[i + 1] == 'b') {
                ret++;
                str.replace(str.begin() + i + 1, str.begin() + i + 2, "a");
            }
        }
    }
    cout << ret << endl << str << endl;
    return 0;
}