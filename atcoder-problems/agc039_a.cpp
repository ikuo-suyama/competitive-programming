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

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  string S;
  ll K;
  cin >> S >> K;
  int N = S.size();

  ll tmp = 0;
  char c = S[0];
  for (int i = N - 1; i >= 0; i--) {
    if (c == S[i])
      tmp++;
    else
      break;
  }
  if (tmp == N) {
    cout << ceil(((double)N / 2)) * K << endl;
    return 0;
  }

  ll ans = 0;
  rep(i, N) {
    if (c == S[i])
      tmp++;
    else {
      c = S[i];
      if (tmp > 1) {
        ans += ceil((double)tmp / 2);
      }
      tmp = 0;
    }
  }
  if (tmp && S[N - 1] != S[0]) ans += ceil((double)tmp / 2);

  cout << ans * K << endl;
}