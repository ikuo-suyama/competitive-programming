#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc165/abc165_c.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
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

int N, M, Q;
ll ans = 0;
vector<int> buf(0);
vector<int> a(0);
vector<int> b(0);
vector<int> c(0);
vector<int> d(0);

void dfs(int i, const int range_start, const int range_end) {
  if (i == N) {
    // 全桁埋めたので判定
    ll tmpans = 0;
    rep(i, Q) {
      if (buf[b[i]] - buf[a[i]] == c[i]) tmpans += d[i];
    }
    ans = max(tmpans, ans);
  } else {
    repi(j, range_start, range_end + 1) {
      buf[i] = j;
      dfs(i + 1, range_start, range_end);
    }
  }
}

/**
 * https://www.hamayanhamayan.com/entry/2020/05/02/225726
 * 重複順列 dfsによる全探索(全列挙)
 * 必要ない箇所は探索しないことを枝刈りという
 * #dfs #全探索 #枝刈り
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> N >> M >> Q;

  buf.resize(N);
  a.resize(Q);
  b.resize(Q);
  c.resize(Q);
  d.resize(Q);
  rep(i, Q) {
    int _a, _b;
    cin >> _a >> _b >> c[i] >> d[i];
    _a--;
    _b--;
    a[i] = _a;
    b[i] = _b;
  }

  dfs(0, 1, M);
  cout << ans << endl;
}