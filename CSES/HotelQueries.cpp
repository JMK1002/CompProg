//
// Created by JMKov on 11/16/2023.
//
#include <iostream>
using namespace std;

int t[800002];
int arr[200002];
int n, m;

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = arr[l];
    }
    else {
        int mid = (l + r) / 2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

void modify(int v, int l, int r, int index, int val) {
    if (l == index && r == index) {
        t[v] = val;
        arr[index] = val;
    }
    else {
        int mid = (l + r) / 2;
        if (index <= mid) {
            modify(v * 2, l, mid, index, val);
        }
        else {
            modify(v * 2 + 1, mid + 1, r, index, val);
        }
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

int query(int v, int l, int r, int al, int ar) {
    if (l > r || al > ar) {
        return 0;
    }
    else if (l == al && r == ar) {
        return t[v];
    }
    else {
        int mid = (l + r) / 2;
        return max(query(v * 2, l, mid, al, min(ar, mid)),
                   query(v * 2 + 1, mid + 1, r, max(al, mid + 1), ar));
    }
}

int findIndex(double target) {
    cin.tie();
    cout.tie();
    istream::sync_with_stdio(0);
    int low = 0;
    int high = n - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        int val = query(1, 0, n - 1, 0, mid);
        if (val < target) {
            low = mid + 1;
        }
        else if (val > target) {
            high = mid - 1;
        }
    }
    low += (query(1, 0, n - 1, 0, low) < target);
    return low;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
//    for (int i = 0; i < 40; i++) cout << t[i] << " ";
//    for (int i = 0; i < n; i++) {
//        cout << query(1, 0, n - 1, 0, i) << endl;
//    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int ind = findIndex(x - 0.5);
        if (ind == n) {
            cout << 0 << " ";
        }
        else {
            cout << ind + 1 << " ";
            modify(1, 0, n - 1, ind, arr[ind] - x);
        }
    }
    return 0;
}