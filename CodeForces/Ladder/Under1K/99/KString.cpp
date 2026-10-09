#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    string newStr = "";
    int array[26] = { 0 };
    for (char c : str) {
        array[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (array[i] % n != 0 && array[i] != 0) {
            cout << -1 << endl;
            return 0;
        }
        else {
            array[i] /= n;
        }
    }

    for (int i = 0; i < 26; i++) {
        int index = newStr.size() / n;
        for (int j = 0; j < array[i]; j++) {
            newStr += i + 'a';
        }
    }
    for (int i = 0; i < n; i++) {
        cout << newStr;
    }
    cout << endl;
    return 0;
}