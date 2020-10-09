#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/diverta2019_2_b.txt"); \
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

  int N;
  cin >> N;
  
  vector<ll> x(N), y(N);
  rep(i, N) { cin >> x[i] >> y[i]; }

  ll ans = N;

  map<pair<ll, ll>, ll> map;
  rep(i, N) rep(j, N) {
    if (i == j) continue;
    ll p = x[i] - x[j];
    ll q = y[i] - y[j];
    map[{p, q}]++;
  }

  ll ret = 0;
  for (auto kv : map) {
    ret = max(ret, kv.second);
  }

  cout << ans - ret << endl;
}