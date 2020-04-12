#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc162/abc162_d.txt"); \
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

bool isIJK(vector<vector<int>> &c, int target) {
  int id = lower_bound(c[2].begin(), c[2].end(), target) - c[2].begin();
  if (id < 0 || id >= c[2].size()) return false;
  return c[2][id] == target;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  vector<vector<int>> c(3, vector<int>(0));
  rep(i, N) {
    char s;
    cin >> s;
    int t = 0;
    if (s == 'R') {
      t = 0;
    } else if (s == 'G') {
      t = 1;
    } else if (s == 'B') {
      t = 2;
    }
    c[t].push_back(i);
  }

  ll ans = c[0].size() * c[1].size() * c[2].size();
  if (ans == 0) {
    cout << ans << endl;
    return 0;
  }
  for (int i : c[0]) {
    for (int j : c[1]) {
      int diff = abs(i - j);
      int mi = min(i, j);
      int ma = max(i, j);
      if (mi > diff) {
        if (isIJK(c, mi - diff)) ans--;
      }
      if (isIJK(c, ma + diff)) ans--;
      if (diff % 2 == 0) {
        if (isIJK(c, ma - diff / 2)) ans--;
      }
    }
  }

  cout << ans << endl;
}