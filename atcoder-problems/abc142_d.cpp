#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc142_d.txt"); \
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
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

// 素数判定
// O(Sqrt N)
bool IsPrime(ll num) {
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;  // 偶数はあらかじめ除く

  ll sqrtNum = ceil(sqrt(num));
  for (ll i = 3; i <= sqrtNum; i += 2) {
    if (num % i == 0) {
      // 素数ではない
      return false;
    }
  }

  // 素数である
  return true;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  ll a, b;
  cin >> a >> b;

  ll ans = 1;
  ll g = gcd(a, b);
  for(ll i = 2; i * i <= g; i++) {
    if (g % i == 0 && IsPrime(i)) ans++;
  }
  if (IsPrime(g)) ans++;

  cout << ans << endl;
}