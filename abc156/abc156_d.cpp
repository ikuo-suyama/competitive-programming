#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

ll plusMod(ll a, ll b, const int mod = MOD) {
  ll ans = (a + b) % mod;
  if (ans < 0) {
    ans += mod;
  }
  return ans;
}
ll prodMod(ll a, ll b, const int mod = MOD) {
  ll t = a * b % mod;
  if (t < 0) t += mod;
  return t;
}

/**
 * 繰り返し自乗法
 * http://satanic0258.hatenablog.com/entry/2016/04/29/004730
 */
ll powMod(ll n, ll p, const int mod = MOD) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    ll t = powMod(n, p / 2);
    return prodMod(t, t);
  } else {
    return prodMod(n, powMod(n, p - 1));
  }
}
/**
 * 余剰階乗 (Factorial)
 */
ll factMod(ll n) {
  ll n_fact = 1;
  rep(i, n) { n_fact = prodMod(n_fact, n - i); }
  return n_fact;
}
/**
 * 余剰Combination
 * nCk≡n! * (k!)^M−2 * ((n−k)!)^M−2 (modM)
 */
ll combMod(ll n, ll k, const int mod = MOD) {
  ll n_fact = factMod(n);
  ll k_fact = factMod(k);
  ll n_k_fact = factMod(n - k);

  ll k_powM = powMod(k_fact, mod - 2);
  ll n_k_powM = powMod(n_k_fact, mod - 2);

  // printf("%lld, %lld, %lld, %lld, %lld\n", n_fact, k_fact, n_k_fact, k_powM, n_k_powM);

  ll nCk = prodMod(prodMod(n_fact, k_powM), n_k_powM);
  return nCk;
}

int main() {
  ifstream in("abc156/abc156_d.txt");
  cin.rdbuf(in.rdbuf());

  int N, a, b;
  cin >> N >> a >> b;

  ll tot_cnt = powMod(2, N) - 1;
  ll nCa = combMod(N, a);
  ll nCb = combMod(N, b);

  // printf("%lld, %lld, %lld\n", tot_cnt, nCa, nCb);

  cout << plusMod(plusMod(tot_cnt, -nCa), -nCb) << endl;
}