#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc167/abc167_d.txt"); \
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

  int N, K;
  cin >> N >> K;

  vector<int> c(N);
  rep(i, N) {
    cin >> c[i];
    c[i]--;
  }

  vector<int> a(N, 0);
  a[0] = c[0];
  repi(i, 1, N) { a[i] = c[a[i - 1]]; }

  // ループの開始位置で判定
  int n = 3 % K - 1;
  ll ans = a[n] + 1;

  cout << ans << endl;
}