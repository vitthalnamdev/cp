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
int arr[] = {2, 3, 4};
int sum = 2 + 3 + 4;
int dp[4][sum+5];
for(int i=0;i<=sum;i++){
    dp[0][i] = i*(sum-i);
}
 
for(int i=1;i<=3;i++){
    for(int j=0;j<=sum;j++){
        dp[i][j] = max(dp[i-1][j] , (j+arr[i-1]<=sum?dp[i-1][j+arr[i-1]]:0));
    }
}
for(int i=0;i<=3;i++){
    for(int j=0;j<=sum;j++){
        cout<<dp[i][j]<<" ";
    }cout<<endl;
}
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}