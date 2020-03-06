#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                      \
  ifstream in("loadtolb/abc128_c.txt"); \
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

/**
 * bit全探索
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, M;
  cin >> N >> M;

  vector<vector<int>> c(M, vector<int>());
  rep(i, M) {
    int k;
    cin >> k;
    rep(j, k) {
      int l;
      cin >> l;
      l--;
      c[i].push_back(l);
    }
  }
  vector<int> p(M);
  rep(i, M) { cin >> p[i]; }

  ll ans = 0;
  rep(i, pow(2, N)) {
    // printf("%d--\n", i);
    int totOn = 0;
    rep(j, M) {
      int cntOn = 0;
      for (auto l : c[j]) {
        // printf("  l:%d, %d, %d\n", l, (1 << l), i & (1 << l));
        cntOn += ((i & 1 << l) != 0);
      }
      if (cntOn % 2 == p[j]) totOn++;
    }
    if (totOn == M) ans++;
  }

  cout << ans << endl;
}