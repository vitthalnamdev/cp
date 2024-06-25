#include<bits/stdc++.h>
using namespace std;
#define ll long long
int vis[200005];
int ans[200005];
int arr[200005];
int vis2[200005];
int dist[200005];
int refr = -1;
bool dfs(int node , int prev){
   if(vis2[node]){
      ans[node] = dist[prev] + 1 - dist[node];
      refr = node; 
      return true;  
   }
   if(vis[node]){
       return false;
   }
   vis[node] = 1;vis2[node] = 1;
   dist[node] = dist[prev] + 1;
   bool check = dfs(arr[node], node);
   if(check==true){
      ans[node] = ans[arr[node]];
      if(node==refr){
        check = 0;
      }
   }else{
      ans[node] = ans[arr[node]] + 1;
   }
   vis2[node] = false;
   return check;

} 
void solve(){
int n;cin>>n;
for(int i=1;i<=n;i++){
    cin>>arr[i];
}
for(int i=1;i<=n;i++){
    if(!vis[i]){
        vis[i] = 1;vis2[i]=1;
        bool check = dfs(arr[i],i);
        if(check == false)
        ans[i] = ans[arr[i]] + 1;
        else 
        ans[i] = ans[arr[i]];
        vis2[i] = 0;
        refr = -1;
    }
    
}
 
for(int i=1;i<=n;i++)cout<<ans[i]<<" ";

}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}