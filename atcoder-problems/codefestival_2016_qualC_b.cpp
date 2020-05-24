#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                                      \
  ifstream in("atcoder-problems/codefestival_2016_qualC_b.txt"); \
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

  int K, T;
  cin >> K >> T;

  vector<int> a(T);
  rep(i, T) { cin >> a[i]; }
  sort(a.begin(), a.end(), greater<int>());

  ll ans = 0;
  if (T > 1) {
    ans = max(a[0] - a[1] - 1, 0);
  } else {
    ans = a[0] - 1;
  }

  cout << ans << endl;
}