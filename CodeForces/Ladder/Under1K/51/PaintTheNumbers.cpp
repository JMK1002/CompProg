#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    int mini = 1000000;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        mini = min(mini, array[i]); 
    }
    while (array.size() > 0) {
        int a = mini;
        mini = 100000000;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] % a == 0) {
                array.erase(array.begin() + i);
                i--;
            }
            else if (array[i] < mini) {
                mini = array[i];
            }
        }
        ret++;
    }
    cout << ret << endl;
    return 0;
}