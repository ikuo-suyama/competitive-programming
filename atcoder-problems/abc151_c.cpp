#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc151_c.txt"); \
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

  int N, M;
  cin >> N >> M;

  vector<int> ac(N, 0);
  vector<int> wc(N, 0);
  rep(i, M) {
    int p;
    string a;
    cin >> p >> a;
    p--;
    if (a == "AC") {
      ac[p] = 1;
    } else {
      if (!ac[p]) {
        wc[p]++;
      }
    }
  }

  int _ac = 0, _wc = 0;
  rep(i, N) {
    _ac += ac[i];
    if (ac[i]) {
      _wc += wc[i];
    }
  }

  printf("%d %d", _ac, _wc);
}