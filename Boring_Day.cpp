#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
void solve(){
  ll n,l,r;cin>>n>>l>>r;
  ll arr[n];
  for(int i=0;i<n;i++)cin>>arr[i];
  int p1=0,p2=0;
  int count = 0;ll check = 0;
  while(p2<n){
    if(check<l){
        check+=(arr[p2++]);
    }
    while(check>r){
        check-=arr[p1++];
    }
    if(check>=l && check<=r){
        count++;check=0;p1 = p2;
    }
  }
  cout<<count<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}