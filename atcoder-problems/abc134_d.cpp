#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc134_d.txt"); \
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

  vector<int> c(N + 1);
  rep(i, N) { cin >> c[i + 1]; }

  vector<int> a(N + 1, 0);
  ll tot;
  for (int i = N; i >= 1; i--) {
    if (i > N / 2) {
      a[i] = c[i];
    } else {
      int sum = 0;
      repi(j, 1, N / i + 1) { sum += a[j * i]; }
      a[i] = sum % 2 == c[i] ? 0 : 1;
    }
    tot += a[i];
  }

  cout << tot << endl;
  rep(i, N + 1) { 
    if (a[i]) cout << i << endl;
  }
}