#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
void solve(){
ll x,y,k;cin>>x>>y>>k;
 while(x>1){
     ll rem = y - x%y;
     x = x + min(k,rem);
     k = max((ll)0,k-rem);
      while(x>1 && x%y==0){
           x/=y;
     }
     if(k==0){
        break;
     }
 }
 int left = k % (y-1);
cout<<x + left<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}