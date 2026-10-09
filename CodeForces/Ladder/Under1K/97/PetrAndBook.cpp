#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int pages[7];
    int count = -1;
    for (int i = 0; i < 7; i++) {
        cin >> pages[i];
    }
    while (n > 0) {
        count++;
        count %= 7;
        n -= pages[count];
    }
    cout << count + 1 << endl;
}