#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc140/abc140_e.txt"); \
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

  int N;
  cin >> N;

  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  ll ans = 0;
  rep(i, N - 1) {
    vector<int> ms(0);
    int m = max(c[i], c[i + 1]);
    int m2 = min(c[i], c[i + 1]);
    ans += m2;
    ms.push_back(m2);
    repi(j, i + 2, N) {
      if (m < c[j]) {
        m2 = m;
        m = c[j];
      } else if (m2 < c[j]) {
        m2 = c[j];
      }
      ans += m2;
      ms.push_back(m2);
    }
    print_vec(ms);
  }

  cout << ans << endl;
}