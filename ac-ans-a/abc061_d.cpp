#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int N, M;

string berman_ford(map<P, ll>& m) {
  vector<ll> d(N, __LONG_LONG_MAX__);

  d[0] = 0;

  rep(i, N) {
    for (auto p : m) {
      int j = p.first.first;
      int k = p.first.second;
      if (d[j] == __LONG_LONG_MAX__) continue;

      ll current = d[k];
      ll cost = d[j] + p.second;

      if (current > cost) {
        d[k] = cost;
      }
    }
  }
  ll ans = -d[N - 1];

  vector<bool> negative(N, false);
  rep(i, N + 1) {
    for (auto p : m) {
      int j = p.first.first;
      int k = p.first.second;
      if (d[j] == __LONG_LONG_MAX__) continue;

      ll current = d[k];
      ll cost = d[j] + p.second;

      if (current > cost) {
        d[k] = cost;
        negative[k] = true;
      }
      if (negative[j]) negative[k] = true;
    }
  }

  return negative[N - 1] ? "inf" : to_string(ans);
}

/**
 * ベルマンフォード法 / Berman Ford
 * SeeAlso: ダイクストラ
 * 負のコストがある場合、閉経路がある場合はこちら
 * O(NM)
 * https://qiita.com/wakimiko/items/69b86627bea0e8fe29d5
 * https://nw.tsuda.ac.jp/lec/BellmanFord/
 */
int main() {
  ifstream in("ac-ans-a/abc061_d.txt");
  cin.rdbuf(in.rdbuf());

  cin >> N >> M;

  map<P, ll> m;
  rep(i, M) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;

    m.emplace(make_pair(a, b), -c);
  }

  string ans = berman_ford(m);
  cout << ans << endl;
}