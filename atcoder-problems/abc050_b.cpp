#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc050_b.txt"); \
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

  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  ll sum = 0;
  rep(i, N) { sum += c[i]; }

  int M;
  cin >> M;

  vector<P> p(M);
  rep(i, M) {
    int x, t;
    cin >> x >> t;
    x--;
    p[i] = make_pair(x, t);
  }

  rep(i, M) {
    ll tmp = sum;
    tmp -= c[p[i].first];
    tmp += p[i].second;
    cout << tmp << endl;
  }
}