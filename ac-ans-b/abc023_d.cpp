#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main() {
  ifstream in("ac-ans-b/abc023_d.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  vector<ll> H(N), S(N);
  rep(i, N) { cin >> H[i] >> S[i]; }

  auto check = [&](ll x) -> bool {
    vector<ll> c(N);
    rep(i, N) {
      if (x - H[i] < 0) return false;
      c[i] = (x - H[i]) / S[i];
    }
    sort(c.begin(), c.end());
    rep(i, N) {
      if (c[i] < i) {
        return false;
      }
    }
    return true;
  };

  ll l = 0, r = LINF;
  // すべての風船を割ることができる高さを２分探索で求める
  while (l + 1 < r) {
    ll x = (l + r) / 2;
    if (check(x)) {
      r = x;
    } else {
      l = x;
    }
  }

  cout << r << endl;
}