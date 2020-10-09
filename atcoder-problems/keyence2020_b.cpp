#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                   \
  ifstream in("atcoder-problems/keyence2020_b.txt"); \
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

/**
 * #座標 #二次元 #重複排除
 * #座標圧縮 かと思ったら 右側の座標が小さい順に貪欲で解けた
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  vector<pl> c(N);
  rep(i, N) {
    ll x, l;
    cin >> x >> l;
    // 右側の小さい順にソートしたい
    c[i] = pl(x + l, x - l);
  }
  sort(c.begin(), c.end());

  ll ans = 0;
  ll cur = -LINF;
  rep(i, N) {
    ll s = c[i].second;
    if (cur <= s) {
      ans++;
      cur = c[i].first;
    }
  }

  cout << ans << endl;
}