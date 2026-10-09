#include<bits/stdc++.h>
using namespace std; long long t, n, i, j, l, r, m, c;
int main(){
    for (cin >> t; t--; cout << c << "\n"){
        cin >> n; vector<int> a(n), b(n), s;
        for (i = 0; i < n; i++) cin >> a[i];
        for (i = c = 0; i < n; s.push_back(i++)){ cin >> b[i];
            while (s.size() && a[s.back()] < a[i]) s.pop_back();
            if (b[i] == a[i]) c += (i + 1) * (n - i);
            else if (s.size()){
                l = 0, r = s.size() - 1, j = -1;
                while (l <= r) m = (l + r) / 2, (a[s[m]] >= b[i] ? j = s[m], l = m + 1 : r = m - 1);
                c += (j + 1) * (n - i);
            }
        }
    }
}