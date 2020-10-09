#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/abc110_c.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v) \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  string S, T;
  cin >> S >> T;

  map<char, char> m;
  rep(i, S.size()) {
    if (!m.count(S[i])) {
      m[S[i]] = T[i];
    } else {
      char t = m[S[i]];
      if (t != T[i]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  m.clear();
  rep(i, S.size()) {
    if (!m.count(T[i])) {
      m[T[i]] = S[i];
    } else {
      char s = m[T[i]];
      if (s != S[i]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
 
  cout << "Yes" << endl;
}