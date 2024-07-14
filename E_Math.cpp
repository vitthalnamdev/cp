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
    int n;
    cin >> n;
    int mx = 0;
    int ans = 1;
    set<int> check;
    for (int i = 2; i <= sqrt(n); i++)
    {
        int cnt = 0;
        while (n % i == 0)
        {
            n /= i;
            cnt++;
        }
        if (cnt > 0)
        {
            a   ns *= i;
            mx = max(mx, cnt); 
            check.insert(cnt);
        }
    }
    if (n > 1)
    {
        ans *= n;
        mx = max(mx, 1);
        check.insert(1);
    } 
    ll result = check.size() > 1 ? 1 : 0;
    
    for (int i = 31; i >= 0; i--)
    {
        int now = ((1 << i) ^ mx);
        int now2 = ((1 << i) & mx);
        if (now == 0)
        {  
            result += i;break;
        }
        else if (now2)
        {
            result = i + 2;break;
        }
    }

    cout << ans << " " << result;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    while (t--)
    {
        solve();
    }
}