#include<bits/stdc++.h>
using namespace std;
#define pcount(x) __builtin_popcount(x)
  #define ll long long 
void solve(){
  int n, m;cin>>n>>m;
  int table[n+1][33];
  for(int i=1;i<=n;i++){
    cin>>table[i][0];
  }

  for(int j=1;j<=30;j++){
    for(int i=1;i<=n;i++){
        table[i][j] = table[table[i][j-1]][j-1];
    }
  }
  
  while(m--){
      int j,k;cin>>j>>k;
      for(int l=30;l>=0;l--){
         if(((k) & (1<<l) )){
            j = table[j][l];
         }
      }
    cout<<j<<endl;
  } 
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
 int t = 1;
 while(t--){
solve();
}
}