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
void solve(){
 int n;cin>>n;
 int arr[n], brr[n];
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 for(int i=0;i<n;i++){
    cin>>brr[i];
 }
 int a=0, b=0;
 int cn=0,cp=0;
 for(int i=0;i<n;i++){
    if(arr[i]==-1 && brr[i]==-1){
         cn++;
    }else if(arr[i]==1 && brr[i]==1){
        cp++;
    }else if(arr[i]==1){
        a++;
    }else if(brr[i]==1){
        b++;
    }
 }
    
   int Arr[2] = {a, b};
   sort(Arr,Arr+2);
   int prev = Arr[0];   
   Arr[0]+=(min(Arr[1]-Arr[0] , cp));
   cp -=min(cp,(Arr[0]-prev));
   
   Arr[0]+=(cp/2 + cp%2);Arr[1]+=(cp/2);
   sort(Arr,Arr+2);
   prev = Arr[1];
    Arr[1]-=(min(Arr[1]-Arr[0] , cn));
   cn -=min(cn,(prev - Arr[1]));
   Arr[0] -= (cn/2);
   Arr[1] -= (cn/2+cn%2);
   sort(Arr,Arr+2);
   cout<<Arr[0]<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}