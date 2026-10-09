#include <iostream>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        map<int, bool> closed;
        int n, s, k;
        cin >> n >> s >> k;
        int a = s;
        int b = s;
        for (int i = 0; i < k; i++) {
            int sdf;
            cin >> sdf;
            closed[sdf] = true;
        }
        int count = 0;
        while (closed[a] && closed[b]) {
            b--;
            b = max(b, 1);
            a++;
            a = min(a, n);
            count++;
        }
        cout << count << endl;
    }
    return 0;
}