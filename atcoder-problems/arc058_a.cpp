#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/arc058_a.txt"); \
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
  int K;
  cin >> N >> K;

  unordered_set<int> d;
  rep(i, K) {
    int _d;
    cin >> _d;
    d.insert(_d);
  }

  int ans = 0;
  repi(i, N, 100000) {
    string s = to_string(i);
    bool ok = true;
    rep(j, s.size()) {
      if (d.count(s[j] - '0')) {
        ok = false;
        break;
      }
    }
    if (ok){
      ans = i;
      break;
    }
  }

  cout << ans << endl;
}