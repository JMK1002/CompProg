#include "bits/stdc++.h"
#define int long long

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[ ";
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    os << "]";
    return os;
}

using namespace std;

int getAns(int& k, multiset<int>& ms) { return k - (*ms.rbegin()); }
struct SegTree {
    int n;
    vector<int> tree, setLazy, begin, end;
    void prop(int i) {
        if (setLazy[i] != -100) {
            setLazy[2 * i + 1] = setLazy[2 * i] = setLazy[i];
            tree[2 * i] = tree[2 * i + 1] =
                setLazy[i] * (end[2 * i + 1] - begin[2 * i + 1] + 1);
            setLazy[i] = -100;
        }
    }
    SegTree(int nn) {
        n = 1;
        while (n < nn) n *= 2;
        tree.resize(2 * n);
        setLazy.resize(2 * n, -100);
        begin.resize(2 * n);
        end.resize(2 * n);
        for (int i = n; i < 2 * n; i++) {
            begin[i] = end[i] = i - n;
        }
        for (int i = n - 1; i > 0; i--) {
            begin[i] = begin[2 * i];
            end[i] = end[2 * i + 1];
        }
    }
    void rangeSet(int i, int amt, int lo, int hi) {
        if (i < n) prop(i);
        if (begin[i] == lo && end[i] == hi) {
            tree[i] = amt * (hi - lo + 1);
            setLazy[i] = amt;
            return;
        }
        if (begin[2 * i] <= hi && end[2 * i] >= lo) {
            rangeSet(2 * i, amt, lo, min(hi, end[2 * i]));
        }
        if (begin[2 * i + 1] <= hi && end[2 * i + 1] >= lo) {
            rangeSet(2 * i + 1, amt, max(lo, begin[2 * i + 1]), hi);
        }
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    int query(int i, int lo, int hi) {
        if (i < n) prop(i);
        if (begin[i] == lo && end[i] == hi) return tree[i];
        int ans = 0;
        if (begin[2 * i] <= hi && end[2 * i] >= lo) {
            ans += query(2 * i, lo, min(end[2 * i], hi));
        }
        if (begin[2 * i + 1] <= hi && end[2 * i + 1] >= lo) {
            ans += query(2 * i + 1, max(lo, begin[2 * i + 1]), hi);
        }
        return ans;
    }
};
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            v[i] = v[i] - i;
        }
        vector<int> ans(n);  // ans[i] is answer from i to i+k-1
        map<int, int> mp;
        multiset<int> active;
        for (int i = 0; i < k; i++) {
            if (mp[v[i]] == 0) {
                mp[v[i]] = 1;
                active.insert(1);
            } else {
                active.erase(active.find(mp[v[i]]));
                mp[v[i]]++;
                active.insert(mp[v[i]]);
            }
        }
        ans[0] = getAns(k, active);
        for (int i = k; i < n; i++) {
            // erase v[i-k]
            active.erase(active.find(mp[v[i - k]]));
            mp[v[i - k]]--;
            if (mp[v[i - k]] != 0) active.insert(mp[v[i - k]]);

            if (mp[v[i]] == 0) {
                mp[v[i]] = 1;
                active.insert(1);
            } else {
                active.erase(active.find(mp[v[i]]));
                mp[v[i]]++;
                active.insert(mp[v[i]]);
            }
            ans[i - k + 1] = getAns(k, active);
        }
        vector<array<int, 3>> queries(q);
        vector<int> an(q);
        for (int i = 0; i < q; i++) {
            queries[i][2] = i;
            cin >> queries[i][0] >> queries[i][1];
            queries[i][0]--;
            queries[i][1]--;
            queries[i][0] *= -1;
        }
        sort(begin(queries), end(queries));
        for (int i = 0; i < q; i++) queries[i][0] *= -1;
        SegTree st(n);
        st.rangeSet(1, ans[n - k], n - k, n - k);
        int cur = n - k;
        stack<pair<int, int>> s;
        s.push({ans[n - k], n - k});
        for (int i = 0; i < q; i++) {
            while (cur != queries[i][0]) {
                cur--;
                int here = cur;
                while (s.size() && s.top().first > ans[cur]) {
                    here = s.top().second;
                    s.pop();
                }
                s.push({ans[cur], here});
                st.rangeSet(1, ans[cur], cur, here);
            }
            an[queries[i][2]] =
                st.query(1, queries[i][0], queries[i][1] - k + 1);
        }
        for (auto x : an) cout << x << endl;
    }
}