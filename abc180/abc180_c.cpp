#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("abc180/abc180_c.txt"); \
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

// 素因数分解
vector<pair<ll, ll>> prime_factorize(ll N) {
  vector<pair<ll, ll>> res;
  for (ll a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    ll ex = 0;  // 指数

    while (N % a == 0) {
      ++ex;
      N /= a;
    }

    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (N != 1) res.push_back({N, 1});
  return res;
}

void solve(int i, ll cur, vector<pair<ll, ll>> p, vector<ll>& ans) {
  if (i >= p.size()) {
    ans.push_back(cur);
    return;
  }
  auto pn = p[i];
  rep(j, pn.second + 1) { 
    solve(i + 1, cur, p, ans);
    cur *= pn.first;
  }
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll N;
  cin >> N;

  vector<pair<ll, ll>> primes = prime_factorize(N);
  vector<ll> ans(0);
  solve(0, 1, primes, ans);

  sort(ans.begin(), ans.end());
  rep(i, ans.size()) { cout << ans[i] << endl; }
}