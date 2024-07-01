#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
int mod = 1e9+7;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve(){
      ll n;
        cin >> n;
        int dp[n+1][n+1];
        int cnt[n+1];
        for(int i = 0; i <= n; i++) 
            fill_n(dp[i], n + 1, -1);
        fill_n(cnt, n + 1, 0ll);
 
        for(int i = 0; i < n ;i++) { 
            ll x;
            cin >> x;
            cnt[x]++; 
        }

        dp[0][0] = 0;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 0; j <= n; j++) {
                dp[i][j] = dp[i-1][j];
                if (cnt[i] && j > 0) {
                    dp[i][j] = dp[i-1][j-1];
                }
                if (j >= cnt[i] && dp[i-1][j-cnt[i]] != -1) {
                    if (dp[i][j] == -1 || dp[i-1][j-cnt[i]] + cnt[i] < dp[i][j]) {
                        dp[i][j] = dp[i-1][j-cnt[i]] + cnt[i];
                    }
                }
            }
        }
        ll ans = n;
        for (ll i = n; i >= 0; i--) {
            if (dp[n][i] != -1) {
                ans = i;    break;
            }
        }
        cout << ans <<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}