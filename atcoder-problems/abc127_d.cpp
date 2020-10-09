#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc127_d.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
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

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, M;
  cin >> N >> M;

  vector<int> a(N);
  rep(i, N) { cin >> a[i]; }
  sort(a.begin(), a.end());

  priority_queue<pl, vector<pl>> que;
  rep(i, M) {
    int b, c;
    cin >> b >> c;
    que.push(make_pair(c, b));
  }

  ll ans = 0;
  int r = 0;
  bool ok = true;
  while (!que.empty() && ok) {
    auto top = que.top();
    que.pop();
    ll tgt = top.first;
    ll cnt = top.second;

    int replace = 0;
    repi(i, r, r + cnt) {
      if (a[i] <= tgt) {
        a[i] = tgt;
        replace++;
      } else {
        ok = false;
        break;
      }
    }
    r += replace;
  }

  rep(i, N) { ans += a[i]; }

  cout << ans << endl;
}