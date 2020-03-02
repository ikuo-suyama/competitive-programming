#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc157/abc157_d.txt"); \
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
const int MOD = 1e9 + 7;

struct UnionFind {
  vector<int> par;  // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

  UnionFind(int N) : par(N) {  //最初は全てが根であるとして初期化
    for (int i = 0; i < N; i++) par[i] = i;
  }

  int root(int x) {  // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  vector<int> cnt;
  void countUp() {
    cnt = vector<int>(par.size(), 0);
    for (int i = 0; i < par.size(); i++) {
      int r = root(i);
      cnt[r]++;
    }
  }
  int countConnected(int x) { return cnt[root(x)]; }

  void unite(int x, int y) {  // xとyの木を併合
    int rx = root(x);         // xの根をrx
    int ry = root(y);         // yの根をry
    if (rx == ry) return;  // xとyの根が同じ(=同じ木にある)時はそのまま
    par[rx] =
        ry;  // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
  }

  bool same(int x, int y) {  // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, M, K;
  cin >> N >> M >> K;

  UnionFind u = UnionFind(N);
  vector<vector<int>> fr(N, vector<int>(0));
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    fr[a].push_back(b);
    fr[b].push_back(a);
    u.unite(a, b);
  }

  vector<vector<int>> bl(N, vector<int>(0));
  rep(i, K) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (u.same(a, b)) {
      bl[a].push_back(b);
      bl[b].push_back(a);
    }
  }

  u.countUp();

  rep(i, N) {
    int ans = u.countConnected(i) - fr[i].size() - bl[i].size() - 1;
    cout << ans << ' ';
  }
}