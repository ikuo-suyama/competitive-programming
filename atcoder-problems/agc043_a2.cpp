#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                               \
  ifstream in("atcoder-problems/agc043_a.txt"); \
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

int dp[110][110];

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int H, W;
  cin >> H >> W;

  memset(dp, INF, 110 * 110 * sizeof(int));

  vector<string> s(H);
  rep(i, H) { cin >> s[i]; }

  dp[0][0] = s[0][0] == '#' ? 1 : 0;
  rep(h, H) rep(w, W) {
    rep(k, 2) {
      int nh = h + (k % 2);
      int nw = w + ((k + 1) % 2);
      if (nh >= H || nw >= W) continue;

      int cnt = s[h][w] == '.' && s[nh][nw] == '#';
      dp[nh][nw] = min(dp[nh][nw], dp[h][w] + cnt);
    }
  }

  cout << dp[H - 1][W - 1] << endl;
}