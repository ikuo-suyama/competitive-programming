#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc066_b.txt"); \
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

  int ans = 0;
  for (int i = S.size() - 3; i > 0; i -= 2) {
    bool ok = true;
    rep(j, i / 2) {
      char a = S[j];
      char b = S[i / 2 + 1 + j];
      if (a != b) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = i + 1;
      break;
    }
  }

  cout << ans << endl;
}