#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int long long

const ll N = 2e5 + 7;
const ll mod = 1e9 + 7;
const ll mod1 = 998244353;

int ciel(int a, int b)
{
    return (a / b) + ((a % b) != 0);
}

ll expo(ll x, ll y)
{
    ll res = 1;
    x %= mod;
    while (y)
    {
        if (y % 2)
            res = (res * x % mod) % mod;
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}
ll inv(ll x) { return expo(x, mod - 2); }
ll madd(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}
ll mmul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}
ll msub(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a - b) % mod) + mod) % mod;
}
ll mdiv(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (mmul(a, inv(b)) + mod) % mod;
}
ll power(long long x, unsigned int y, int p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int p = 31;
int hash1(string s)
{
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        ans = madd(ans, mmul((s[i] - 'a' + 1), power(p, i, mod)));
    }
    return ans;
}

vector<int> prefixhash(string s)
{
    vector<int> ans;
    // ans.push_back(0);
    int n = s.size();
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x = madd(x, mmul((s[i] - 'a' + 1), power(p, i, mod)));
        ans.push_back(x);
    }
    return ans;
}
vector<int> prefixhash1(string s)
{
    int n = s.size();
    vector<int> ans(n);
    // ans.push_back(0);
    // int n = s.size();
    int x = 0;
    int j = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        x = madd(x, mmul((s[i] - 'a' + 1), power(p, i, mod)));
        j++;
        ans[i] = x;
    }
    // reverse(ans.begin(),ans.end());
    return ans;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = (s.size());

        vector<int> v = prefixhash(s);
        vector<int> u = prefixhash1(s);
        // for (auto it : u)
        // {
        //     cout << it << " ";
        // }
        // cout << "\n";
        string s1 = "";
        string s2 = "";
        for (int i = 0; i < n; i++)
        {
            if (i < n / 2)
                s1 += s[i];
            else
                s2 += s[i];
        }

        int ans = 0;
        if (s1 == s2)
            ans += 2;
        for (int i = 0; i < n - 2; i++)
        {
            if (i % 2)
            {
                int p = v[i];
                int q = v[i / 2];
                int w = mdiv(msub(p, q), power(31LL, (i + 1) / 2, mod));
                w %= mod;
                // cout << q << " " << w << "\n";
                // if(w==q)
                // {
                // cout << i << "\n";
                // }

                int p1 = u[i + 1];
                int q1 = u[i + 1 + (n - (i + 1)) / 2];
                int w1 = mmul(msub(p1, q1), power(31LL, ((n - (i + 1)) / 2), mod));
                w1 %= mod;
                // cout << w1 << "\n";
                // cout << q1 << "\n";
                // cout << p1 << "\n";
                if (w1 == q1 && w == q)
                {
                    ans++;
                    // cout << i << "\n";
                }
            }
        }
        cout << ans << "\n";
    }
}