//
// Created by JMKov on 6/17/2023.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n;
    cin >> n;
    map<int, string[5]> hash;
    vector<pair<string, string>> sameVowel;
    vector<pair<string, string>> diffVowel;
//    map<int, bool> explored;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
//        char br[5] = {'a', 'e', 'i', 'o', 'u'};
//        s = br[i % 5];
//        for (int j = 0; j < 9; j++)
//        s += (char) (std::rand() % ('z' - 'a') + 'a');
        int vowel = 0;
        int ending;
        for (char c : s) {
//            char c = br[j % 5];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o') {
                vowel++;
                switch ((int) c) {
                    case 'a': ending = 0; break;
                    case 'e': ending = 1; break;
                    case 'i': ending = 2; break;
                    case 'o': ending = 3; break;
                    case 'u': ending = 4; break;
                }
            }
        }
//        if (!explored[vowel]) {
//            for (int j = 0; j < 5; j++) hash[vowel][j] = "";
//            explored[vowel] = true;
//        }
        if (hash[vowel][ending].empty()) {
            hash[vowel][ending] = s;
        }
        else {
            sameVowel.emplace_back(hash[vowel][ending], s);
            hash[vowel][ending] = "";
        }
    }
    for (const auto& p : hash) {
        string hold;
        for (const string& s : p.second) {
            if (!s.empty() && hold.empty()) hold = s;
            else if (!s.empty()) {
                diffVowel.emplace_back(hold, s);
                hold = "";
            }
        }
    }
    string output;
    int count = min((diffVowel.size() + sameVowel.size()) / 2, sameVowel.size());
    output += to_string(count) + "\n";
    int samePtr = 0;
    int diffPtr = 0;
//    cout << "SDF" << endl;
    for (int i = 0; i < count; i++) {
        if (diffPtr < diffVowel.size()) {
            output += diffVowel[diffPtr].first + " " + sameVowel[samePtr].first + "\n" + diffVowel[diffPtr].second + " " + sameVowel[samePtr].second + "\n";
            diffPtr++; samePtr++;
        }
        else {
            output += sameVowel[samePtr].first + " " + sameVowel[samePtr + 1].first + "\n" + sameVowel[samePtr].second + " " + sameVowel[samePtr + 1].second + "\n";
            samePtr += 2;
        }
    }
    cout << output;
    return 0;
}