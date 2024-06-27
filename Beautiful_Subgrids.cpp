 #include<bits/stdc++.h>
 using namespace std;
   #define ll long long 
 //(popcount) in the below gcc target.
 #pragma GCC target("popcount")
 #define cntone(x) __builtin_popcountll(x)
 #define trailzero(x) __builtin_clzll(x)
 #define trailone(x) __builtin_ctzll(x)
 void solve(){
 int n;cin>>n;
vector<bitset<3001>>vec(n+1);
for(int i=1;i<=n;i++){
 cin>>vec[i];
}
ll ans = 0;
for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      ll now = (vec[i]&vec[j]).count();
      ans+=(now*(now-1)/2);
    }
}
cout<<ans<<endl;
 }
 int main(){
 std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
 int t;cin>>t;
 while(t--){
 solve();
 }
 }