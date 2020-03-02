#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("abc149/abc149_c.txt"); \
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
const int MOD = 1e9 + 7;

vector<int> sieve(int N) {
  vector<bool> e(N + 1, true);
  e[0] = false;
  e[1] = false;
  int sqrtN = ceil(sqrt(N)) + 1;
  rep(p, sqrtN) {
    if (!e[p]) continue;
    for (int i = pow(p, 2); i <= N; i += p) {
      e[i] = false;
    }
  }
  vector<int> ret;
  rep(i, N + 1) {
    if (e[i]) ret.push_back(i);
  }
  return ret;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int x;
  cin >> x;

  auto primes = sieve(2e5);
  int id = upper_bound(primes.begin(), primes.end(), x) - primes.begin();
  ll ans;
  if (primes[id-1] == x) {
    ans = x;
  } else {
    ans = primes[id];
  }
  cout << ans << endl;
}