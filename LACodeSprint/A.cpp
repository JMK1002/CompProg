//
// Created by Lewis Lau on 5/18/24.
//

#include <iostream>
using namespace std;

int main() {
    long long w, p, t, b, r;
    cin >> w >> p >> t >> b >> r;

    // assume the last cycle ends when the next inspection begins
    // that should be the worst case
    long long k = p / (t + b);
    long long remain = p % (t + b);
    bool success;
    if (remain < b) {
        success = k * t * r >= w;
    } else {
        success = (k * t + remain - b) * r >= w;
    }

    if (success) {
        cout << "Soot Sprites sing a lullaby" << endl;
    } else {
        cout << "The CSHOA decrees are as murky as the Forest Spirit" << endl;
    }

}