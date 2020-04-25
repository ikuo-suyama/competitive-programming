#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc076_c.txt"); \
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

  string S, T;
  cin >> S >> T;

  if (S.size() < T.size()) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }

  bool ok = false;
  for (int i = S.size() - T.size(); i >= 0; i--) {
    bool replace = true;
    rep(j, T.size()) {
      if (S[i + j] != T[j] && S[i + j] != '?') {
        replace = false;
        break;
      }
    }
    if (replace) {
      S.replace(i, T.size(), T);
      ok = true;
      break;
    }
  }
  if (!ok) {
    cout << "UNRESTORABLE" << endl;
  } else {
    rep(i, S.size()) { cout << (S[i] == '?' ? 'a' : S[i]); }
  }
}