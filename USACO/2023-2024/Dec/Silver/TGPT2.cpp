//
// Created by JMKov on 12/16/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

string s;
int t, c;

vector<int> targets;
set<int> hit;
set<int> invHit[5];
int pts[100004][5];
map<int, int> whenHit[5];
map<int, int> earlHit[5];
int answers[5];

void sim(int ind) {
    int ptr = ind - 2;
    for (int i = 0; i < c; i++) {
        bool hitOnThisTurn = false;

        if (s[i] == 'L') ptr--;
        else if (s[i] == 'R') ptr++;
        else {
            auto asdf = lower_bound(targets.begin(), targets.end(), ptr);
            if (asdf != targets.end() && (*asdf) == ptr) {
                whenHit[ind][ptr] = i;
                if (hit.find(ptr) == hit.end()) {
                    hit.insert(ptr);
                    earlHit[ind][ptr] = i;
                    hitOnThisTurn = true;
                }
            }
        }

        if (hitOnThisTurn) {
            if (i == 0) pts[i][ind] = 1;
            else pts[i][ind] = pts[i - 1][ind] + 1;
        }
        else {
            if (i == 0) pts[i][ind] = 0;
            else pts[i][ind] = pts[i - 1][ind];
        }
    }
    hit.clear();
}

int main() {
    cin >> t >> c;
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        targets.push_back(x);
    }
    sort(targets.begin(), targets.end());
    cin >> s;

    for (int i = 0; i < 5; i++) sim(i);

    int ptr = 0;
    for (int i = 0; i < c; i++) {
        if (s[i] == 'L') ptr--;
        else if (s[i] == 'R') ptr++;
        if (s[i] == 'F') {
            for (int ind = 0; ind < 5; ind++) {
                auto asdf = lower_bound(targets.begin(), targets.end(), ptr + ind - 2);
                if (asdf != targets.end() && (*asdf) == ptr + ind - 2) {
                    whenHit[ind][ptr + ind - 2] = i;
                    if (invHit[ind].find(ptr + ind - 2) == invHit[ind].end()) {
                        invHit[ind].insert(ptr + ind - 2);
//                        earlHit[ind][ptr + ind - 2] = i;
//                        hitOnThisTurn = true;
                    }
                }
            }
        }
    }

    int ans = pts[c - 1][2];
    for (int i = 0; i < 5; i++) {
        answers[i] = invHit[i].size();
        ans = max(ans, answers[i]);
    }

    ptr = 0;
    for (int i = 0; i < c; i++) {
        bool wasAHit = false;

        if (s[i] == 'L') {
            ptr--;
            ans = max(ans, answers[4]);

            // if it would hit for ind = 3
            auto asdf = lower_bound(targets.begin(), targets.end(), ptr + 1);
            bool hits = (asdf != targets.end() && (*asdf) == ptr + 1) && (hit.find(ptr + 1) == hit.end() && whenHit[3][ptr] < i);
            ans = max(ans, answers[3] + hits);
        }
        else if (s[i] == 'R') {
            ptr++;
            ans = max(ans, answers[0]);
            // if it would hit for ind = 1
            auto asdf = lower_bound(targets.begin(), targets.end(), ptr - 1);
            bool hits = (asdf != targets.end() && (*asdf) == ptr - 1) && (hit.find(ptr - 1) == hit.end() && whenHit[1][ptr] < i);
            ans = max(ans, answers[1] + hits);
        }
        else if (s[i] == 'F') {
            ans = max(ans, answers[1]);
            ans = max(ans, answers[3]);

            auto asdf = lower_bound(targets.begin(), targets.end(), ptr);
            if (asdf != targets.end() && (*asdf) == ptr) {
                if (hit.find(ptr) == hit.end()) {
                    hit.insert(ptr);
                    wasAHit = true;
                }
            }

            for (int ind = 0; ind < 5; ind++) {
                if (whenHit[ind][ptr + ind - 2] == i) {
                    invHit[ind].erase(ptr + ind - 2);
                    answers[ind]--;
                }
                if (invHit[ind].find(ptr + ind - 2) == invHit[ind].end() && wasAHit) answers[ind]++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}