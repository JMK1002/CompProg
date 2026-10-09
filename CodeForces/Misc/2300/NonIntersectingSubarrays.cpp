#include<bits/stdc++.h>

using namespace std;

#define scl(n) scanf("%lld",&n)
#define ll long long
#define sz 4005
#define pb push_back
#define lim 1e9
#define mp make_pair
#define pll pair<ll,ll>
#define fr first
#define sc second
#define mod 998244353

ll n, k, ans = 0;

ll dp[sz][sz][4];

// ll calc(ll id, ll prev)
// {
//     //cout<<"id: " <<id<< " prev: " <<prev<<endl;
//     if(id > n){
//         return 1;
//     }
//     if(dp[id][prev][0] != -1){
//         return dp[id][prev][0];
//     }

//     if(prev < k){
//         ll a = (calc(id+1, prev+1) * (k-prev)) % mod;
//         dp[id][prev][1] += (dp[id+1][prev+1][1] * (k-prev))%mod;
//         if(prev + 1 == k){
//             dp[id][prev][1] += a;
//             //cout<<id<< " a " <<prev<< "  " <<a<<endl;
//         }

//         ll b = (calc(id+1, 1) * prev) % mod;
//         dp[id][prev][1] += (dp[id+1][1][1] * prev) % mod;
//         dp[id][prev][0] = (a + b) % mod;
//         dp[id][prev][1] %= mod;
//         //cout<<id<< " " <<prev<< " " <<dp[id][prev][1]<<endl;
//     }
//     else{
//         ll a = (calc(id + 1, 1) * k) % mod;
//         //cout<<a<< "  " <<k<<endl;
//         dp[id][prev][1] += (dp[id+1][1][1] * k) % mod;
//         dp[id][prev][0] = a;
//         dp[id][prev][1] %= mod;
//         dp[id][prev][0] %= mod;
//     }
//     //cout<<"ret " << id<< " " <<prev<< " " <<dp[id][prev][0]<<endl;;
//     return dp[id][prev][0];
// }

void calc2()
{
    for(int i = n; i > 0; i--){
        for(int j = 1; j <= k; j++){
            if(i == n){
                dp[i][j][0] = k;
                if(j == k-1){
                    dp[i][j][1] = 1;
                }
                else{
                    dp[i][j][1] = 0;
                }
            }
            else{
                //dp[i][j][0] = dp[i+1][j+1][2] - dp[i+1][0][2];
                if(j == k-1){
                    dp[i][j][1] = dp[i+1][k][0];
                }

                if(j == k){
                    dp[i][j][1] += (dp[i+1][1][1] * k)%mod;
                    dp[i][j][0] = dp[i+1][1][0] * k;
                }
                else{
                    dp[i][j][1] += (dp[i+1][j+1][1] * (k-j)) % mod;
                    dp[i][j][0] += (dp[i+1][j+1][0] * (k-j)) % mod;

                    dp[i][j][1] += (dp[i+1][j][3] - dp[i+1][0][3] + mod);
                    dp[i][j][0] += (dp[i+1][j][2] - dp[i+1][0][2] + mod);
                } 
                dp[i][j][1] %= mod;
                dp[i][j][0] %= mod;
            }
            //cout<<i<< "  " << j<< "  " << dp[i][j][0] << "  " <<dp[i][j][1] << endl; 
        }

        for(int j = 1; j <= k; j++){
            //cout<<dp[i][j][0]  << "   " <<dp[i][j][1] << endl;
            dp[i][j][2] = (dp[i][j-1][2] + dp[i][j][0])%mod;
            dp[i][j][3] = (dp[i][j-1][3] + dp[i][j][1])%mod;
            //cout<<dp[i][j][2] << " " <<dp[i][j][3]<<endl;

        }
    }
}

int main()
{
    scl(n);
    scl(k);

    // for(int i = 0; i <= n; i++){
    //     for(int j =  0; j <= k; j++){
    //         dp[i][j][0] = -1;
    //         dp[i][j][1] = 0;
    //     }
    // }

    calc2();
    cout<<dp[1][k][1] << endl;

}