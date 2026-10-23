#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {

	#define int long long
	int n, s;
	cin >> n >> s;
	int m = (s - n)*2;

	int t[n];
	for(int i = 0; i<n; i++)
	{
		cin >> t[i];
		t[i] *= 30;
	}
	sort(t, t+n);


	priority_queue <pair<int, int>> pq;
	for(int i = n-1; i>=0; i--)
	{
		if(i == n-1 || i == n-2)
		{
			pq.push({t[i]*10/6, 1});
		}
		else {
			pq.push({t[i]*10/3, 0});
		}
	}

	pair<int, int> ans = {-1, -1};

	while(m--)
	{
		pair<int, int> current = pq.top();
		pq.pop();

		if(current.second == 2)
		{
			ans = current;
			break;
		}
		if(current.second == 1)
		{
			pq.push({current.first * 6 / 10, 2});
		}
		else {
			pq.push({current.first / 2, 1});
		}
	}

	if(ans.first == -1) ans = pq.top();

	long double ansnum = ans.first;
	ansnum /= 30;
	/*if(ans.second == 1)
	{
		ansnum *= 10;
		ansnum *= 6;
	}
	if(ans.second == 2)
	{
		ansnum *= 10;
		ansnum *= 3;
	}
	ansnum /= 30;

	if(ans.second == 1)
	{
		ansnum *= 10;
		ansnum *= 6;
	}
	if(ans.second == 2)
	{
		ansnum *= 10;
		ansnum *= 3;
	}*/

	cout << setprecision(9) << ansnum;
}
