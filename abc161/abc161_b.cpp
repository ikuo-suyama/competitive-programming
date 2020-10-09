#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc161/abc161_b.txt"); \
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

  int N, M;
  cin >> N >> M;

  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  double tot = 0;
  rep(i, N) { tot += c[i]; }
  sort(c.begin(), c.end(), greater<int>());

  int ret = 0;
  double th = (tot / (4 * M));
  rep(i, N) {
    if (c[i] >= th) ret++;
  }

  cout << (ret >= M ? "Yes" : "No") << endl;
}