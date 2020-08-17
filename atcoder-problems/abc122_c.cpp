#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc122_c.txt"); \
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

  int N, Q;
  cin >> N >> Q;

  string S;
  cin >> S;

  vector<int> l(Q), r(Q);
  rep(i, Q) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }

  vector<int> c(N, 0);
  repi(i, 1, N) {
    if (S[i - 1] == 'A' && S[i] == 'C') {
      c[i] = c[i - 1] + 1;
    } else {
      c[i] = c[i - 1];
    }
  }

  rep(i, Q) {
    cout << c[r[i]] - c[l[i]] << endl;
  }
}