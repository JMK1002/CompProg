//
// Created by JMKov on 4/20/2023.
//
#include <bits/stdc++.h>
using namespace std;
int a[1000010], res;

int main()
{
    int n; cin >> n;
    for( int i = 0; i < n; i ++ ) cin >> a[i];
    for( int i = 1; i < n; i ++ )
    {
        if( a[i] != 0 && a[i] != 3 && a[i] == a[i-1] ) a[i] = 0;
        if( a[i] == 3 && a[i-1] != 0 && a[i-1] != 3 ) a[i] = 3-a[i-1];
    }
    for( int i = 0; i < n; i ++ )
        if( !a[i] ) res ++;
    cout << res << '\n';
    return 0;
}