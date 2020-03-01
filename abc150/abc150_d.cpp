#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc150/abc150_d.txt"); \
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

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  ll M;
  cin >> N >> M;

  vector<ll> a(N);
  set<int> checker;

  rep(i, N) {
    cin >> a[i];
    int t = a[i], cnt = 0;
    while (t % 2 == 0) {
      t /= 2;
      cnt++;
    }
    checker.insert(cnt);
  }
  if (checker.size() != 1) {
    cout << 0 << endl;
    return 0;
  }

  ll l = 1;
  rep(i, N) { l = lcm(l, a[i] / 2); }

  cout << (M < l ? 0 : (M / l + 1) / 2) << endl;
}