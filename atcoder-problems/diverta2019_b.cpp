#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                   \
  ifstream in("atcoder-problems/diverta2019_b.txt"); \
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

  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int r = 0;
  ll ans = 0;
  while (R * r <= N) {
    int g = 0;
    while (R * r + G * g <= N) {
      int rest = N - (R * r + G * g);
      int b = rest / B;
      if (rest == 0 || (b != 0 && rest - (B * b) == 0)) {
        // printf("%d %d %d\n", r, g, b);
        ans++;
      }
      g++;
    }
    r++;
  }

  cout << ans << endl;
}