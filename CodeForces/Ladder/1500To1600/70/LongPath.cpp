//
// Created by JMKov on 5/27/2023.
//
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long arr[n];
//    long long got[n];
//    bool count[n];
    long long moves[n];
    long long differences[n];
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
//        count[i] = false;
//        got[i] = -1;
        moves[i] = -1;
    }
    moves[0] = 0;
    differences[0] = 1;
//    long long pos = 0;
//    long long time = 0;
//    while (true) {
//        if (got[pos] == -1) {
//            got[pos] = time;
//        }
//        time++;
//        if (!count[pos]) {
//            count[pos] = true;
//            pos = arr[pos];
//        }
//        else {
//            count[pos] = false;
//            pos++;
//            if (pos == n) {
//                break;
//            }
//        }
//    }
//    cout << time << endl;
//    for (long long i : got) cout << i << " ";
//    cout << endl;
    for (long long i = 1; i < n; i++) {
        moves[i] = differences[i - 1] + moves[i - 1] + 1;
        differences[i] = i - arr[i] + 1;
        moves[i] %= 1000000007;
        for (long long j = arr[i]; j < i; j++) {
            differences[i] += differences[j];
            differences[i] %= 1000000007;
        }
    }
//    for (long long i : moves) cout << i << " ";
//    cout << endl;
//    for (long long i : differences) cout << i << " ";
//    cout << endl;
    cout << (differences[n - 1] + moves[n - 1] + 1) % 1000000007 << endl;
    return 0;
}
// 1 1 2 1  3  3
// 0 2 6 12 26 48
// 1 3 5 13 21 43
// time[i] = time[arr[i]] + time[arr[i] + 1]... time[i - 1] + arr[i]
// time[i] += for (long long j = arr[i]; j < i; j++) time[j] + arr[i]

//6
//1 1 2 1 3 3
//92
//0 2 6 12 26 48