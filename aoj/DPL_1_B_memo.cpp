#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                \
  ifstream in("aoj/DPL_1_B.txt"); \
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

int N, W;
int dp[110][10010];

int memo(int i, int w, vector<int>& weight, vector<int>& value) {
  if (i > N) return 0;
  if (dp[i][w] != -1) return dp[i][w];

  int res;
  if (w < weight[i]) {
    // 残りが足りない。入れない処理
    res = memo(i + 1, w, weight, value);
  } else {
    res = max(memo(i + 1, w, weight, value),
              memo(i + 1, w - weight[i], weight, value) + value[i]);
  }

  return dp[i][w] = res;
}

/**
 * DP Dynamic Programming
 */
int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> N >> W;

  vector<int> weight(N);
  vector<int> value(N);
  rep(i, N) { cin >> value[i] >> weight[i]; }

  memset(dp, -1, sizeof(int) * 110 * 10010);

  cout << memo(0, W, weight, value) << endl;
}