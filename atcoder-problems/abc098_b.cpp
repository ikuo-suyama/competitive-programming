#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc098_b.txt"); \
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
  string S;
  cin >> S;

  int ans = 0;
  repi(i, 1, N) {
    int tmp = 0;
    map<char, int> l;
    map<char, int> r;
    string ls = S.substr(0, i);
    string rs = S.substr(i, N);
    rep(j, N) {
      if (ls.size() > j) l[ls[j]]++;
      if (rs.size() > j) r[rs[j]]++;
    }
    for (auto kv : l) {
      if (r.find(kv.first) != r.end()) tmp++;
    }
    ans = max(tmp, ans);
  }

  cout << ans<< endl;
}