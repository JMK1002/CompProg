//
// Created by JMKov on 6/19/2024.
//
#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[54];
int inds[54];
vector<int> opDivs;
vector<vector<int>> ans;

void calcInds() {
    for (int i = 0; i < n; i++) {
        inds[arr[i]] = i;
    }
}

int calcRun(int ind) {
    int ret = 1;
    for (int i = ind + 1; i < n; i++) {
        if (arr[i] != arr[i - 1] + 1) return ret;
        ret++;
    }
    return ret;
}

void operation() {
    int s = 0;
    int newArr[n];
    for (int i : opDivs) {
        for (int j = 0; j < i; j++) {
            newArr[n - s - i + j] = arr[j + s];
        }
        s += i;
    }
    for (int i = 0; i < n; i++) arr[i] = newArr[i];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }

    calcInds();
    while (calcRun(0) < n) {
        int ind = 0;
        for (int i = 0; i < n - 1; i++) {
            if (inds[i] > inds[i + 1]) {
                ind = i;
                break;
            }
        }

        opDivs.push_back(inds[ind + 1]);
        int sz = calcRun(inds[ind + 1]);
        opDivs.push_back(sz);
        int sz2 = calcRun(inds[ind]);
        opDivs.push_back(sz2 + inds[ind] - (inds[ind + 1] + sz));
        opDivs.push_back(n - (inds[ind] + sz2));

        for (int i = 0; i < opDivs.size(); i++) {
            if (opDivs[i] == 0) {
                opDivs.erase(opDivs.begin() + i);
                i--;
            }
        }

        ans.push_back(opDivs);

        operation();
        calcInds();
        opDivs.clear();
//        for (int i = 0; i < n; i++) cout << arr[i] << " ";
//        cout << endl;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}