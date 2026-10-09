#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int binSearch(int val, int low, int high) {
    int mid = (low + high) / 2;
    if (low > high) {
        return pow(2, mid);
    }

    else if (pow(2, mid) == val) {
        return val;
    } 
    else if (pow(2, mid) < val) {
        return binSearch(val, mid + 1, high);
    }
    else {
        return binSearch(val, low, mid - 1);
    }
}

int main() {
    int n, b, p;
    cin >> n >> b >> p;
    int tc = p * n;
    int bc = 0;
    while (n != 1) {
        int roundPopulation = pow(2, (int) log2(n));
        bc += roundPopulation * b;
        bc += roundPopulation / 2;
        n -= roundPopulation / 2;
    }
    cout << bc << " " << tc << endl;
    return 0;

}