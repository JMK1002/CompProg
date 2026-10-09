#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int array[n];
    int personSum;
    bool covered[n] = { false };
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        sum += array[i];
    }
    int pairSum = 2 * sum / n;
    for (int i = 0; i < n; i++) {
        if (covered[i]) {
            continue;
        }
        covered[i] = true;
        int a = pairSum - array[i];
        for (int j = 0; j < n; j++) {
            if (array[j] == a && !covered[j]) {
                covered[j] = true;
                cout << i + 1 << " " << j + 1 << endl;
                j = n + 1;
            }
        }
    }
}