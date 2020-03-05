#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc148/abc148_d.txt"); \
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
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  ll cnt = 0;
  int last = -1;
  vector<int> a(0);
  rep(i, N) {
    if (c[i] != i + 1 - cnt) {
      cnt++;
    } else {
      last = i;
    }
  }

  // printf("%d, %d", c[last], N - cnt + 1);
  if (cnt == c.size() || c[last] != N - cnt) cnt = -1;

  cout << cnt << endl;
}