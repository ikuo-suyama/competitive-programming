#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder/abl_d.txt"); \
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

#include <atcoder/segtree>

int op(int a, int b) { return max(a, b); }
int e() { return 0; }

const int MAX_A = 300005;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, K;
  cin >> N >> K;
  
  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  ll ans = 0;
  atcoder::segtree<int, op, e> dp(MAX_A);
  rep(i, N) { int x = c[i];
    int l = max(0, x - K);
    int r = min(x + K + 1, MAX_A);
    int now = dp.prod(l, r) + 1;
    dp.set(x, now);
  }

  cout << dp.prod(0, MAX_A) << endl;
}