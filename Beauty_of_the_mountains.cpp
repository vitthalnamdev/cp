#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
void solve(){
 int n,m,k;cin>>n>>m>>k;
 ll arr[n][m];
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];
    }
 }
 vector<string>check(n);
 for(int i=0;i<n;i++){cin>>check[i];}
 ll fst = 0,scd = 0;
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(check[i][j]=='1'){
            fst+=(arr[i][j]);
        }else scd+=(arr[i][j]);
    }
 }  
  ll diff = scd - fst;int ans = 0;
  int hcf = 0;
   bool f=0;
   if(diff==0){
      cout<<"YES"<<endl;return;
   }
  int p1 =0;int p2 =0;
  while(p1+k-1<n){
     if(p2==0){
      ans=0;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(check[p1+i][j]=='1')ans++;
            }
        }
        p2 = k;
     }else{
        for(int i=0;i<k;i++){
            if(check[p1+i][p2-k]=='1'){ans--;}
            
        }
        for(int i=0;i<k;i++){
           if(check[p1+i][p2]=='1')ans++;
        }
        p2++;
     }

     int ans2 = k*k-2*ans;
     if(p2>m-1){
        p2=0;p1++;
     }
      hcf = __gcd(hcf,ans2);
  }
  
  if(hcf!=0 && (diff%hcf)==0){f=1;}
  if(f){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}