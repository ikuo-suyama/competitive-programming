#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc096_c.txt"); \
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

  bool ok = true;
  rep(i, H) rep(j, W) {
    if (s[i][j] == '#') {
      char t = i > 0 ? s[i - 1][j] : '-';
      char b = i < H - 1 ? s[i + 1][j] : '-';
      char l = j > 0 ? s[i][j - 1] : '-';
      char r = j < W - 1 ? s[i][j + 1] : '-';
      if (t != '#' && b != '#' && l != '#' && r != '#') {
        ok = false;
        break;
      }
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
}