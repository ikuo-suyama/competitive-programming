#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int N;
void warshall_floyd(vector<vector<int>>& d) {
  rep(i, N) {      // 経由地
    rep(j, N) {    // 開始点
      rep(k, N) {  // 終点
        // printf("i:%d j:%d k:%d d[j][i]:%d d[i][k]:%d\n", i, j, k, d[j][i],
        //        d[i][k]);
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
      }
    }
  }
}

/**
 * Warshall Floyd法
 * 全経路の組み合わせに対して最短となるコストを求める
 * O(N^3)
 */
int main() {
  ifstream in("ac-ans-a/abc012_4.txt");
  cin.rdbuf(in.rdbuf());

  int M;
  cin >> N >> M;

  vector<vector<int>> d(N, vector<int>(N, INF));
  rep(i, N) {
    // 自分への到達時間は０
    d[i][i] = 0;
  }
  rep(i, M) {
    int a, b, t;
    cin >> a >> b >> t;
    a--;
    b--;
    d[a][b] = t;
    d[b][a] = t;
  }

  warshall_floyd(d);
  vector<int> best(N);
  rep(i, N) { best[i] = *max_element(d[i].begin(), d[i].end()); }
  int ans = *min_element(best.begin(), best.end());

  cout << ans << endl;
}