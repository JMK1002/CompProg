//
// Created by JMKov on 4/4/2023.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int binSearch(int target, vector<int> array, int low, int high) {
    if (low > high) {
        return low + (array[low] < target);
    }
    int mid = (low + high) / 2;
    if (array[mid] == target) {
        return mid;
    }
    else if (array[mid] < target) {
        return binSearch(target, array, mid + 1, high);
    }
    else {
        return binSearch(target, array, low, mid - 1);
    }
}

vector<int> generatePrimes(int n) {
    int list[n - 1];
    for (int i = 0; i < n - 1; i++) {
        list[i] = i + 2;
    }
    for (int i = 0; list[i] < sqrt(n); i++) {
        int val = list[i];
        if (val == -1) {
            continue;
        }
        for (int j = i + val; j < n; j += val) {
            list[j] = -1;
        }
    }
    vector<int> out(0);
    for (int i : list) {
        if (i != -1) {
            out.insert(out.end(), i);
        }
    }
    return out;
}

int main() {

    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            maxVal = max(matrix[i][j], maxVal);
        }
    }
    // using the prime sieve up to 10^5, the largest gap was 72, so
    // increasing the max value by 80 ensures it finds the next prime
    maxVal += 80;
    vector<int> primes = generatePrimes(maxVal);

    int deltaMatrix[n][m];
    int deltaPrime[maxVal];
    int index = 0;
    for (int i = 0; i < maxVal; i++) {
        deltaPrime[i] = primes[index] - i;
        index += i == primes[index];
//        cout << deltaPrime[i] << " ";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            deltaMatrix[i][j] = deltaPrime[matrix[i][j]];
//            cout << deltaMatrix[i][j] << endl;
        }
    }

    int mn = 1000000000;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += deltaMatrix[i][j];
        }
        mn = min(mn, sum);
    }

    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += deltaMatrix[j][i];
        }
        mn = min(mn, sum);
    }
    cout << mn << endl;
    return 0;
}