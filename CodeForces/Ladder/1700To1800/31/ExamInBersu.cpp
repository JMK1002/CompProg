#include <bits/stdc++.h>
using namespace std;

int n, m, a[200005];

void solve(){
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        while(sum > m || (pq.size() && pq2.size() && pq.top() > pq2.top())){
            sum -= pq.top();
            pq2.push(pq.top());
            pq.pop();
        }
        while(pq2.size() && sum + pq2.top() <= m){
            sum += pq2.top();
            pq.push(pq2.top());
            pq2.pop();
        }
        cout<<pq2.size()<<" ";
        pq.push(a[i]);
    }
}

int main() {
// 	int t;cin>>t;while(t--)
    solve();
}