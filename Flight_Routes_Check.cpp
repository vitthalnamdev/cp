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
 vector<int> adj[100005], adj_rev[100005];
vector<bool> used(100005,0);
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

 void solve(){
      int n;
  cin>>n;int m;cin>>m;
   
    for (int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 1; i <=n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());
    vector<int>ans(n+1,0);
    int cnt = 0;
    for (auto v : order)
        if (v>0 && !used[v]) {
            dfs2 (v);
            if(component.size()>0)
            ans.push_back(component.back());
            cnt++;
            for(auto j:component){
               ans[j]=cnt; 
            }
            component.clear();
             
         
        }
        cout<<cnt<<endl;
         for(int i=1;i<=n;i++){
             cout<<ans[i]<<" ";
         }cout<<endl;
 }
 int main(){
 std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
 int t=1;
 while(t--){
 solve();
 }
 }