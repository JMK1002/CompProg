#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];
    int min1 = 100000000;
    int min2 = 100000000;
    int max1 = -1;
    int max2 = -1;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        if (array[i] >= max1) {
            max2 = max1;
            max1 = array[i];
        }
        else if (array[i] >= max2) {
            max2 = array[i];
        }

        if (array[i] <= min1) {
            min2 = min1;
            min1 = array[i];
        }
        else if (array[i] <= min2) {
            min2 = array[i];
        }
    }

    cout << min(max1 - min2, max2 - min1) << endl;
    return 0;
}