#include <iostream>
#include <string>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    int readingStageY = 0;
    int array[w - (w - 1) / 3][h];
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            
            if (i % 2 == 0) {
                if (s[j] == 'v') {
//                    array[]
                }
            }
        }
    }
    return 0;
}