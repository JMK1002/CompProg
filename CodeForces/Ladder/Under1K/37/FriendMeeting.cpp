#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int a = min(x, y);
    int b = max(x, y);
    int count1 = 1;
    int count2 = 1;
    int tiredness = 0;
    while (a != b) {
        a++;
        tiredness += count1;
        count1++;
        if (a == b) {
            break;
        }
        tiredness += count2;
        count2++;
        b--;
    }
    cout << tiredness << endl;
    return 0;
}