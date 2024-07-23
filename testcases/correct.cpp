#include <bits/stdc++.h>
using namespace std;
#define ll long long
//(popcount) in the below GCC target.
// #pragma GCC target()
int mod = 1e9 + 7;
ll inv(ll a)
{
    return a <= 1 ? a : mod - (long long)(mod / a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
pair<ll,ll> mini(pair<ll,ll>a , pair<ll,ll>b){
    if(a.first<b.first){
        return a;
    }else if(a.first>b.first){
        return b;
    }else if(a.second>b.second){
        return b;
    }else{
        return a;
    }
    return {-1,-1};
}
void solve()
{
    ll n, l, k;
    cin >> n >> l >> k;
    ll cordinate[n + 1], speed[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> cordinate[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> speed[i];
    }
    cordinate[n] = l;speed[n] = 0;
    vector<vector<ll>>dp(n+1 , vector<ll>(k+1 , INT_MAX));
    dp[0][0] = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int p = i-1;p>=0;p--){
               int now = j - (i - p - 1);
               if(now>=0  && dp[p][now]!=INT_MAX){
                 dp[i][j] = min(dp[i][j] , dp[p][now] + (cordinate[i] - cordinate[p])*speed[p]);
               }
               
            }
        }
    }
    for(int i=0;i<=k;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[j][i]<<" ";
        }cout<<endl;
    }
    ll ele = *min_element(dp[n].begin(),dp[n].end());
    cout<<ele<<endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;

    while (t--)
    {
        solve();
    }
}