#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc040_a.txt"); \
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

  string S;
  cin >> S;

  vector<int> c(S.size() + 1, 0);
  char bef = '-';
  rep(i, S.size()) {
    char cur = S[i];
    if (cur == '<') {
      if (bef == '>') {
        c[i + 1] = 1;
      } else {
        c[i + 1] = c[i] + 1;
      }
    } else {
      if (bef == '<') {
        c[i + 1] = 0;
      } else {
        c[i + 1] = c[i] - 1;
      }
    }
    bef = S[i];
  }
  ll ans = 0;
  rep(i, c.size()) {
    ans += abs(c[i]);
  }
  rep(i, c.size()) { cout << c[i] << ' '; }
  cout << endl;
  rep(i, S.size()) { cout << S[i] << ' '; }

  cout << ans << endl;
}