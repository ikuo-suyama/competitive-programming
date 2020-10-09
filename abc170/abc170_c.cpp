#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("abc170/abc170_c.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v) \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int X, N;
  cin >> X >> N;
  
  if (N == 0) {
    cout << X << endl;
    return 0;
  }

  map<int, int> m;
  rep(i, N) {
    int p;
    cin >> p;
    m[p]++;
  }

  ll ans = X;
  int MAX = 101;
  for (int i = X; i <= 101; i++) {
    if (!m[i]) {
      MAX = i;
      break;
    }
  }

  int MIN = -1;
  for (int i = X - 1; i > -1; i--) {
    if (!m[i]) {
      MIN = i;
      break;
    }
  }

  if (abs(X - MIN) > abs(X - MAX)) {
    ans = MAX;
  } else {
    ans = MIN;
  }

  cout << ans << endl;
}