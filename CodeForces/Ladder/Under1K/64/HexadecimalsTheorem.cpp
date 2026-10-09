#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "0 0 0" << endl;
        return 0;
    }
    if (n == 1) {
        cout << "1 0 0" << endl;
        return 0;
    }
    if (n == 2) {
        cout << "1 1 0" << endl;
        return 0;
    }
    vector<long long> fib(3, 1);
    fib[0] = 0;
    while (fib[fib.size() - 1] < n) {
        fib.insert(fib.end(), fib[fib.size() - 1] + fib[fib.size() - 2]);
    }
    cout << fib[fib.size() - 3] << " " << fib[fib.size() - 3] << " " << fib[fib.size() - 4] << endl;
    return 0;
}