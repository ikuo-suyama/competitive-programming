#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc147/abc147_c.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  vector<vector<P>> a(N, vector<P>(0));
  rep(i, N) {
    int A;
    cin >> A;
    rep(j, A) {
      int x, y;
      cin >> x >> y;
      x--;
      a[i].push_back(make_pair(x, y));
    }
  }

  int ans = 0;
  for (int i = pow(2, N) - 1; i >= 0; i--) {
    bool ok = true;
    vector<int> c(N);
    rep(j, N) { c[j] = (i & (1 << j)) ? 1 : 0; }
    rep(j, N) {
      if (c[j]) {
        rep(l, a[j].size()) {
          int x = a[j][l].first;
          int y = a[j][l].second;
          if (c[x] != y) {
            // 矛盾がある発言が見つかった
            ok = false;
            break;
          }
        }
      }
    }
    if (ok) {
      int tmp = 0;
      rep(j, N) { tmp += (i & (1 << j)) ? 1 : 0; }
      ans = max(ans, tmp);
    }
  }

  cout << ans << endl;
}