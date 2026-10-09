#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n - 1];
    int path[200002] = { -1 };
    for (int i = 0; i < n - 1; i++) {
        cin >> array[i];
    }
    int a = array[n - 2];
    int count = 1;
    path[0] = n;
    while (a != 1) {
        path[count] = a;
        a = array[a - 2];
        count++;
    }

    cout << 1 << " ";
    for (int i = count - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    return 0;
}