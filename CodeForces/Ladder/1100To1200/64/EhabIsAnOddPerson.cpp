//
// Created by JMKov on 3/27/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    if (((a + b) & 1) == 0) {
        return false;
    }
    return a < b;
}

int main() {
    int n;
    cin >> n;
    vector<int> pray(n);
    bool hasOdd = false;
    bool hasEven = false;
    for (int i = 0; i < n; i++) {
        cin >> pray[i];
        hasOdd = hasOdd || ((pray[i] & 1) == 1);
        hasEven = hasEven || (pray[i] & 1) == 0;
    }
    if (hasOdd && hasEven) {
        sort(pray.begin(), pray.end());
    }
    for (int i : pray) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}