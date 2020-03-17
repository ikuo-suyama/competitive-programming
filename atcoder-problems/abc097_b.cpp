#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc097_b.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int x;
  cin >> x;

  int MAX_I = sqrt(1000) + 1;
  int ans = 1;
  repi(i, 2, MAX_I) {
    int j = 2;
    while (pow(i, j) <= x) {
      // printf("%d, %d, %f\n", i, j, pow(i, j));
      ans = max((int)pow(i, j++), ans);
    }
  }

  cout << ans << endl;
}