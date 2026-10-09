#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int psum[n + 1];
    int sum = 0;
    psum[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        cin >> psum[i];
        sum += psum[i];
        psum[i] += psum[i - 1];
    }

    int a, b;
    cin >> a >> b;
    int dist = abs(psum[b - 1] - psum[a - 1]);
    cout << min(dist, sum - dist) << endl;
}