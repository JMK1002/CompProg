//
// Created by JMKov on 6/17/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> indicies;
vector<pair<int, int>> operations;
int arr[300010];
int n;

void doOperation(int i, int j) {
    operations.emplace_back(i, j);
    int v = arr[i];
    arr[i] = arr[j];
    arr[j] = v;
    indicies[arr[i]] = i;
    indicies[arr[j]] = j;
}

void displayInfo() {
    for (int j = 0; j < n; j++) cout << arr[j] << " ";
    cout << endl;
    for (int j = 0; j < n; j++) cout << indicies[j] << " ";
    cout << endl << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) indicies.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
        indicies[arr[i]] = i;
    }
//    displayInfo();
    for (int i = 0; i < n; i++) {
        if (i == indicies[i]) continue;
        if (abs(indicies[i] - i) * 2 >= n) {
            doOperation(i, indicies[i]);
        }
        else if (abs(max(i, indicies[i]) - (n - 1)) * 2 >= n) {
            doOperation(i, n - 1);
            doOperation(n - 1, indicies[i]);
            doOperation(i, n - 1);
        }
        else if (min(i, indicies[i]) * 2 >= n) {
            doOperation(i, 0);
            doOperation(0, indicies[i]);
            doOperation(i, 0);
        }
        else {
            int a = max(i, indicies[i]);
            int b = min(i, indicies[i]);
            doOperation(a, 0);
            doOperation(b, n - 1);
            doOperation(0, n - 1);
            doOperation(a, 0);
            doOperation(b, n - 1);
        }
//        displayInfo();
    }
    cout << operations.size() << endl;
    for (pair<int, int> p : operations) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
    return 0;
}

// 1 2 3 4 5 6