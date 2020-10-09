#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc075_b.txt"); \
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

  int H, W;
  cin >> H >> W;

  vector<string> s(H);
  rep(i, H) { cin >> s[i]; }

  rep(h, H) rep(w, W) {
    if (s[h][w] == '#') continue;
    int minH = max(0, h - 1);
    int maxH = min(H - 1, h + 1);
    int minW = max(0, w - 1);
    int maxW = min(W - 1, w + 1);

    int cnt = 0;
    repi(i, minH, maxH + 1) {
      repi(j, minW, maxW + 1) {
        // printf("%d %d %c\n", i, j, s[i][j]);
        cnt += s[i][j] == '#';
      }
    }
    // printf("%d %d %d %d %d\n", minH, maxH, minW, maxW, cnt);
    s[h][w] = '0' + cnt;
  }

  rep(h, H) {
    rep(w, W) { cout << s[h][w]; }
    cout << endl;
  }
}