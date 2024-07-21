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
   int n;
        cin>> n;

        vector<ll> nums(n);
        for(int i=0;i<n;i++)
        cin>> nums[i];

        

        sort(nums.begin(),nums.end());
        unordered_map<ll, ll> prefix, suffix;
        for (int i = 0; i < n; i++)
        {
            if (prefix.find(nums[i] - 1) != prefix.end())
            {
                prefix[nums[i]] = prefix[nums[i] - 1] + 1;
            }
            else
            {
                prefix[nums[i]] = 1;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (suffix.find(nums[i] + 1) != suffix.end())
            {
                suffix[nums[i]] = suffix[nums[i] + 1] + 1;
            }
            else
            {
                suffix[nums[i]] = 1;
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += prefix[nums[i]] * suffix[nums[i] + 2];
        }
        cout<<ans<<endl;
    }
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}