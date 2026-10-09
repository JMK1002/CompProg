//
// Created by JMKov on 4/16/2023.
//
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    map<int, int> mp;
    mp[4] = 0;
    mp[8] = 1;
    mp[15] = 2;
    mp[16] = 3;
    mp[23] = 4;
    mp[42] = 5;
    int count[6];
    int snake[6];
    for(int i = 0; i < 6; i++) {
        count[i] = 0;
        snake[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[i] = mp[a];
        count[arr[i]]++;
        if (arr[i] == 0) {
            snake[arr[i]]++;
        }
        else if (snake[arr[i] - 1] > 0) {
            snake[arr[i] - 1]--;
            snake[arr[i]]++;
        }
    }
    cout << n - snake[5] * 6 << endl;
    return 0;
}