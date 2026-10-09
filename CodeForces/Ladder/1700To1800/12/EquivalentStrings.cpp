#include <bits/stdc++.h>

#define MM_Taha ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;

string solve(string s) {
    if (s.size() % 2 == 1) {
        return s;
    }
    string s1, s2;
    s1 = solve(s.substr(0, s.size() / 2));
    s2 = solve(s.substr(s.size() / 2));
    if (s1 < s2)
        return s1 + s2;
    else
        return s2 + s1;
}

int main() {

    MM_Taha;
    string a, b;`
    cin >> a >> b;
    if (solve(a) == solve(b))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
	 	 	  		 	 		 				  	      		