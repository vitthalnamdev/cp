#include<iostream>
#include<vector>

using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
int mod = 1e9+7;
// ll inv(ll a) {
// return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
// }
// #define cntone(x) __builtin_popcountll(x)
// #define trailzero(x) __builtin_clzll(x)
// #define trailone(x) __builtin_ctzll(x)
void solve(){
    int n,m;cin>>n>>m;
    vector<string>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
  vector<vector<int>>pref(n+1,vector<int>(m+1,0));
    for( int i = 0; i< n;i ++ ){
        for(int j=0 ;j<m;j++){
           pref[i+1][j+1] = pref[i][j+1] + pref[i+1][j] - pref[i][j] + (arr[i][j]=='1');
        }
    }
    auto findones = [&](int r1 , int c1 , int r2 , int c2 ){
         return pref[r2+1][c2+1] - pref[r1][c2+1] - pref[r2+1][c1] + pref[r1][c1];
    };  
    auto getzeroes = [&](int r1 , int c1 , int r2 , int c2 ){
        int curr =  findones(r1,c1,r2,c2);
        return (r2-r1+1)*(c2-c1+1) - curr;
    };
    int answer = n*m;
    
    for(int r1=0;r1<n;r1++){
        for(int r2 = r1 + 4 ; r2 < n;r2++){
            for(int c1 = 0;c1 < m;c1++){
                for(int c2 = c1 + 3;c2 < m;c2++){
                     int curr = findones(r1+1, c1+1 , r2-1 , c2-1);     
                     curr+=(getzeroes(  r1+1 , c2 , r2 - 1 , c2));
                     curr+=(getzeroes(  r1+1 , c1 , r2 - 1 , c1));
                     curr+=(getzeroes(r1 , c1+1 , r1 , c2 - 1));
                     curr+=(getzeroes(r2 , c1+1 , r2 , c2 - 1));
                     if(curr< answer){
                       answer = curr;
                     }
                     
                }
            }
        }
    }
     printf("%d\n" , answer);
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}