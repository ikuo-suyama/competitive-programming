#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc037_a.txt"); \
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

  string S;
  cin >> S;

  int N = S.size();

  vector<int> g(N);
  set<char> s = {S[0], S[1], S[2]};

  g[0] = 1;
  g[1] = S[0] == S[1] ? 1 : 2;
  g[2] = S[1] == S[2] ? 2 : g[1] + 1;

  repi(i, 3, N) {
    if (S[i] != S[i - 1]) {
      g[i] = g[i - 1] + 1;
    } else {
      g[i] = g[i - 3] + 2;
    }
  }

  cout << g[N - 1] << endl;
}