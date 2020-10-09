#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc039_a.txt"); \
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

int cnt(string s) {
  ll tmp = 0;
  ll sum = 0;
  char c = s[0];
  rep(i, s.size()) {
    if (c == s[i])
      tmp++;
    else {
      if (tmp > 1) sum += tmp / 2;
      tmp = 1;
      c = s[i];
    }
  }
  if (tmp > 1) sum += tmp / 2;
  return sum;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  string S;
  ll K;
  cin >> S >> K;
  int N = S.size();
  set<char> c;
  rep(i, N) c.insert(S[i]);

  ll ans = 0;
  ans = cnt(S);
  if (K == 1) {
    cout << ans << endl;
    return 0;
  } else if (c.size() == 1) {
    cout << S.size() * K / 2 << endl;
    return 0;
  }

  ans *= K;
  if (S[0] == S[N - 1]) {
    int a = 0;
    rep(i, N) {
      if (S[0] == S[i])
        a++;
      else
        break;
    }
    int b = 0;
    for (int i = N - 1; i >= 0; i--) {
      if (S[0] == S[i])
        b++;
      else
        break;
    }
    ans -= ((a / 2) + (b / 2) - (a + b) / 2) * (K - 1);
  }

  cout << ans << endl;
}