#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
int index(const vector<T>& vec, const T& n) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == n) {
			return i;
		}
	}
	return -1;
}

int main() {
    ifstream indata("gymnastics.in");
    int n;
    int k;
    indata >> k;
    indata >> n;
    vector<vector<int>> data(k, vector<int> (n));

    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            indata >> data[i][j];
            data[i][j]--;
        }
    }

    int pairs = 0;
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < n; l++) {
            if (i == l) {
                continue;
            }

            bool relationship = true;
            for (const vector<int>& s : data) {
                if (index(s, i) < index(s, l)) {
                    relationship = false;
                    break;
                }
            }

            if (relationship) {
                pairs++;
            }
        }
    }
    indata.close();
    ofstream write("gymnastics.out");
    write << pairs;
    write.close();
}