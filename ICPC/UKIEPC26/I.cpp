#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long ansa, ansb, anssum = 1e18;
	for(long long a = n+1; a<2*n; a++)
	{
		if(a*n % (a-n) == 0)
		{
			long long b = (a*n)/(a-n);
			if(a + b < anssum)
			{
				anssum = a + b;
				ansa = a; ansb = b;
			}
		}
	}
	cout << ansa << ' ' << ansb;
	return 0;
}
