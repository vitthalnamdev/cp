#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
int mod = 1e9 + 9;
int ele = 1e9 + 7;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
ll binpow(ll a, ll b){
    if(b==0){return 1;}
    ll result = 1;
    if(b%2){result = a;}
    ll half = binpow(a,b/2);
    return ((half*half)%mod*result)%mod;
}

bool check(vector<ll>&anshash , int endind , vector<ll>&shash , int start , int n){
    ll end = (shash[n-1] + mod - (start-1>=0?shash[start-1]:0))%mod;
    ll inverse = inv(binpow(ele,start))%mod;
    end = (end*inverse)%mod;
    return anshash[endind]==end;
}



void solve(){
   int n,k;cin>>n>>k;
   string s;cin>>s;
   string ans = "";
   int curr = s[0]-'0';int cnt = 0; 
   for(int i=0;i<n;i++){
     if(cnt==k){
        cnt = 0;curr^=1;
     }
     ans+=('0' + curr);
     cnt++;
  }reverse(ans.begin(),ans.end());
   int result = -1;cnt = 0; 
   vector<ll>anshash(n);
   vector<ll>shash(n);
   for(int i=0;i<n;i++){
     anshash[i] =( (i-1>=0?anshash[i-1]%mod:0) +  (ans[i]-'0'+1)*binpow(ele,i)%mod + mod ) %mod;
   }
   for(int i=0;i<n;i++){
    shash[i] =( (i-1>=0?shash[i-1]%mod:0) +  (s[i]-'0'+1)*binpow(ele,i)%mod + mod ) %mod;
   }
 
   
   for(int i=n-1;i>=0;i--){
     
      if(ans[i]==s[cnt]){
    
         if(i-1>=0 && check(anshash,i-1,shash, cnt+1 , n)){
            result = cnt+1;  
         }else if(i==0){
            result = n;
         }
      }else{
        break;
      }cnt++;
   }

   cout<<result<<endl;
}
 
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}