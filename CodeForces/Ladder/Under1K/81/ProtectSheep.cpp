#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int xLen, yLen;
    int dirs[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };
    cin >> xLen >> yLen;
    string grid[xLen];
    vector<pair<int, int>> shep(0);
    
    for (int i = 0; i < xLen; i++) {
        cin >> grid[i];
        for (int j = 0; j < yLen; j++) {
            if (grid[i][j] == 'S') {
                pair<int, int> a;
                a.first = i;
                a.second = j;
                shep.insert(shep.end(), a);
            }
        }
    }
    for (int i = 0; i < shep.size(); i++) {
        for (int j = 0; j < 4; j++) {
            pair<int, int> a;
            int x = shep[i].first + dirs[j][0];
            int y = shep[i].second + dirs[j][1];
            if (x < 0 || x >= xLen || y < 0 || y >= yLen || grid[x][y] == 'S') {
                continue;
            }
            if (grid[x][y] == 'W') {
                cout << "No" << endl;
                return 0;
            }
            grid[x][y] = 'D';
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < xLen; i++) {
        cout << grid[i] << endl;
    }
    return 0;
}