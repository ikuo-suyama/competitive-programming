#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                         \
  ifstream in("atcoder-problems/nikkei2019_2_qual_b.txt"); \
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

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  map<int, int> m;
  rep(i, N) {
    int d;
    cin >> d;
    m[d]++;
    if (i == 0 && d != 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  if (m[0] > 1) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1;
  ll mod = 998244353;

  repi(i, 1, m.size()) {
    if (m[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
    ll pat = modpow(m[i-1], m[i], mod);
    ans = ans * pat % mod;
  }

  cout << ans << endl;
}