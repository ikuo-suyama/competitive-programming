#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc126_c.txt"); \
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

int loga(int x, int a) {
  if (x == 0 || x == 1) return 0;
  int cnt = 0;
  while (x != 0) {
    x /= a;
    cnt++;
  }
  return cnt;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, K;
  cin >> N >> K;

  double ans;
  repi(i, 1, N + 1) {
    ll f = i;
    double p = 1;
    while (K > f) {
      f *= 2;
      p /= 2;
    }
    ans += p;
  }
  printf("%.12lf", ans / N);
}