#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> ans;

int main()
{
    int t;
    int n, k;
    string s, r;
    int i, j;

    cin >> t;
    while(t --)
    {
        cin >> n >> k;
        cin >> s;

        for(i = 1, r.clear(); i < k; i ++)
            r += "()";
        for(i = 0; (i + k) * 2 <= n; i ++)
            r += '(';
        for(i = 0; (i + k) * 2 <= n; i ++)
            r += ')';

        for(i = 0, ans.clear(); i < n; i ++)
        {
            if(s[i] == r[i])
                continue;
            for(j = i; s[j] != r[i]; j ++)
                ;
            ans.push_back(make_pair(i + 1, j + 1));
            swap(s[i], s[j]);
        }

        cout << ans.size() << endl;
        for(auto &x : ans)
            cout << x.first << ' ' << x.second << endl;
    }

    return 0;
}