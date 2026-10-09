#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long count = 0;
    long long total = 0;
    while (count != -1) {
        total += count * (1 + count);
        if (total > 2 * n) {
            cout << count - 1 << endl;
            count = n + 1;
            break;
        }
        count++;
    }
}