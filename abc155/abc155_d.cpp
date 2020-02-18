#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const ll LL_INF = 1e18 + 1;
const int MOD = 1e9 + 7;

int main() {
  ifstream in("abc155/abc155_d.txt");
  cin.rdbuf(in.rdbuf());

  ll N, K;
  cin >> N >> K;

  vector<ll> c(N);
  rep(i, N) { cin >> c[i]; }
  sort(c.begin(), c.end());

  ll l = -LL_INF;
  ll r = LL_INF;
  while (l + 1 < r) {
    // k個のときのペアの積の最大値を二分探索する
    ll x = (l + r) / 2;
    ll total = 0;

    rep(i, N) {
      // c[i] と組にしてXを超えないペアの数を二分探索で求める
      int ll = i, rr = N;
      if (c[i] > 0) {
        while (ll + 1 < rr) {
          int xx = (ll + rr) / 2;
          if (c[i] * c[xx] < x) {
            ll = xx;
          } else {
            rr = xx;
          }
        }
        total += ll - i;
        // printf("x: %d, c[i]:%lld ll:%d, total:%d\n", x, c[i], ll, total);
      } else {
        // c[i] が負の場合は、後ろから小さい数になる
        while (ll + 1 < rr) {
          int xx = (ll + rr) / 2;
          if (c[i] * c[xx] < x) {
            rr = xx;
          } else {
            ll = xx;
          }
        }
        total += N - rr;
        // printf("x: %d, c[i]:%lld ll:%d, total:%d\n", x, c[i], ll, total);
      }
    }

    if (total < K) {
      l = x;
    } else {
      r = x;
    }
  }

  cout << l << endl;
}