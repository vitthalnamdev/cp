/**
 *    author:  tourist
 *    created: 30.06.2024 17:40:59
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> nxt(n + 1);
    nxt[n] = n;
    for (int i = n - 1; i >= 0; i--) {
      if (i < n - 1 && a[i + 1] != a[i]) {
        nxt[i] = i + 1;
      } else {
        nxt[i] = nxt[i + 1];
      }
    }
    const int inf = int(1e9);
    vector<vector<int>> f(n + 1, vector<int>(n + 1, inf));
    for (int j = 0; j <= n; j++) {
      f[n][j] = 0;
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j <= n; j++) {
        f[i][j] = f[nxt[i]][min(n, j + 1)] + 1;
        
        if (j > 0) {
          f[i][j] = min(f[i][j], f[i + 1][j - 1]);
        }
      }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<f[i][j]<<" ";
        }cout<<endl;
    }
    cout << f[0][0] << '\n';
  }
  return 0;
}
