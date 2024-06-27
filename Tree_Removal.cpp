 #include<bits/stdc++.h>
 using namespace std;
   #define ll long long 
 //(popcount) in the below gcc target.
 //#pragma GCC target()
 #define cntone(x) __builtin_popcountll(x)
 #define trailzero(x) __builtin_clzll(x)
 #define trailone(x) __builtin_ctzll(x)
 void dfs(int node , vector<int>adj[] , int vis[] , vector<int>&ans){
    vis[node] = 1;

   for(auto i:adj[node]){
    if(!vis[i])
    dfs(i, adj, vis, ans);
   }


    ans.push_back(node);
 }
 void solve(){
 int n;cin>>n;
 int arr[n];
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
  vector<int>adj[n];
  for(int i=1;i<n;i++){
       int a, b;cin>>a>>b;
       a--;b--;
       adj[a].push_back(b);
       adj[b].push_back(a);

  }
  int mn = INT_MAX;int ind = -1;
  for(int i=0;i<n;i++){
     if(arr[i]<mn){
        mn= arr[i];ind = i;
     }
  }
  vector<int>ans;
  int vis[n];
  for(int i=0;i<n;i++){vis[i]=0;}
   
  dfs(ind, adj , vis , ans);
  ans.pop_back();
  cout<<ans.size()<<endl;
  for(auto i:ans)cout<<i+1<<" ";cout<<endl;
 }
 int main(){
 std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
 int t;cin>>t;
 while(t--){
 solve();
 }
 }