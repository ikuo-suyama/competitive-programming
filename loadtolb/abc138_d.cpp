#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                      \
  ifstream in("loadtolb/abc138_d.txt"); \
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
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

vector<ll> c;
vector<vector<int>> g;

void add(int i, int x) {
  c[i] += x;
  for (auto j : g[i]) {
    add(j, x);
  }
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, Q;
  cin >> N >> Q;

  c = vector<ll>(N, 0);
  g = vector<vector<int>>(N, vector<int>(0));
  rep(i, N - 1) {
    int f, t;
    cin >> f >> t;
    f--;
    t--;
    g[f].push_back(t);
  }

  rep(i, Q) {
    int q, x;
    cin >> q >> x;
    q--;
    add(q, x);
  }

  rep(i, N) { cout << c[i] << " " << endl; }
}