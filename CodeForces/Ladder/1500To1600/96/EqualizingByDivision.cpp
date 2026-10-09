//
// Created by JMKov on 6/5/2023.
//
#include <iostream>
using namespace std;
int count[200010];
int t[200010];

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        count[arr[i]]++;
        if (count[arr[i]] >= k) {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 0;
    int mn = 2000000000;
    for (int j = 0; j < 21; j++)
    {
        ans++;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0) continue;
            arr[i] /= 2;
            count[arr[i]]++;
            t[arr[i]] += ans;
            if (count[arr[i]] >= k) {
                mn = min(t[arr[i]], mn);
            }
        }
    }
    cout << mn << endl;
    return 0;
}