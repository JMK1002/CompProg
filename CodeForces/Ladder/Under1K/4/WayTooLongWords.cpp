#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string word;
        cin >> word;
        
        if (word.length() > 10) {
            cout << word[0] << word.length() - 2 << word[word.length() - 1] << endl;
            continue;
        }
        cout << word << endl;
    }
    return 0;
}