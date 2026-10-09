//
// Created by JMKov on 5/17/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int n;
vector<int> arr;

long long condition(int s, int k) {
    vector<long long> sorted(n);
    for (int i = 0; i < n; i++) {
        sorted[i] = (long long) arr[i] + (long long) (i + 1) * (long long) k;
    }
    sort(sorted.begin(), sorted.end());
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += sorted[i];
    }
    if (sum > s) return -1;
    return sum;
}

bool compare(int a, int b) {
    return arr[a] < arr[b];
}

int main() {
    int s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int low = 1;
    int high = n;
    while (low < high) {
        int k = (low + high) / 2;
        if (condition(s, k) == -1) {
            high = k - 1;
        }
        else {
            low = k + 1;
        }
    }
    low -= condition(s, low) == -1;
    cout << low << " " << condition(s, low) << endl;
}