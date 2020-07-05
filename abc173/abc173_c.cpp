#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc173/abc173_c.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;
#else
#define INPUT_FILE
#define print_vec(v)
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
typedef pair<ll, ll> pl;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int H, W, K;
  cin >> H >> W >> K;

  vector<vector<char>> c(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) { cin >> c[i][j]; }
  }

  ll ans = 0;
  rep(i, pow(2, H)) {
    vector<vector<char>> tmp(c);
    // 行の塗りつぶし
    rep(j, H) {
      if (i & (1 << j)) {
        rep(l, W) { tmp[j][l] = ' '; }
      }
    }

    // 列の塗りつぶし
    rep(j, pow(2, W)) {
      vector<vector<char>> tmptmp(tmp);
      rep(l, W) {
        if (j & (1 << l)) {
          rep(k, H) { tmptmp[k][l] = ' '; }
        }
      }

      // 数え上げ
      int cnt = 0;
      rep(j, H) rep(k, W) {
        if (tmptmp[j][k] == '#') {
          cnt++;
        }
      }
      if (cnt == K) ans++;
    }
  }
  cout << ans << endl;
}