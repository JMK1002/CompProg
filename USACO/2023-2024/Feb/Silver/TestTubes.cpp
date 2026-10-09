//
// Created by JMKov on 2/18/2024.
//
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> solve(int n, string s1, string s2) {
    bool start1 = (s1[n - 1] == '1');
    bool start2 = (s2[n - 1] == '1');
    int l1 = 1;
    int l2 = 1;
    for (int i = 1; i < n; i++) {
        l1 += (s1[i] != s1[i - 1]);
        l2 += (s2[i] != s2[i - 1]);
    }
    vector<pair<int, int>> moves;
    for (int i = 0; i < l1; i++) {
        if (i % 2 == 0) {
            if (start2 == start1) moves.emplace_back(1, 2);
            else moves.emplace_back(1, 3);
        }
        else {
            if (start2 == start1) moves.emplace_back(1, 3);
            else moves.emplace_back(1, 2);
        }
    }

    moves.emplace_back(2, 1);

    for (int i = 0; i < l2 - 1; i++) {
        if (i % 2 == 0) {
            moves.emplace_back(2, 3);
        }
        else {
            moves.emplace_back(2, 1);
        }
    }
    moves.emplace_back(3, 2);
    vector<pair<int, int>> fmoves;
    int cnt = 0;
    for (int i = 0; i < moves.size(); i++) {
        fmoves.emplace_back(moves[i]);
        cnt += (moves[i].second == 3);
        if (i == 0) continue;
        if (fmoves[fmoves.size() - 1].first == fmoves[fmoves.size() - 2].second && fmoves[fmoves.size() - 1].second == fmoves[fmoves.size() - 2].first) {
            if (fmoves[fmoves.size() - 2].second == 3) {
                if (cnt == 1) {
                    cnt = 0;
                    fmoves.erase(fmoves.begin() + (fmoves.size() - 1));
                    fmoves.erase(fmoves.begin() + (fmoves.size() - 1));
                    continue;
                }
                cnt--;
            }
            fmoves.erase(fmoves.begin() + (fmoves.size() - 2));
        }
    }
//    bool hasStuff = false;
//    for (int i = 0; i < fmoves.size(); i++) {
//        if (fmoves[i].first == 1) {
//            if (l1 == 0) {
//                // erase & cont
//            }
//            l1--;
//            start1 = !start1;
//        }
//        else if (fmoves[i].first == 2) {
//            if (l2 == 0) {
//                // erase & cont
//            }
//            l2--;
//            start2 = !start2;
//        }
//        else {
//            if (!hasStuff) {
//                // erase and cont
//            }
//            hasStuff = false;
//        }
//        if (fmoves[i].second == 3) hasStuff
//    }
    return fmoves;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        string s1, s2;
        cin >> n >> p >> s1 >> s2;
        vector<pair<int, int>> m1 = solve(n, s1, s2);
        vector<pair<int, int>> m2 = solve(n, s2, s1);

        if (p == 1) cout << min(m1.size(), m2.size()) << endl;
        else {
            cout << min(m1.size(), m2.size()) << endl;
            if (m1.size() < m2.size()) {
                for (pair<int, int> p2 : m1) cout << p2.first << " " << p2.second << endl;
            }
            else {
                for (pair<int, int> p2 : m2) {
                    pair<int, int> a = {p2.first, p2.second};
                    if (a.first == 1) a.first = 2;
                    else if (a.first == 2) a.first = 1;
                    if (a.second == 1) a.second = 2;
                    else if (a.second == 2) a.second = 1;
                    cout << a.first << " " << a.second << endl;
                }
            }
        }

    }
    return 0;
}
//6
//4 1
//1221
//2211
//4 2
//1221
//2211
//4 3
//1221
//2211
//6 3
//222222
//111112
//4 3
//1121
//1222
//4 2
//1121
//1222

//4
//4
//1 2
//1 3
//2 1
//3 2
//4
//1 2
//1 3
//2 1
//3 2
//1
//2 1
//5
//2 3
//1 2
//1 3
//1 2
//3 1
//6
//2 3
//1 2
//1 3
//1 2
//2 1
//3 2

//In the first three test cases, the minimum number of pours to separate the tubes is 4
//. We can see how the following moves separate the test tubes:
//Initial state:
//
//1: 1221
//2: 2211
//3:
//After the move "1 2":
//1: 122
//2: 22111
//3:
//After the move "1 3":
//1: 1
//2: 22111
//3: 22
//After the move "2 1":
//1: 1111
//2: 22
//3: 22
//After the move "3 2":
//1: 1111
//2: 2222
//3:
//In the last test case, the minimum amount of pours is 5
//. However, since P=2
//, the given construction with 6
// moves is valid since it is within 5
// pours from the optimal answer.