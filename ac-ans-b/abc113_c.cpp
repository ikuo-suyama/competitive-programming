#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int main() {
  ifstream in("ac-ans-b/abc113_c.txt");
  cin.rdbuf(in.rdbuf());

  int N , M;
  cin >> N >> M;
  
  vector<vector<int>> c(N, vector<int>(0));
  vector<int> P(M);
  vector<int> Y(M);

  rep(i, M) {
    int p, y;
    cin >> p >> y;
    p--;
    c[p].push_back(y);
    P[i] = p;
    Y[i] = y;
  }

  rep(i, N) { sort(c[i].begin(), c[i].end()); }
  rep(i, M) {
    auto _p = c[P[i]];
    auto ite = lower_bound(_p.begin(), _p.end(), Y[i]);
    printf("%06d%06ld\n", P[i] + 1, distance(_p.begin(), ite) + 1);
  }
}