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
int n;cin>>n;
ll arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
ll mx = 0;
ll prevmx = arr[0];
vector<ll>check;
for(int i=1;i<n;i++){
   ll curr = (prevmx - arr[i]);
   if(curr>0){
     check.push_back(curr);
   }
   prevmx = max(prevmx, arr[i]);
}
sort(check.begin(),check.end());
ll prevsum = 0;
 for(int i=0;i<check.size();i++){
    check[i]-=prevsum;
    check[i] = max(check[i],(ll)0);
    mx+=(check[i]*(check.size()-i+1));
    prevsum+=(check[i]);
 }
 cout<<mx<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}