#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc131_d.txt"); \
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

  int N;
  cin >> N;

  vector<P> c(N);
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    c[i] = make_pair(b, a);
  }

  auto comp = [&](P a, P b) -> bool {
    if (a.first == b.first)
      return a.second < b.second;
    else
      return a.first < b.first;
  };
  sort(c.begin(), c.end(), comp);

  bool ret = true;
  ll time = 0;
  rep(i, N) {
    int lim = c[i].first;
    time += c[i].second;
    if (lim < time) {
      ret = false;
      break;
    }
  }

  cout << (ret ? "Yes" : "No") << endl;
}