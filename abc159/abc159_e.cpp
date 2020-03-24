#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc159/abc159_e.txt"); \
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

  int H, W, K;
  cin >> H >> W >> K;

  vector<vector<int>> c(H, vector<int>(W));
  rep(i, H) {
    string s;
    cin >> s;
    rep(j, W) { c[i][j] = s[j] - '0'; }
  }

  // rep(i, pow(2, H - 1)) {
  // }

  int ans = 0;
  int cnt_tot = 0;
  rep(j, W) {
    int cnt_line = 0;
    rep(i, H) { cnt_line += c[i][j]; }

    if (cnt_tot + cnt_line > K) {
      ans += 1;
      cnt_tot = cnt_line;
    } else {
      cnt_tot += cnt_line;
    }
  }

  cout << ans << endl;
}