#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int N, M;

string berman_ford(vector<vector<int>>& g, map<P, ll>& m) {
  vector<ll> d(N, __LONG_LONG_MAX__);
  bool negative = false;

  d[0] = 0;

  rep(i, N + 1) {
    bool updated = false;
    for (auto p : m) {
      int j = p.first.first;
      int k = p.first.second;

      ll current = d[k];
      ll cost = d[j] + p.second;

      if (current > cost) {
        d[k] = cost;
        updated = true;
      }
    }

    if (!updated) {
      break;
    }
    if (i == N) {
      negative = true;
    }
  }

  return negative ? "inf" : to_string(-d[N - 1]);
}

/**
 * ベルマンフォード法 / Berman Ford
 * SeeAlso: ダイクストラ
 * 負のコストがある場合、閉経路がある場合はこちら
 * O(NM)
 * https://qiita.com/wakimiko/items/69b86627bea0e8fe29d5
 */
int main() {
  ifstream in("ac-ans-a/abc061_d.txt");
  cin.rdbuf(in.rdbuf());

  cin >> N >> M;

  vector<vector<int>> g(N, vector<int>(0));
  map<P, ll> m;
  rep(i, M) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;

    g[a].push_back(b);
    m.emplace(make_pair(a, b), -c);
  }

  string ans = berman_ford(g, m);
  cout << ans << endl;
}