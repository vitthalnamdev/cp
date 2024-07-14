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
 vector<pair<ll,ll>>arr(n);
 for(int i=0;i<n;i++){
    cin>>arr[i].first>>arr[i].second;
 }
 vector<pair<ll,ll>>temp(n);
 pair<ll,ll>curr={arr[0].first,arr[0].second};
 temp[0] = curr;
 for(int i=1;i<n;i++){
   temp[i].first = arr[i].first+curr.first;
   temp[i].second = arr[i].second+curr.second;
   curr = temp[i];
 }
 if(curr.first<=0 && curr.second>=0){
    cout<<"Yes"<<endl;
    ll sum = 0;
    for(int i=0;i<n-1;i++){
        cout<<arr[i].first<<" ";
        sum+=arr[i].first;
    }
    cout<<-sum<<endl;
 }else{
    cout<<"No"<<endl;
 }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}