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

  int N = S.size() + 1;
  vector<int> l(N, 0);
  vector<int> r(N, 0);
  for (int i = 1; i < N; i++) {
    if (S[i - 1] == '<') {
      l[i] = l[i - 1] + 1;
    } else {
      l[i + 1] = 0;
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    if (S[i] == '>') {
      r[i] = r[i+1] + 1;
    } else {
      r[i] = 0;
    }
  }
  ll ans = 0;
  rep(i, N) { ans += max(r[i], l[i]); }

  // rep(i, N) { cout << r[i] << ' '; }
  // cout << endl;
  // rep(i, N) { cout << l[i] << ' '; }
  // cout << endl;
  // rep(i, S.size()) { cout << S[i] << ' '; }

  cout << ans << endl;
}