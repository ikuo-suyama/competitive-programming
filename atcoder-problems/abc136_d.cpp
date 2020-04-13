#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc136_d.txt"); \
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

  vector<int> c(S.size(), 1);
  vector<int> n(S.size(), 2);
  ll cnt = 0;
  while (++cnt <= 10000) {
    n = c;
    rep(i, S.size()) {
      if (S[i] == 'R') {
        n[i + 1] += c[i];
      } else {
        n[i - 1] += c[i];
      }
      n[i] -= c[i];
    }
    c = n;
  }

  rep(i, S.size()) { cout << c[i] << ' '; }
}