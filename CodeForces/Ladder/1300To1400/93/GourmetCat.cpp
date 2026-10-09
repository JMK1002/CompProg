//
// Created by JMKov on 5/2/2023.
//
#include <iostream>
using namespace std;

// a b c a c b a

int main() {
    int schedule[7] = {0, 1, 2, 0, 2, 1, 0};
    int food[3];
    cin >> food[0] >> food[1] >> food[2];
    int ans = min(food[2] / 2, min(food[1] / 2, food[0] / 3));
    food[0] -= ans * 3;
    food[1] -= ans * 2;
    food[2] -= ans * 2;
    int mx = 0;
    for (int i = 0; i < 7; i++) {
        int testFood[3];
        for (int j = 0; j < 3; j++) testFood[j] = food[j];
        int count = 0;
        int a = i;
        while (testFood[0] >= 0 && testFood[1] >= 0 && testFood[2] >= 0) {
            testFood[schedule[a]]--;
            a++;
            a %= 7;
            count++;
        }
        count--;
        mx = max(count, mx);
    }

//    cout << mx << endl;
    cout << ans * 7 + mx << endl;
    return 0;
}