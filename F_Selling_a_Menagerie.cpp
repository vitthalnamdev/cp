#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
template<typename T>
void printvec(vector<T>arr){
  for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
  }cout<<endl;
}


int mod = 1e9+7;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
set<pair<int,int>>result;
vector<int>result2;
bool dfs(int node , vector<int>&vis1 , vector<int>&vis2 , vector<int>&ans , vector<int>adj[] , int coins[]){
   vis1[node] = 1;
   vis2[node] = 1;
   bool check = 0;
   for(auto i:adj[node]){
      if(!vis1[i]){
        check |= dfs(i , vis1 , vis2 , ans , adj , coins );
       
      }else if(vis1[i] && vis2[i]){
         check = true;
         result.insert({coins[i] , i});
         result2.push_back(i);
      }
   }
   if(check==false){
     ans.push_back(node);
   }else if(result.find(make_pair(coins[node] , node))==result.end()){
     result.insert({coins[node], node});
     result2.push_back(node);
   }else{
     auto now = *result.begin();
     vector<int>newans;
     vector<int>nowans;
     while(result2.size()>0){
        if(result2.back()==now.second){
            while(nowans.size()>0){
               ans.push_back(nowans.back());
               nowans.pop_back();
            }
        }
        nowans.push_back(result2.back());
        result2.pop_back();
     }
    while(nowans.size()>0){
               ans.push_back(nowans.back());
               nowans.pop_back();
    }result2.clear();
     result.clear();  
     check = 0;
   }
   vis2[node] = 0;
   return check;
}

void solve(){
 int n;cin>>n;
 int arr[n+1];
 for(int i=1;i<=n;i++)cin>>arr[i];
 int coins[n+1];
 for(int i=1;i<=n;i++)cin>>coins[i];
 vector<int>adj[n+1];
 for(int i=1;i<=n;i++){
    adj[arr[i]].push_back(i);
 }
 vector<int>vis1(n+1,0);
 vector<int>vis2(n+1,0);
 vector<int>ans;
 for(int i=1;i<=n;i++){
    if(!vis1[i]){
        dfs(i , vis1 , vis2 , ans , adj , coins);
    }
 }
 for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
 }cout<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}