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
    int n, l, k;
    cin >> n >> l >> k;
    int cordinate[n + 1], speed[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> cordinate[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> speed[i];
    }
    pair<ll, ll> dp[n + 1][k + 1];
    cordinate[n] = l;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = {INT_MAX , INT_MAX};
    
    dp[0][0].first = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1][0] = {dp[i][0].first + speed[i] * (cordinate[i + 1] - cordinate[i]), speed[i]};
    }
    
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(j<i){dp[j][i] = dp[j][i-1];}
            dp[j + 1][i] = mini({dp[j][i].first + (cordinate[j + 1] - cordinate[j]) * speed[j], speed[j]},
                                {dp[j][i - 1].first + (cordinate[j + 1] - cordinate[j]) * dp[j][i - 1].second, dp[j][i - 1].second});
        }
    }

    cout << dp[n][k].first << endl;
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