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

  auto top = que.top();
  que.pop();
  ll tgt = top.first;
  ll cnt = top.second;

  auto rit = lower_bound(a.begin(), a.end(), tgt);
  if (*rit == tgt) rit--;
  cnt = min(cnt, ll(rit - a.begin()));
  ll ans = 0;
  // 右側を足し上げ
  repi(i, rit - a.begin() + 1, N) { ans += a[i]; }
  ans += tgt * cnt;
  rit = max(rit - cnt, a.begin());

  while (!que.empty()) {
    auto top = que.top();
    que.pop();
    ll tgt = top.first;
    ll cnt = top.second;

    auto lit = upper_bound(a.begin(), rit, tgt);
    if (lit == rit) break;
    cnt = min(cnt, ll(lit - a.begin()));
    ans += tgt * cnt;
    rit = min(lit - cnt, a.begin());
  }

  cout << ans << endl;
}