#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int prefix[s.length()] = { 0 };
    for (int i = 1; i < s.length(); i++) {
        prefix[i] = prefix[i - 1] + (s[i] == s[i - 1]);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        cout << prefix[b] - prefix[a] << endl;
    }
    return 0;
}