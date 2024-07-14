#include <bits/stdc++.h>
using namespace std;
#define ll long long
//(popcount) in the below GCC target.
// #pragma GCC target()
int mod = 1e9 + 7;
ll inv(ll a)
{
    return a <= 1 ? a : mod - (long long)(mod / a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve()
{
    int n, ans = 0;
    string a, b;
    cin >> n >> a >> b;
    bool f = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > b[i])
            f = 1;
    if (f)
    {   
        cout << "-1\n"; 
        return;
    }
    for (char j = 'b'; j <= 't'; j++)
    {
        map<char, int> count;
        for (int i = 0; i < n; i++)
            if (a[i] != b[i] && b[i] == j)
            count[a[i]] = 1;
        ans += count.size();
        for (int i = 0; i < n; i++) 
            if (count[a[i]])
                a[i] = j;
        if(j=='b'){
            cout<<ans<<endl;
        }
    }
    cout << ans <<endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}