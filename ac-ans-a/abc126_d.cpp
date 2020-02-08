#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("ac-ans-a/abc126_d.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  vector<vector<int>> g(N);
  map<P, ll> wm;
  rep(i, N - 1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);

    ll w;
    cin >> w;
    w %= 2;
    wm.emplace(make_pair(u, v), w);
    wm.emplace(make_pair(v, u), w);
  }

  queue<int> que;
  vector<int> color(N, -1);
  que.push(0);
  color[0] = 0;
  while (!que.empty()) {
    int from = que.front();
    que.pop();
    ll nw = color[from];

    for (auto to : g[from]) {
      if (color[to] != -1) continue;
      ll w = wm.at(make_pair(from, to));
      color[to] = (nw + w) % 2;
      que.push(to);
    }
  }

  rep(i, N) { cout << color[i] << endl; }
}