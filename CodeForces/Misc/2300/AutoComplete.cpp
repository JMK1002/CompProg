#include <iostream>
#include <map>
#include <set>
using namespace std;

struct Node {
    int best;
    map<int, int> children;

    Node() {
        best = -1;
    }

    Node(int b) {
        best = b;
    }
};

Node trie[2000006];
int par[2000006];
string strings[100006];
multiset<string> ms;
map<pair<int, int>, bool> FUCKTHIS;
map<string, set<int>> inv;
int position = 0;
int nxt = 0;

bool compare(int a, int b) {
    if (FUCKTHIS.find({a, b}) != FUCKTHIS.end()) return FUCKTHIS[{a, b}];

    if (a == -1) return false;
    else if (b == -1) return true;

    else if (strings[a].size() > strings[b].size()) return true;
    else if (strings[a].size() < strings[b].size()) return false;
    
    else if (strings[a] < strings[b]) {
        FUCKTHIS[{a, b}] = true;
        return true;
    }
    else if (strings[a] > strings[b]) {
        FUCKTHIS[{a, b}] = false;
        return false;
    }

    FUCKTHIS[{a, b}] = a < b;
    return a < b;
}

void add(int id) {
    string s = strings[id];
    inv[s].insert(id);
    ms.insert(s);
    int curr = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i];
        if (trie[curr].children.find(c) == trie[curr].children.end()) {
            trie[curr].children[c] = ++nxt;
            trie[nxt] = Node(-1);
            par[nxt] = curr;
        }
        if (compare(id, trie[curr].best)) {
            trie[curr].best = id;
        }
        curr = trie[curr].children[c];
    }
    if (compare(id, trie[curr].best)) {
        trie[curr].best = id;
    }
}

void del(int id) {
    string s = strings[id];
    inv[s].erase(id);
    ms.erase(ms.find(s));
    int curr = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i];
        curr = trie[curr].children[c];
    }

    string stringPosition = s;

    if (trie[curr].best == id) {
        trie[curr].best = (ms.find(stringPosition) != ms.end()) ? *inv[stringPosition].begin() : -1;
        for (pair<int, int> n : trie[curr].children) {
            if (compare(trie[n.second].best, trie[curr].best)) {
                trie[curr].best = trie[n.second].best;
            }
        }
    }

    while (curr) {
        curr = par[curr];
        stringPosition.pop_back();
        if (trie[curr].best == id) {
            trie[curr].best = (ms.find(stringPosition) != ms.end()) ? *inv[stringPosition].begin() : -1;
            for (pair<int, int> n : trie[curr].children) {
                if (compare(trie[n.second].best, trie[curr].best)) {
                    trie[curr].best = trie[n.second].best;
                }
            }
        }
    }
}

void app(string s) {
    for (int i = 0; i < s.size(); i++) {
        int c = s[i];
        if (trie[position].children.find(c) == trie[position].children.end()) {
            trie[position].children[c] = ++nxt;
            trie[nxt] = Node(-1);
            par[nxt] = position;
        }
        position = trie[position].children[c];
    }
}

void back(int n) {
    for (int i = 0; i < n; i++) {
        position = par[position];
    }
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    // string lkj = "";
    // for (int i = 0; i < 1000000; i++) lkj += "a";
    for (int i = 0; i < n; i++) {
        string asdf;
        cin >> asdf;
        
        if (asdf == "add") {
            int x;
            cin >> x >> strings[x];
            // strings[x] = lkj;
            add(x);
        }
        else if (asdf == "append") {
            string s;
            cin >> s;
            // s = lkj;
            app(s);
        }
        else if (asdf == "backspace") {
            int x;
            cin >> x;
            back(x);
        }
        else {
            int x;
            // cout << "SDF" << endl;
            cin >> x;
            del(x);
        }

        cout << trie[position].best << endl;
    }
    return 0;
}
// 5
// add 1 apple
// add 2 baboon
// add 3 bab
// delete 2
// append b