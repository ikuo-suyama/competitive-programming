#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc166/abc166_e.txt"); \
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
  vector<int> h(N);
  rep(i, N) {
    cin >> c[i];
    h[i] = c[i] - i;
  }
  sort(h.begin(), h.end());

  ll ans = 0;
  rep(i, N) {
    // printf("i:%d\n", i);
    // この関数が最初にfalseを返す位置のイテレータの位置
    // true, true, false
    //             ^
    auto comps = [&](int x) -> bool {
      // printf("-- %d %d\n", x, c[i]);
      return x + c[i] + i < 0;
    };
    auto compe = [&](int x) -> bool { return x + c[i] + i < 1; };
    auto s = partition_point(h.begin(), h.end(), comps);
    auto e = partition_point(h.begin(), h.end(), compe);
    ans += e - s;
  }

  cout << ans << endl;
}