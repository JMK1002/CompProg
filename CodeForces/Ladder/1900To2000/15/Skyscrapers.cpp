//
// Created by JMKov on 7/4/2023
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long arr[n];
    long long sum[n];
    long long nSum[n];
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        sum[i] = 0;
        nSum[i] = 0;
    }
    vector<pair<long long, long long>> stack;
    for (long long i = 0; i < n; i++) {
        long long last = -1;
        while (!stack.empty() && arr[i] < stack.back().first) {
            last = stack.back().second;
            stack.pop_back();
        }
        if (last != -1) {
            stack.emplace_back(arr[i], last);
        }
        stack.emplace_back(arr[i], i);
        auto p = lower_bound(stack.begin(), stack.end(), *new pair<long long, long long>(arr[i], 0));
        if ((*p).second == 0) {
            sum[i] += arr[i] * (stack.back().second - (*p).second + 1);
        }
        else {
            sum[i] += sum[(*p).second - 1] + arr[i] * (stack.back().second - (*p).second + 1);
        }
//        for (pair<long long, long long> j : inc) cout << j.second << " ";
//        cout << endl;
//        for (pair<long long, long long> j : inc) cout << j.first << " ";
//        cout << endl << endl;
    }
//    for (long long i : sum) cout << i << " ";
//    cout << endl;
    reverse(arr, arr + n);
    stack.clear();
    for (long long i = 0; i < n; i++) {
        long long last = -1;
        while (!stack.empty() && arr[i] < stack.back().first) {
            last = stack.back().second;
            stack.pop_back();
        }
        if (last != -1) {
            stack.emplace_back(arr[i], last);
        }
        stack.emplace_back(arr[i], i);
        auto p = lower_bound(stack.begin(), stack.end(), *new pair<long long, long long>(arr[i], 0));
        if ((*p).second == 0) {
            nSum[i] += arr[i] * (stack.back().second - (*p).second + 1);
        }
        else {
            nSum[i] += nSum[(*p).second - 1] + arr[i] * (stack.back().second - (*p).second + 1);
        }
//        for (pair<long long, long long> j : inc) cout << j.second << " ";
//        cout << endl;
//        for (pair<long long, long long> j : inc) cout << j.first << " ";
//        cout << endl << endl;
    }
    reverse(arr, arr + n);
    reverse(nSum, nSum + n);
    for (long long i = 0; i < n; i++) {
        sum[i] -= arr[i];
        sum[i] += nSum[i];
    }
//    for (long long i : sum) cout << i << " ";
//    cout << endl;
    long long index = 0;
    for (long long i = 0; i < n; i++) if (sum[index] < sum[i]) index = i;
//    cout << index << endl;
    long long ans[n];
    long long v = arr[index];
    for (long long i = index; i < n; i++) {
        v = min(arr[i], v);
        ans[i] = v;
    }
    v = arr[index];
    for (long long i = index; i >= 0; i--) {
        v = min(arr[i], v);
        ans[i] = v;
    }
    for (long long i : ans) cout << i << " ";
    cout << endl;
    return 0;
}