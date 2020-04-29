#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc144_c.txt"); \
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

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll N;
  cin >> N;

  vector<pair<ll, ll>> pf = prime_factorize(N);
  sort(pf.begin(), pf.end(), greater<>());

  ll a = 1, b = 1;
  for (auto p : pf) {
    ll prime = p.first;
    ll factor = p.second;
    rep(i, factor) {
      if (a > b)
        b *= prime;
      else
        a *= prime;
    }
  }
  cout << a + b - 2 << endl;
}