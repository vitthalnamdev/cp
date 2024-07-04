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
    int n,t;
    double p;
    cin>>n>>p>>t;
    double s[n+1][t+1], f[n+1][t+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=t;j++){
        s[i][j]=1;
        f[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
    for(int j=i;j<=t;j++){
        s[i][j] = s[i-1][j-1]*p + f[i][j-1]*(p);
        f[i][j] = f[i][j-1]*(1-p) + s[i-1][j-1]*(1-p); 
    }
    }
    double ans = 0;
    for(int i=1;i<=min(n,t);i++){
        ans+=(s[i][t]);
    }
    //cout<<setprecision(10)<<fixed;
    cout<<ans<<endl;
    }
    int main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int t=1;
    while(t--){
    solve();
    }
    }