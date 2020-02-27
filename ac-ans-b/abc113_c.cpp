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

  cin.tie(0);
  ios::sync_with_stdio(false);

  int N , M;
  cin >> N >> M;
  
  vector<vector<int>> c(N);
  vector<int> P(M);
  vector<int> Y(M);

  rep(i, M) {
    cin >> P[i] >> Y[i];
    c[--P[i]].push_back(Y[i]);
  }

  rep(i, N) { sort(c[i].begin(), c[i].end()); }
  rep(i, M) {
    ll id = lower_bound(c[P[i]].begin(), c[P[i]].end(), Y[i]) -  c[P[i]].begin();
    printf("%06d%06lld\n", P[i] + 1, id + 1);
  }
}