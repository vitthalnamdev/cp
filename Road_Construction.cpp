#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
class DSU{
  public:
  int n;
  int* parent; int *rank;
  DSU(int sz){
     n= sz;
    parent = new int[100005];
    rank = new int[100005];
    for(int i=1;i<=n;i++)parent[i]=i,rank[i] = 1;
  }
  int find(int a){
     if(parent[a]==a){return a;}
     return find(parent[a]);
  }

  bool merge(int a, int b){
    
     int parenta = find(a);int parentb = find(b);
     if(parenta == parentb){return false;}
     if(rank[parenta]>rank[parentb]){
         rank[parenta]+=(rank[parentb]);
        parent[parentb] = parenta;
     }else if(rank[parentb]> rank[parenta]){
         rank[parentb]+=(rank[parenta]);
        parent[parenta] = parentb;
     }
     else{
        rank[parenta]+=(rank[parentb]);
        parent[parentb] = parenta;
     }
     return true;
  }

};

void solve(){
  int n, m;cin>>n>>m;
  DSU now (n+1);
  int components = n;int mx = 1;
  for(int i=0;i<m;i++){
    int a, b;cin>>a>>b;
    bool check = now.merge(a,b);
    if(check)components--;
    int pra = now.find(a);int prb = now.find(b);
    
    mx = max(mx, max(now.rank[pra],now.rank[prb]));
    cout<<components<<" "<<mx<<endl;
  } 
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}