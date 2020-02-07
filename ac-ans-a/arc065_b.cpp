#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

/**
 * UnionFind
 * 
 */
struct UnionFind {
  vector<int> par;  // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

  UnionFind(int N) : par(N) {  //最初は全てが根であるとして初期化
    for (int i = 0; i < N; i++) par[i] = i;
  }

  int root(int x) {  // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

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
  ifstream in("ac-ans-a/arc065_b.txt");
  cin.rdbuf(in.rdbuf());

  int N, K, L;
  cin >> N >> K >> L;

  UnionFind p(N + 1), r(N + 1);

  rep(i, K) {
    int a, b;
    cin >> a >> b;
    p.unite(a, b);
  }
  rep(i, L) {
    int a, b;
    cin >> a >> b;
    r.unite(a, b);
  }

  vector<P> ab(N + 1, make_pair(0, 0));
  map<P, int> cnt_m;
  rep(i, N + 1) {
    P k =  make_pair(p.root(i), r.root(i));
    ab[i] = k;

    // 同じペアの数を数え上げる
    decltype(cnt_m)::iterator it = cnt_m.find(k);
    if (it != cnt_m.end()) {
      int cnt = it->second;
      cnt_m.erase(k);
      cnt_m.emplace(k, cnt + 1);
    } else {
      cnt_m.emplace(k, 1);
    }
  }

  repi(i, 1, N + 1) { cout << cnt_m.at(ab[i]) << ' '; }
  cout << endl;
}