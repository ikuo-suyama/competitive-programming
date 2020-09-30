#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc114_c.txt"); \
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

  ll N;
  cin >> N;

  ll ans = 0;
  vector<int> d = {3, 5, 7};
  int k = to_string(N).size();
  while (k >= 3) {
    rep(i, pow(3, k)) {
      set<int> se;
      ll cnt = 0, dig = 0, n = i;
      rep(j, k) {
        int s = n % 3;
        dig += d[s] * pow(10, j);
        n /= 3;
        se.insert(s);
      }
      // printf("i:%d %lld\n", i, dig);
      if (dig <= N && se.size() == 3) ans++;
    }
    k--;
  }

  cout << ans << endl;
}