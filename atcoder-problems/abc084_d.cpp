#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc084_d.txt"); \
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

unordered_map<int, int> sieve(int N) {
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
  unordered_map<int, int> ret;
  rep(i, N + 1) {
    if (e[i]) ret.emplace(i, 1);
  }
  return ret;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  vector<int> l(N), r(N);
  rep(i, N) { cin >> l[i] >> r[i]; }

  int MAX = 1e5;
  unordered_map<int, int> primes = sieve(MAX);
  vector<int> c(MAX, 0);
  for (int i = 3; i <= MAX; i += 2) {
    c[i] = c[i - 2];
    if (primes[i] && primes[(i + 1) / 2]) c[i]++;
  }

  rep(i, N) { cout << c[r[i]] - c[l[i] - 2] << endl; }
}