#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int left[n];
    int right[n];
    left[0] = (s[0] == '(');
    right[n - 1] = (s[n - 1] == ')');
    for (int i = 1; i < n; i++) {
        left[i] = left[i - 1] + (s[i] == '(');
    }
    for (int i = n - 2; i >= 0; i--) {
        right[i] = right[i + 1] + (s[i] == ')');
    }
    int index = -1;
    for (int i = 0; i < n; i++) {
        cout << left[i] << " " << right[i] << endl;
        if (left[i] == right[i]) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << 0 << endl;
        return 0;
    }
    cout << 1 << endl;
    vector<int> output(0);
    for (int i = 0; i <= index; i++) {
        if (s[i] == '(') {
            output.insert(output.end(), i);
        }
    }
    for (int i = n - 1; i >= index  ; i--) {
        if (s[i] == ')') {
            output.insert(output.end(), i);
        }
    }
    cout << output.size() << endl;
    for (int i : output) {
        cout << i + 1 << " ";
    }
    return 0;
}