#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                 \
  ifstream in("atcoder-problems/caddi2018_a.txt"); \
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

map<ll, ll> factorization(ll N) {
  map<ll, ll> ret;
  ll fact = 2;
  while(fact <= sqrt(N)) {
    if (N % fact == 0) {
      ret[fact]++;
      N /= fact;
    } else {
      fact++;
    }
  }
  if (N != 0) ret[N]++;
  return ret;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll N, P;
  cin >> N >> P;
  if (N == 1) {
    cout << P << endl;
    return 0;
  };

  map<ll, ll> fact = factorization(P);
  ll ans = 1;
  for (auto kv : fact) {
    if (kv.second >= N) {
      ans *= pow(kv.first, kv.second / N);
    }
  }

  cout << ans << endl;
}