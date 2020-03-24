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

int H, W, K;
int countSplit(int s, int h, const vector<vector<int>> &c) {
  printf("    sp s:%d h:%d\n", s, h);
 
  int ans = 0;
  int cnt_tot = 0;
  rep(j, W) {
    int cnt_line = 0;
    repi(i, s, h) { cnt_line += c[i][j]; }
    if (cnt_line > K) {
      // 分割不可
      return -1;
    }
    if (cnt_tot + cnt_line > K) {
      printf("    --split! j:%d, tot:%d line:%d\n", j, cnt_tot, cnt_line);
      ans += 1;
      cnt_tot = cnt_line;
    } else {
      cnt_tot += cnt_line;
    }
  }
  return ans;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> H >> W >> K;

  vector<vector<int>> c(H, vector<int>(W));
  rep(i, H) {
    string s;
    cin >> s;
    rep(j, W) { c[i][j] = s[j] - '0'; }
  }

  int ans = INF;
  rep(i, pow(2, H - 1)) {
    printf("-- i:%d\n", i);
    vector<int> h(1, 0);
    rep(j, H) {
      if (i & (1 << j)) {
        h.push_back(j + 1);
      }
    }
    h.push_back(H);
    int ans_h = 0;
    rep(j, h.size() - 1) {
      // TODO: 列毎にスプリットするかどうかを決める必要がある
      printf("  %d to %d - cnt:%d\n", h[j], h[j + 1], countSplit(h[j], h[j + 1], c));
      int tmp = countSplit(h[j], h[j + 1], c);
      if (tmp < 0) {
        ans_h = -1;
        break;
      }
      ans_h = max(ans_h, tmp);
    }
    printf("-- ans_h:%d + %d\n", ans_h, (int)h.size() - 2);
    if (ans_h == -1) continue;
    ans = min(ans, ans_h + (int)h.size() - 2);
  }

  cout << ans << endl;
}