#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/arc006_1.txt"); \
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

  vector<int> e(6);
  rep(i, 6) { cin >> e[i]; }
  int b;
  cin >> b;
  vector<int> l(6);
  rep(i, 6) { cin >> l[i]; }

  ll cnt = 0;
  ll bcnt = 0;
  rep(i, 6) {
    if (l[i] == b) {
      bcnt++;
      continue;
    }
    rep(j, 6) {
      if (e[j] == l[i]) {
        cnt++;
        break;
      }
    }
  }

  ll ans = 0;
  if (cnt == 6) {
    ans = 1;
  } else if (cnt == 5 && bcnt == 1) {
    ans = 2;
  } else if (cnt == 5) {
    ans = 3;
  } else if (cnt == 4) {
    ans = 4;
  } else if (cnt == 3) {
    ans = 5;
  }

  cout << ans << endl;
}