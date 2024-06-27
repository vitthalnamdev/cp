#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
void solve(){
int a, b;cin>>a>>b;
int x,y;cin>>x>>y;
if(b>=a && y<=x || (a>=b && x<=y)){
    cout<<"NO"<<endl;
}else{
    cout<<"YES"<<endl;
}
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}