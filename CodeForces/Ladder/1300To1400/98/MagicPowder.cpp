//
// Created by JMKov on 5/4/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ingredients[n];
    int supplies[n];
    for (int i = 0; i < n; i++) cin >> ingredients[i];
    for (int i = 0; i < n; i++) cin >> supplies[i];
    int cookies = 1000000000;
    for (int i = 0; i < n; i++) cookies = min(cookies, supplies[i] / ingredients[i]);
    for (int i = 0; i < n; i++) supplies[i] -= cookies * ingredients[i];
    while (k >= 0) {
        int required = 0;
        for (int i = 0; i < n; i++) required += max(0, ingredients[i] - supplies[i]);
        for (int i = 0; i < n; i++) supplies[i] -= min(supplies[i], ingredients[i]);
        k -= required;
        cookies++;
    }
    cookies--;
    cout << cookies << endl;
    return 0;
}