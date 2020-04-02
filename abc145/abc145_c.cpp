#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc145/abc145_c.txt"); \
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

  int N;
  cin >> N;

  vector<P> c(N);
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    c[i] = make_pair(a, b);
  }

  long np = 1;
  vector<int> v(N);
  rep(i, N) {
    np *= i + 1;
    v[i] = i;
  }

  long double sum = 0;
  do {
    rep(i, N - 1) {
      int x = c[v[i]].first;
      int y = c[v[i]].second;
      int xi = c[v[i + 1]].first;
      int yi = c[v[i + 1]].second;
      sum += sqrt(pow(x - xi, 2) + pow(y - yi, 2));
    }
  } while (next_permutation(v.begin(), v.end()));

  printf("%6Lf", sum / np);
}