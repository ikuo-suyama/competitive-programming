#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;

int N;

void make_graph(vector<PL>& c, vector<vector<ll>>& g, map<P, ll>& m) {
  repi(i, 1, N) {
    ll cost = c[i].first - c[i - 1].first;
    int j = c[i - 1].second;
    int k = c[i].second;

    g[j].push_back(k);
    g[k].push_back(j);
    PL key = make_pair(j, k);
    if (m.count(key)) {
      ll current_cost = m.at(key);
      if (current_cost > cost) {
        m.erase(key);
        m.erase(make_pair(k, j));
      }
    }
    m.emplace(make_pair(j, k), cost);
    m.emplace(make_pair(k, j), cost);
  }
}

ll solve_prim(vector<vector<ll>>& g, map<P, ll>& m) {
  // cost, next
  priority_queue<PL, vector<PL>, greater<PL>> que;
  ll cost = 0;
  ll cnt = 0;
  vector<bool> reached(N, false);

  que.push(make_pair(0, 0));
  while (cnt < N || !que.empty()) {
    PL top = que.top();
    que.pop();

    ll current = top.second;
    if (reached[current]) continue;

    cost += top.first;
    reached[current] = true;
    cnt++;

    for (auto i : g[top.second]) {
      if (reached[i]) continue;
      ll _cost = m.at(make_pair(current, i));
      que.push(make_pair(_cost, i));
    }
  }
  return cost;
}

/**
 * 最小全域木 / プリム法
 * http://www.deqnotes.net/acmicpc/prim/
 */
int main() {
  ifstream in("ac-ans-a/arc076_b.txt");
  cin.rdbuf(in.rdbuf());

  cin >> N;

  vector<PL> x(N);
  vector<PL> y(N);
  rep(i, N) {
    ll _x, _y;
    cin >> _x >> _y;
    x[i] = make_pair(_x, i);
    y[i] = make_pair(_y, i);
  }

  vector<vector<ll>> g(N, vector<ll>(0));
  map<P, ll> m;
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  make_graph(x, g, m);
  make_graph(y, g, m);

  ll cnt = solve_prim(g, m);
  cout << cnt << endl;
}