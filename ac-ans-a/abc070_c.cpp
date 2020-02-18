#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

// 最大公約数を求める関数。ユークリッドの除去法
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

// 最小公倍数を求める関数。
// a * b = gcd(a,b) * lcm(a,b)
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ifstream in("ac-ans-a/abc070_c.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  vector<ll> c(N);
  rep(i, N) { cin >> c[i]; }

  ll ans = c[0];
  repi(i, 1, N) { ans = lcm(ans, c[i]); }

  cout << ans << endl;
}