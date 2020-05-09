#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc085_c.txt"); \
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

/**
 * 全探索 10 ^ 3, x, y, z
 * x, y を決めるとz が決まるので O(N^2) で終わるパターン
 * 後でとく
 * https://qiita.com/drken/items/ace3142967c4f01d42e9
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, Y;
  cin >> N >> Y;

  rep(i, N + 1) {
    rep(j, N + 1) {
      int res = (Y - (10000 * i + 5000 * j));
      int n = N - i - j;
      if (n < 0) break;
      if (res == 1000 * n) {
        printf("%d %d %d", i, j, n);
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;
}