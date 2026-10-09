//
// Created by JMKov on 4/22/2023.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    bool left[n + 1];
    bool right[n + 1];
    int works = 0;
    for (int i = 0; i < n + 1; i++) {
        left[i] = false;
        right[i] = false;
    }
    for (int j = 0; j < q; j++) {
        int x, y;
        cin >> x >> y;

        if (x == 1) {
            if (left[y]) {left[y] = false;}
            else {left[y] = true;}
            if (left[y]) {
                for (int i = -1; i < 2; i++) {
                    if (y + i >= 0 && y + i <= n && right[y + i]) {
                        works++;
                    }
                }
            }
            else {
                for (int i = -1; i < 2; i++) {
                    if (y + i >= 0 && y + i <= n && right[y + i]) {
                        works--;
                    }
                }
            }

        }
        else {
            if (right[y]) {right[y] = false;}
            else {right[y] = true;}
            if (right[y]) {
                for (int i = -1; i < 2; i++) {
                    if (y + i >= 0 && y + i <= n && left[y + i]) {
                        works++;
                    }
                }
            }
            else {
                for (int i = -1; i < 2; i++) {
                    if (y + i >= 0 && y + i <= n && left[y + i]) {
                        works--;
                    }
                }
            }
        }
//        works = max(works, 0);
        if (works || left[1]) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
//            cout << x << " " << y << endl;
//            cout << works << endl;
//            cout << left[4] << " " << left[5] << " " <<left[6] << endl;
//            cout << right[y] << endl;
        }
    }

    return 0;
}