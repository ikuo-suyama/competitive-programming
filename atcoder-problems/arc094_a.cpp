#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/arc094_a.txt"); \
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

  int N = 3;

  vector<int> d(N);
  rep(i, N) { cin >> d[i]; }
  sort(d.begin(), d.end());

  int a = d[0];
  int b = d[1];
  int c = d[2];

  ll ans = 0;
  if ((b - a) % 2 == 0) {
    ans += (b - a) / 2;
    a = b;
  } else {
    ans += (b - a) / 2 + 1;
    c++;
  }

  ans += c - b;

  cout << ans << endl;
}