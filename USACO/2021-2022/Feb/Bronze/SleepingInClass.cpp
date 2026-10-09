#include <string>
#include <vector>
#include <iostream>
using namespace std;


int main() {
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        int listSize;
        cin >> listSize;
        vector<int> list(listSize);
        int totalHours = 0;
        for (int j = 0; j < listSize; j++) {
            cin >> list[j];
            totalHours += list[j];
        }
        listSize % i;
        for (int j = listSize; j >= 0; j--) {
            if (j != 0 && listSize % j != 0) {
                continue;
            }
            int countingHours = 0;
            int targetSleep = totalHours / j;
            bool equal = true;
            for (int k : list) {
                countingHours += k;
                if (countingHours > targetSleep) {
                    equal = false;
                    break;
                }
                else if (countingHours == targetSleep) {
                    countingHours = 0;
                }
            }

            if (equal) {
                if (j == 0) {
                    cout << 0 << endl;
                    break;
                }
                else {
                    cout << (listSize - j) << endl;
                    break;
                }
            }
        }
    }
}