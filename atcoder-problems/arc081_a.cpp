#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/arc081_a.txt"); \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;
  
  vector<ll> c(N);
  rep(i, N) { cin >> c[i]; }

  sort(c.begin(), c.end(), greater<ll>());
  vector<ll> a(2, 0);
  int j = 0;
  rep(i, N - 1) {
    if (c[i] == c[i + 1]) {
      a[j++] = c[i];
      i++;
    }
    if (j > 1) break;
  }

  cout << a[0] * a[1] << endl;
}