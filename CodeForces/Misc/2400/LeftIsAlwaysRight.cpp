#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int mod = 998244353;
void add(int& x, int y){
	x += y;
	if(x >= mod) x -= mod;
}
int binpow(int a, int b){
	if(!b) return 1;
	if(1 & b) return 1ll * a * binpow(a, b - 1) % mod;
	return binpow(1ll * a * a % mod, b >> 1);
}
const int N = 1e5;
int fact[N + 1] = {1}, rev_fact[N + 1];
int C(int n, int k){
	//0 <= k <= n
	if(k < 0 || n < k) return 0;
	return 1ll * fact[n] * rev_fact[n - k] % mod * rev_fact[k] % mod;
}

int n, k, cnt[2], alo[N];
string s;
bool only[2][N + 1];

int calc(int l, bool x){
	if(cnt[0] + cnt[0] >= k) return 0;
	if(cnt[1] + cnt[1] >= k) return 0;
	if(!only[x][l]) return 0;
//	assert(alo[l % (k - 1)] == !x);
	int c = k - 1 >> 1;
	return C(k - 1 - cnt[0] - cnt[1], c - cnt[0]);
}

void solve(){
	cin >> n >> k >> s;
	for(int i = 0; i < k - 1; i++) alo[i] = -1;
	reverse(s.begin(), s.end());
//	cout << s << '\n';
	for(int i = 0; i < k - 1; i++){
		if(s[i] == '?') continue;
		cnt[alo[i] = s[i] - '0']++;
	}
	only[0][n] = only[1][n] = 1;
	for(int i = n; i--;){
		only[0][i] = only[0][i + 1];
		only[1][i] = only[1][i + 1];
		if(s[i] == '0') only[1][i] = 0;
		if(s[i] == '1') only[0][i] = 0;
	}
	int ans = 0;
	for(int x = 0; x < 2; x++){
		if(!only[x][k - 1]) continue;
		for(int c = 0; c < k; c++){
			if(c < cnt[x]) continue;
			if(k - 1 - c < cnt[!x]) continue;
			if(c + c <= k - 1) continue;
			add(ans, C(k - 1 - cnt[0] - cnt[1], c - cnt[x]));
		}
	}
	for(int i = k - 1; i < n; i++){
		for(int x = 0; x < 2; x++){
			if(!only[x][i]) continue;
			if(alo[i % (k - 1)] == x) continue;
			if(alo[i % (k - 1)] == -1){
				cnt[alo[i % (k - 1)] = !x]++;
				add(ans, calc(i, x));
				cnt[!x]--;
				alo[i % (k - 1)] = -1;
			}
			else add(ans, calc(i, x));
		}
		if(i == n) continue;
		if(s[i] == '?') continue;
		if(alo[i % (k - 1)] == !(s[i] - '0')) break;
		if(alo[i % (k - 1)] == s[i] - '0') continue;
		cnt[alo[i % (k - 1)] = s[i] - '0']++;
	}
	bool ok = 1;
	for(int i = 0; i < n; i++){
		if(s[i] == '?') continue;
		ok &= alo[i % (k - 1)] == s[i] - '0';
	}
	if(ok && cnt[0] + cnt[0] < k && cnt[1] + cnt[1] < k){
		int c = k - 1 >> 1;
		add(ans, C(k - 1 - cnt[0] - cnt[1], c - cnt[0]));
	}
	cout << ans << '\n';
	cnt[0] = cnt[1] = 0;
	
}

main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for(int i = 1; i <= N; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
	rev_fact[N] = binpow(fact[N], mod - 2);
	for(int i = N; i; i--) rev_fact[i - 1] = 1ll * rev_fact[i] * i % mod;
	int T = 1;
	cin >> T;
	while(T--) solve();
}
