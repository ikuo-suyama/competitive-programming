#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/arc104_b.txt"); \
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
  string S;
  cin >> N >> S;

  vector<int> a(N, 0);
  vector<int> g(N, 0);
  vector<int> c(N, 0);
  vector<int> t(N, 0);
  repi(i, 1, N) {
    a[i] = a[i - 1];
    g[i] = g[i - 1];
    c[i] = c[i - 1];
    t[i] = t[i - 1];
    if (S[i] == 'A') a[i - 1]++;
    if (S[i] == 'G') g[i - 1]++;
    if (S[i] == 'C') c[i - 1]++;
    if (S[i] == 'T') t[i - 1]++;
  }

  ll ans = 0;

  cout << ans << endl;
}