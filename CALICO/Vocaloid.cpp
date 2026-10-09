#include <iostream>
#include <vector>

using namespace std;

/**
 * Find an HQ9+ program that outputs exactly the given text or return IMPOSSIBLE
 * if no solutions exist.
 * 
 * N: the number of lines of text
 * X: a list containing the lines of the text
 */
string solve(int n, vector<string> &x) {
    string ans;
    string currQ = "}{}{}{POPOPO";
    for (int i = 0; i < n; i++) {
        if (x[i] == "Hello, world!") {
            ans += "H";
        }
        else if (x[i] == "99 bottles of beer on the wall, 99 bottles of beer.") {
//            cout << (x[i + 1]) << endl;
//            cout << (x[i + 2]) << endl;
//            cout << x[i + 3] << endl;
//            cout << x[i + 4] << endl;
//            cout << x[i + 5] << endl;
//            cout << x[i + 6] << endl;
//            cout << x[i + 7] << endl;
            if ((x[i + 1] != "Take one down and pass it around, 98 bottles of beer on the wall.") ||
                    (x[i + 2] != "98 bottles of beer on the wall, 98 bottles of beer.") ||
                    (x[i + 3] != "Take one down and pass it around, 97 bottles of beer on the wall.") ||
                    (x[i + 4] != "97 bottles of beer on the wall, 97 bottles of beer.") ||
                    (x[i + 5] != "Take one down and pass it around, 96 bottles of beer on the wall.")) {
                return "IMPOSSIBLE";
            }
            else {
                ans += "9";
                i += 5;
            }
        }
        else {
            if (currQ != "}{}{}{POPOPO" && x[i] != currQ) {
                return "IMPOSSIBLE";
            }
            currQ = x[i];
            string removePlus;
            for (char c : currQ) {
                if (c != '+') removePlus += c;
            }
            removePlus = removePlus.substr(0, ans.size());
            if (ans != removePlus) {
                return "IMPOSSIBLE";
            }
            ans += "Q";
        }
    }
    if (currQ == "}{}{}{POPOPO") return ans;
    string removePlus;
    for (char c : currQ) {
        if (c != '+') {
            removePlus += c;
        }
    }
    if (ans != removePlus) {
        return "IMPOSSIBLE";
    }
    return currQ;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cin.get();
        vector<string> X(N);
        for (int j = 0; j < N; j++) {
            getline(cin, X[j]);
        }
        cout << solve(N, X) << '\n';
    }
}
