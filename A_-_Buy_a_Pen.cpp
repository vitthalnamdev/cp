/*
    Author : Sunny Kumar
    Descr  : Always Ignore
*/

#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;

#define fastio()                           \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);                       \
    std::cout.tie(0)

#define nline \
    std::cout << "\n"
#define YES \
    std::cout << "YES"
#define NO \
    std::cout << "NO"
#define input \
    std::cin >>
#define output \
    std::cout <<

#define _print(vec)      \
    for (auto &ii : vec) \
        cout << ii << " ";

// --------------------------------------------------------------

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define FOR(a, c) for (int a = 0; a < c; a++)
#define FORL(a, b, c) for (int a = b; a <= c; a++)
#define FORR(a, b, c) for (int a = b; a >= c; a--)
#define allass(x) sort(x.begin(), x.end());
#define alldsc(x) sort(x.rbegin(), x.rend());
#define revass(x) reverse(x.begin(), x.end());
#define revdsc(x) reverse(x.rbegin(), x.rend());
#define sum_int(x) accumulate(x.begin(), x.end(), 0)
#define sum_long_long(x) accumulate(x.begin(), x.end(), 0ll)
#define lower__bound(x, val) lower_bound(x.begin(), x.end(), val) - x.begin()
#define upper__bound(x, val) upper_bound(x.begin(), x.end(), val) - x.begin()
#define sqr_veci(x) for_each(x.begin(), x.end(), [](int &n)({ n *= n; }))
#define sqr_vecl(x) for_each(x.begin(), x.end(), [](long long &n)({ n *= n; }))

// --------------------------------------------------------------

typedef unsigned int utt;
typedef unsigned long long ull;
typedef long long ll;
typedef float flt;
typedef long long int lli;
typedef double dd;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// --------------------------------------------------------------

int start_time; // Time Variable

void Start_Time()
{
    start_time = clock();
}

#ifndef EXPERT_JUDGE
#define debug(sunny)                        \
    cerr << "[" << #sunny << "] = " << " "; \
    _display_output(sunny);                 \
    cerr << endl;
#else
#define debug(sunny)
#endif

// --------------------------------------------------------------

void _display_output(int t) { cerr << t; }
void _display_output(long t) { cerr << t; }
void _display_output(ll t) { cerr << t; }
void _display_output(ull t) { cerr << t; }
void _display_output(utt t) { cerr << t; }
void _display_output(lld t) { cerr << t; }
void _display_output(bool t) { cerr << (t ? "true" : "false"); }
void _display_output(flt t) { cerr << t; }
void _display_output(double t) { cerr << t; }
void _display_output(char t) { cerr << t; }
void _display_output(string t) { cerr << t; }

//--------------------------------------------------------------

void End_Time()
{
    int Time_Taken = double(clock() - start_time) / CLOCKS_PER_SEC;
    // cerr << " : [";
    debug(Time_Taken);
    // cerr << "s]";
}

#define power_value(a, b, val) \
    ll res = 1;                \
    while (b--)                \
    {                          \
        res *= a;              \
    }                          \
    val = res;

#define square_root(a, val)    \
    ll root = 1;               \
    while ((root * root) <= a) \
    {                          \
        root++;                \
    }                          \
    val = root - 1;

#define log_base(bs, exp, val) \
    int cnt = 0;               \
    while (exp)                \
    {                          \
        exp /= bs;             \
        cnt++;                 \
    }                          \
    val = cnt - 1;

//--------------------------------------------------------------

template <typename T, typename V>
void _display_output(pair<T, V> p)
{
    cerr << "{";
    _display_output(p.ff);
    cerr << ",";
    _display_output(p.ss);
    cerr << "}";
}
template <typename T>
void _display_output(vector<T> vec)
{
    cerr << "[ ";
    for (T i : vec)
    {
        _display_output(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T, typename V>
void _display_output(vector<pair<T, V>> vec_pair)
{
    cerr << "[ ";
    for (auto i : vec_pair)
    {
        _display_output(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T>
void _display_output(set<T> ordered_set)
{
    cerr << "[ ";
    for (T i : ordered_set)
    {
        _display_output(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T>
void _display_output(unordered_set<T> hash)
{
    cerr << "[ ";
    for (T i : hash)
    {
        _display_output(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T>
void _display_output(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _display_output(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T, typename V>
void _display_output(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _display_output(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T, typename V>
void _display_output(multimap<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _display_output(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T, typename V>
void _display_output(unordered_map<T, V> hash)
{
    cerr << "[ ";
    for (auto i : hash)
    {
        _display_output(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T>
void _display_output(priority_queue<T> heap)
{
    vector<T> heap_vector;
    while (!heap.empty())
    {
        heap_vector.pb(heap.top());
        heap.pop();
    }
    debug(heap_vector);
}
template <typename T>
void _display_output(priority_queue<T, vector<T>, greater<T>> heap)
{
    vector<T> heap_vector;
    while (!heap.empty())
    {
        heap_vector.pb(heap.top());
        heap.pop();
    }
    debug(heap_vector);
}
template <typename T, typename V>
void _display_output(priority_queue<pair<T, V>> heap)
{
    vector<pair<T, V>> heap_vector;
    while (!heap.empty())
    {
        heap_vector.pb({heap.top().ff, heap.top().ss});
        heap.pop();
    }
    debug(heap_vector);
}
template <typename T, typename V>
void _display_output(priority_queue<pair<T, V>, vector<pair<T, V>>, greater<pair<T, V>>> heap)
{
    vector<pair<T, V>> heap_vector;
    while (!heap.empty())
    {
        heap_vector.pb({heap.top().ff, heap.top().ss});
        heap.pop();
    }
    debug(heap_vector);
}
template <typename T>
void _display_output(queue<T> que)
{
    cerr << "[ ";
    while (!que.empty())
    {
        _display_output(que.front());
        que.pop();
        cerr << " ";
    }
    cerr << "]";
}
template <typename T>
void _display_output(stack<T> stck)
{
    cerr << "[ ";
    while (!stck.empty())
    {
        _display_output(stck.top());
        stck.pop();
        cerr << " ";
    }
    cerr << "]";
}

// --------------------------------------------------------------
// Code Start Here

void Sanhayu546__()
{
    int test;
    input test;
    // test = 1;

    while (test--)
    {
        int n;
        input n;

        vl nums(n);
        FOR(i, n)
        input nums[i];

        // Number Of Subsequence which length of that subsequence is equal to Max(ai) - min(ai);

        allass(nums);
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
        output ans;
        nline;
    }
    return;
}

int main()
{
#ifndef EXPERT_JUDGE
    freopen("Output.txt", "w", stderr);
#endif
    fastio();

    Start_Time();

    Sanhayu546__();

    End_Time();
}