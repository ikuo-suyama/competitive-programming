#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc022_a.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;
#else
#define INPUT_FILE
#define print_vec(v)
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
typedef pair<ll, ll> pl;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  string S;
  cin >> S;

  int N = S.size();
  vector<int> c(26, 0);
  rep(i, N) { c[S[i] - 'a']++; }

  if (N < 26) {
    rep(i, 26) {
      if (!c[i]) {
        cout << S << char('a' + i) << endl;
        return 0;
      }
    }
  }
  for (int i = N - 1; i >= 1; i--) {
    // printf("%c %c %d\n", S[i - 1], S[i], S[i - 1] < S[i]);
    c[S[i] - 'a']--;
    if (S[i - 1] < S[i]) {
      rep(j, 26) {
        char t = ('a' + j);
        if (!c[j] && t > S[i - 1]) {
          cout << S.substr(0, i - 1) << char(t) << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}