#include <bits/stdc++.h>
#define rr read()
#define ll long long
using namespace std;
set<int>s1,s2;
multiset<int>vs1,vs2;
int read()
{
    char ch=getchar(); int x=0,f=0;
    while (ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
    while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return f? -x:x;
}

int main()
{
    int w=rr,h=rr,n=rr;
    s1.insert(0); s1.insert(h);
    s2.insert(0); s2.insert(w);
    vs1.insert(h); vs2.insert(w);
    for (int i=0;i<n;++i)
    {
        char c;
        cin>>c;
        if (c=='H'){
            int y=rr;
            s1.insert(y);
            auto l=s1.find(y);
            auto r=l;
            --l; ++r;
            auto t=vs1.find(*r-*l);
            vs1.erase(t);
            vs1.insert(y-*l);
            vs1.insert(*r-y);
        }
        else{
            int x=rr;
            s2.insert(x);
            auto l=s2.find(x);
            auto r=l;
            --l; ++r;
            auto t=vs2.find(*r-*l);
            vs2.erase(t);
            vs2.insert(x-*l);
            vs2.insert(*r-x);
        }
        printf("%lld\n",(ll)(*vs1.rbegin())*(ll)(*vs2.rbegin()));
    }
    return 0;
}
 