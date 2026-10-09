#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int pointer = 1;
    int count = 0;
    while (n >= pointer) {
        if ((pointer & n) == pointer) {
            count++;
        }
        pointer = pointer << 1;
    }
    cout << count << endl;
    return 0;
}