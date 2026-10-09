//
// Created by JMKov on 4/6/2023.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> quantities;
    map<int, int> first;
    map<int, int> last;
    vector<int> array(n);
    vector<int> highestQuantities(0);
    int highestQuantity = 0;
    int actualAns = 1000000;
    int aaaaaa = -1;
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
        quantities[array[i]]++;
        if (!first[array[i]]) {
            first[array[i]] = i + 1;
        }
        if (quantities[array[i]] > highestQuantity) {
            highestQuantities.erase(highestQuantities.begin(), highestQuantities.end());
            highestQuantities.insert(highestQuantities.begin(), array[i]);
            highestQuantity = quantities[array[i]];
            aaaaaa = i + 1;
            actualAns = i + 1 - first[array[i]];
        }
        else if (quantities[array[i]] == highestQuantity) {
            if (i + 1 - first[array[i]] < actualAns) {
                aaaaaa = i + 1;
                actualAns = i + 1 - first[array[i]];
            }
        }
    }
//    int ans = 1000000000;
//    int ansIndex = -1;
//    for (int i : highestQuantities) {
////        cout << last[i] - first[i] << endl;
//        if (last[i] - first[i] < ans) {
//            ans = last[i] - first[i];
//            ansIndex = i;
//        }
//    }
    cout << first[array[aaaaaa - 1]] << " " << aaaaaa << endl;
    return 0;
}