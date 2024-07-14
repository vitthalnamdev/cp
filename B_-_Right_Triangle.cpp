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
vector<pair<double,double>>arr(3);
for(int i=0;i<3;i++){
    cin>>arr[i].first>>arr[i].second;
}
double check[3];
check[0] = (pow(arr[1].second-arr[0].second,2) +pow(arr[1].first-arr[0].first,2)); 
check[1] = (pow(arr[1].second-arr[2].second,2) +pow(arr[1].first-arr[2].first,2));
check[2] = (pow(arr[2].second-arr[0].second,2) +pow(arr[2].first-arr[0].first,2));
sort(check,check+3);
if(check[0] + check[1] ==check[2]){
    cout<<"Yes"<<endl;
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