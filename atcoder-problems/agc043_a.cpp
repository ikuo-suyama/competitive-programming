#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
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

int ans = INF;
int H, W;
void dfs(int h, int w, int cnt, bool del, vector<string> &s) {
  if (cnt > ans) return;
  if (h == H - 1 && w == W - 1) {
    if (s[h][w] == '#') {
      cnt += del ? 0 : 1;
    }
    ans = min(ans, cnt);
    return;
  } else if (h >= H || w >= W)
    return;

  if (s[h][w] == '#') {
    cnt += del ? 0 : 1;
    del = true;
  } else {
    del = false;
  }
  dfs(h + 1, w, cnt, del, s);
  dfs(h, w + 1, cnt, del, s);
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> H >> W;

  vector<string> s(H);
  rep(i, H) { cin >> s[i]; }

  dfs(0, 0, 0, false, s);

  cout << ans << endl;
}