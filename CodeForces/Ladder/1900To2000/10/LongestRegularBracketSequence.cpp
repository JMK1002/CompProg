// LUOGU_RID: 116629696
#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

string s;
stack<int> stk;
int ed[N];
bool vis[N];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == '(') stk.push(i);
        else
        {
            if (stk.empty()) continue;
            int beg = stk.top();
            stk.pop();
            ed[beg] = i;
        }
    }
    int ans1 = 0, ans2 = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (!ed[i] || vis[i]) continue;
        int j = ed[i] + 1;
        while (ed[j] && j < s.length()) vis[j] = true, j = ed[j] + 1;
        if (j - i > ans1) ans1 = j - i, ans2 = 1;
        else if (j - i == ans1) ans2++;
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}