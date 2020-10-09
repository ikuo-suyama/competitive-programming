#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("abc175/abc175_b.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v) \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;
  
  vector<ll> c(N);
  rep(i, N) { cin >> c[i]; }

  ll ans = 0;
  rep(i, N - 2) repi(j, i + 1, N - 1) repi(k, j + 1, N) {
    if (c[i] == c[j] || c[i] == c[k] || c[j] == c[k]) continue;
    vector<ll> a = {c[i], c[j], c[k]};
    sort(a.begin(), a.end());
    if (a[0] + a[1] > a[2]) ans++;
  }

  cout << ans << endl;
}