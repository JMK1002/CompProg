#include<iostream>
#define ll long long
using namespace std;
const int N = 200005;
int a[N], n;
ll sum,ans;
int main()
{
    cin >> n;
    for (int i = 0; i < n;i&1?1: sum += a[i], i++)cin >> a[i];
    for (int i = 0; i < n*2; i+=2)	ans = max(ans, sum = sum + a[(i + 1) % n] - a[i % n]);
    cout << ans;
}