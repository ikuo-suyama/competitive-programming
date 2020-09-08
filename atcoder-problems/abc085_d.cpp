#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc085_d.txt"); \
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

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, H;
  cin >> N >> H;

  vector<int> a(N, 0);
  vector<int> b(N, 0);
  rep(i, N) { cin >> a[i] >> b[i]; }

  priority_queue<P> bque;
  bque.push({b[0], 0});
  int maxIdx = 0;
  repi(i, 1, N) {
    if (a[i] > a[maxIdx] || (a[i] == a[maxIdx] && b[i] < b[maxIdx])) maxIdx = i;

    bque.push({b[i], i});
  }

  ll ans = 0;
  while (bque.size() != 0) {
    P kv = bque.top();
    bque.pop();
    if (kv.second != maxIdx && bque.size() != 0) {
      H -= kv.first;
      ans++;
    } else {
      ll tmp = ceil((float)max(H - kv.first, 0) / a[maxIdx]);
      ans += tmp + 1;
    }
    if (H <= 0) break;
  }
  cout << ans << endl;
}