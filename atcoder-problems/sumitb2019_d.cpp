#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                  \
  ifstream in("atcoder-problems/sumitb2019_d.txt"); \
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

int N;
string S;
int M = 3;
vector<int> buf(M, 0);
int ans = 0;

void dfs(const int i, const int range_s, const int range_e) {
  if (i == M) {
    int j = 0;
    rep(i, N) {
      if (S[i] - '0' == buf[j]) {
        j++;
      }
    }
    if (j >= M) {
      // print_vec(buf);
      ans++;
    }
    return;
  }
  repi(j, range_s, range_e + 1) {
    buf[i] = j;
    dfs(i + 1, range_s, range_e);
  }
}

/**
 * #dfs #全探索 #枝刈り
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> N >> S;

  dfs(0, 0, 9);
  cout << ans << endl;
}