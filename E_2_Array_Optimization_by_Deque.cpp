#include <iostream> 
using namespace std; 
#define ll long long 
// Header files, namespaces, 
// macros as defined above 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> 


int main(){
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ordered_set s;ll ans = 0;
        map<ll,ll>cnt;
        for(int i=0;i<n;i++){
            ll sz = s.size();
            ll ind = s.order_of_key(arr[i]);
             
            ll temp = min(ind , sz-ind - cnt[arr[i]]);
            cnt[arr[i]]++;
            ans+=temp;
            s.insert(arr[i]);
        }
        cout<<ans<<endl;
    }
}