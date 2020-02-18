#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

void prdmod(ll& src, const ll& tgt) {
  ll ret = ((src % MOD) * (tgt % MOD)) % MOD;
  if (ret < 0) ret += MOD;
  src = ret;
}

void addmod(ll& src, const ll& tgt) {
  ll ret = ((src % MOD) + (tgt % MOD)) % MOD;
  if (ret < 0) ret += MOD;
  src = ret;
}

// Sieve of Eratosthenes
// エラトステネスの篩
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

int loga(int x, int a) {
  if (x == 0 || x == 1) return 0;
  int cnt = 0;
  while (x % a == 0) {
    x /= a;
    cnt++;
  }
  return cnt;
}

int main() {
  ifstream in("ac-ans-a/arc067_a.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  // Nまでの素数列
  vector<int> prime = sieve(N);

  // 約数の数は N = p1 ^ c1 * p2 ^ c2 ... のとき (c1 + 1) * (c2 + 1) ...
  // https://juken-mikata.net/how-to/mathematics/number-of-divisor.html
  ll ans = 1;
  for (auto p : prime) {
    ll ans_i = 0;
    repi(i, 2, N + 1) {
      ll c = loga(i, p);
      addmod(ans_i, c);
    }
    prdmod(ans, ans_i + 1);
  }
  cout << ans << endl;
}